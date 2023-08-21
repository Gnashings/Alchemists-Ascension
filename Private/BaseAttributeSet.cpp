// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributeSet.h"
#include "GameplayEffectExtension.h"

UBaseAttributeSet::UBaseAttributeSet()
{
	
}

void UBaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth((FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth())));
	}
	if(Data.EvaluatedData.Attribute == GetTechPointsAttribute())
	{
		SetTechPoints((FMath::Clamp(GetTechPoints(), 0.0f, GetMaxTechPoints())));
	}
	if(Data.EvaluatedData.Attribute == GetSuperGaugeAttribute())
	{
		SetSuperGauge((FMath::Clamp(GetSuperGauge(), 0.0f, GetMaxSuperGauge())));
	}
	if(Data.EvaluatedData.Attribute == GetSpeedAttribute())
	{
		SetSpeed((FMath::Clamp(GetSpeed(), 0.0f, GetMaxSpeed())));
	}
	if (Data.EvaluatedData.Attribute == GetAttackAttribute())
	{
		SetAttack((FMath::Clamp(GetAttack(), 0.0f, GetMaxAttack())));
	}
	if (Data.EvaluatedData.Attribute == GetDefenceAttribute())
	{
		SetDefence((FMath::Clamp(GetDefence(), 0.0f, GetMaxDefence())));
	}
	if (Data.EvaluatedData.Attribute == GetDamageResistAttribute())
	{
		SetDamageResist((FMath::Clamp(GetDamageResist(), 0.0f, GetMaxDamageResist())));
	}
	if (Data.EvaluatedData.Attribute == GetFireResistAttribute())
	{
		SetFireResist((FMath::Clamp(GetFireResist(), 0.0f, GetMaxFireResist())));
	}
	if (Data.EvaluatedData.Attribute == GetWaterResistAttribute())
	{
		SetWaterResist((FMath::Clamp(GetWaterResist(), 0.0f, GetMaxWaterResist())));
	}
	if (Data.EvaluatedData.Attribute == GetEarthResistAttribute())
	{
		SetEarthResist((FMath::Clamp(GetEarthResist(), 0.0f, GetMaxEarthResist())));
	}
	if (Data.EvaluatedData.Attribute == GetAirResistAttribute())
	{
		SetAirResist((FMath::Clamp(GetAirResist(), 0.0f, GetMaxAirResist())));
	}
	if (Data.EvaluatedData.Attribute == GetPoisonResistAttribute())
	{
		SetPoisonResist((FMath::Clamp(GetPoisonResist(), 0.0f, GetMaxPoisonResist())));
	}
}
