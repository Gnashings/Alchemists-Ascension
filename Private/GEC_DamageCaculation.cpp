#include "GEC_DamageCaculation.h"
#include "BaseAttributeSet.h"
#include "AbilitySystemComponent.h"


//Helper Struct for fetching the attributes if need for calculation
struct FDamageStatistics
{
	//Capturdef declarations for attributes.
	DECLARE_ATTRIBUTE_CAPTUREDEF(Defence);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Attack);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageResist);

	//Default Constructor
	FDamageStatistics()
	{
		//Capturedef definitions for attributes
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, Attack, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, Defence, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, Health,	Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, DamageResist, Target, false);
	}
};

static const FDamageStatistics& DamageStatistics()
{
	static FDamageStatistics DmgStatistic;
	return DmgStatistic;
}

UGEC_DamageCaculation::UGEC_DamageCaculation()
{
	RelevantAttributesToCapture.Add(DamageStatistics().AttackDef);
	RelevantAttributesToCapture.Add(DamageStatistics().DefenceDef);
	RelevantAttributesToCapture.Add(DamageStatistics().HealthDef);
	RelevantAttributesToCapture.Add(DamageStatistics().DamageResistDef);
}

void UGEC_DamageCaculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecuteParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	
	//Obrain references to the target and source Ability System Component. Each copy of a Game Attribute.
	UAbilitySystemComponent* TargetABSC = ExecuteParams.GetTargetAbilitySystemComponent();
	AActor* TargetActor = TargetABSC ? TargetABSC->GetAvatarActor() : nullptr;

	UAbilitySystemComponent* SourceABSC = ExecuteParams.GetSourceAbilitySystemComponent();
	AActor* SourceActor = SourceABSC ? SourceABSC->GetAvatarActor() : nullptr;

	//Get the owning GE Spec so that you can use it as a variable and tag.
	const FGameplayEffectSpec& Spec = ExecuteParams.GetOwningSpec();
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	//Aggregator Evaluate Parameters used during the attribute capture.
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	//Capturing Damage
	float BaseDamage = FMath::Max<float>(Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Data.Damage")), false, -1.0), 0.0f);

	//Capturing Defence
	float Defence = 0.f;
	ExecuteParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatistics().DefenceDef, EvaluationParameters, Defence);

	//Capturing Damage Resistance
	float DamageResistance = 0.f;
	ExecuteParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatistics().DamageResistDef, EvaluationParameters, DamageResistance);
	//Capturing Attack
	float Attack = 0.f;
	ExecuteParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatistics().AttackDef, EvaluationParameters, Attack);

	//Damage Done
	float DamageDone = (BaseDamage * Attack) - (Defence * DamageResistance);

	if (DamageDone < 0.f)
	{
		DamageDone = 0.0f;
	}

	//Final execution output.
	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatistics().HealthProperty, EGameplayModOp::Additive, -DamageDone));
}


