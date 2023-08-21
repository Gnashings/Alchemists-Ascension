// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class ALCHEMISTASCENSION_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBaseAttributeSet();
	//Attributes for Health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData Health;
		ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxHealth;
		ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth);

	//Attributes for Tech Points
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
	FGameplayAttributeData TechPoints;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, TechPoints);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
	FGameplayAttributeData MaxTechPoints;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxTechPoints);

	//Attributes for Super Gauge
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
	FGameplayAttributeData SuperGauge;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, SuperGauge);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
	FGameplayAttributeData MaxSuperGauge;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxSuperGauge);	

	//Attributes for Speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Speed);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
	FGameplayAttributeData MaxSpeed;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxSpeed);

	//Attributes for Attack
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData Attack;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Attack);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxAttack;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxAttack);

	//Attributes for Defence
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData Defence;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Defence);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxDefence;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxDefence);


	//Attributes for Resistances
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData DamageResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, DamageResist);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxDamageResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxDamageResist);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData FireResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, FireResist);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxFireResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxFireResist);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData EarthResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, EarthResist);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxEarthResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxEarthResist);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData WaterResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, WaterResist);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxWaterResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxWaterResist);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData AirResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, AirResist);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxAirResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxAirResist);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData PoisonResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, PoisonResist);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributes")
		FGameplayAttributeData MaxPoisonResist;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxPoisonResist);



	void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
