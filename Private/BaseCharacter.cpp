#include "BaseCharacter.h"
#include "BaseAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComp)
	{
		BaseAttributeSetComp = AbilitySystemComp->GetSet<UBaseAttributeSet>();

		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetHealthAttribute()).AddUObject(this, &ABaseCharacter::OnHealthChangedNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetTechPointsAttribute()).AddUObject(this, &ABaseCharacter::OnTechPointsChangedNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetSuperGaugeAttribute()).AddUObject(this, &ABaseCharacter::OnSuperChangedNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetSpeedAttribute()).AddUObject(this, &ABaseCharacter::OnSpeedChangedNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetAttackAttribute()).AddUObject(this, &ABaseCharacter::OnAttackChangedNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetDefenceAttribute()).AddUObject(this, &ABaseCharacter::OnDefenceChangedNative);
		
	}

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

} 

void ABaseCharacter::InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel)
{
	if (AbilitySystemComp)
	{
		if (HasAuthority() && AbilityToGet)
		{
			AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(AbilityToGet, AbilityLevel, 0));
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void ABaseCharacter::GetHealthValues(float& Health, float& MaxHealth)
{
	if (BaseAttributeSetComp)
	{
		Health = BaseAttributeSetComp->GetHealth();
		MaxHealth = BaseAttributeSetComp->GetMaxHealth();
	}
}

void ABaseCharacter::GetTechPointsValues(float& TechPoints, float& MaxTechPoints)
{
	if (BaseAttributeSetComp)
	{
		TechPoints = BaseAttributeSetComp->GetTechPoints();
		MaxTechPoints = BaseAttributeSetComp->GetMaxTechPoints();
	}
}

void ABaseCharacter::GetSuperValues(float& Super, float& MaxSuper)
{
	if (BaseAttributeSetComp)
	{
		Super = BaseAttributeSetComp->GetSuperGauge();
		MaxSuper = BaseAttributeSetComp->GetMaxSuperGauge();
	}
}

void ABaseCharacter::GetSpeedValues(float& Speed, float& MaxSpeed)
{
	if (BaseAttributeSetComp)
	{
		Speed = BaseAttributeSetComp->GetSpeed();
		MaxSpeed = BaseAttributeSetComp->GetMaxSpeed();
	}
}

void ABaseCharacter::GetAttackValues(float& Attack, float& MaxAttack)
{
	if (BaseAttributeSetComp)
	{
		Attack = BaseAttributeSetComp->GetAttack();
		MaxAttack = BaseAttributeSetComp->GetMaxAttack();
	}
}

void ABaseCharacter::GetDefenceValues(float& Defence, float& MaxDefence)
{
	if (BaseAttributeSetComp)
	{
		Defence = BaseAttributeSetComp->GetDefence();
		MaxDefence = BaseAttributeSetComp->GetMaxDefence();
	}
}

void ABaseCharacter::GetDamageResistValues(float& DamageResist, float& MaxDamageResist)
{
	if (BaseAttributeSetComp)
	{
		DamageResist = BaseAttributeSetComp->GetDamageResist();
		MaxDamageResist = BaseAttributeSetComp->GetMaxDamageResist();
	}
}

void ABaseCharacter::GetFireResistValues(float& FireResist, float& MaxFireResist)
{
	if (BaseAttributeSetComp)
	{
		FireResist = BaseAttributeSetComp->GetDamageResist();
		MaxFireResist = BaseAttributeSetComp->GetMaxDamageResist();
	}
}

void ABaseCharacter::GetAirResistValues(float& AirResist, float& MaxAirResist)
{
	if (BaseAttributeSetComp)
	{
		AirResist = BaseAttributeSetComp->GetAirResist();
		MaxAirResist = BaseAttributeSetComp->GetMaxAirResist();
	}
}

void ABaseCharacter::GetWaterResistValues(float& WaterResist, float& MaxWaterResist)
{
	if (BaseAttributeSetComp)
	{
		WaterResist = BaseAttributeSetComp->GetWaterResist();
		MaxWaterResist = BaseAttributeSetComp->GetMaxWaterResist();
	}
}

void ABaseCharacter::GetEarthResistValues(float& EarthResist, float& MaxEarthResist)
{
	if (BaseAttributeSetComp)
	{
		EarthResist = BaseAttributeSetComp->GetEarthResist();
		MaxEarthResist = BaseAttributeSetComp->GetMaxEarthResist();
	}
}

void ABaseCharacter::GetPoisonResistValues(float& PoisonResist, float& MaxPoisonResist)
{
	if (BaseAttributeSetComp)
	{
		PoisonResist = BaseAttributeSetComp->GetPoisonResist();
		MaxPoisonResist = BaseAttributeSetComp->GetMaxPoisonResist();
	}
}


void ABaseCharacter::OnHealthChangedNative(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnTechPointsChangedNative(const FOnAttributeChangeData& Data)
{
	OnTechPointsChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnSuperChangedNative(const FOnAttributeChangeData& Data)
{
	OnSuperChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnSpeedChangedNative(const FOnAttributeChangeData& Data)
{
	OnSpeedChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnAttackChangedNative(const FOnAttributeChangeData& Data)
{
	OnAttackChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnDefenceChangedNative(const FOnAttributeChangeData& Data)
{
	OnDefenceChanged(Data.OldValue, Data.NewValue);
}
