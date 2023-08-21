// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "BaseCharacter.generated.h"

class UBaseAttributeSet;

UCLASS()
class ALCHEMISTASCENSION_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
	UAbilitySystemComponent* AbilitySystemComp;

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
	void InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
	const class UBaseAttributeSet* BaseAttributeSetComp;

	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetHealthValues(float& Health, float& MaxHealth);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetTechPointsValues(float& TechPoints, float& MaxTechPoints);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetSuperValues(float& SuperGauge, float& MaxSuper);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetSpeedValues(float& Speed, float& MaxSpeed);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetAttackValues(float& Attack, float& MaxAttack);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetDefenceValues(float& Defence, float& MaxDefence);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetDamageResistValues(float& DamageResist, float& MaxDamageResist);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetFireResistValues(float& FireResist, float& MaxFireResist);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetAirResistValues(float& AirResist, float& MaxAirResist);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetWaterResistValues(float& WaterResist, float& MaxWaterResist);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetEarthResistValues(float& EarthResist, float& MaxEarthResist);
	UFUNCTION(BlueprintPure, Category = "BaseCharacter")
	void GetPoisonResistValues(float& PoisonResist, float& MaxPoisonResist);

	void OnHealthChangedNative(const FOnAttributeChangeData& Data);
	void OnTechPointsChangedNative(const FOnAttributeChangeData& Data);
	void OnSuperChangedNative(const FOnAttributeChangeData& Data);
	void OnSpeedChangedNative(const FOnAttributeChangeData& Data);
	void OnAttackChangedNative(const FOnAttributeChangeData& Data);
	void OnDefenceChangedNative(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnHealthChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnTechPointsChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnSuperChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnSpeedChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnAttackChanged(float OldValue, float NewValue);
	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
	void OnDefenceChanged(float OldValue, float NewValue);
};
