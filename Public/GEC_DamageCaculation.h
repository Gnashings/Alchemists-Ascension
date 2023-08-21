// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEC_DamageCaculation.generated.h"

/**
 * 
 */
UCLASS()
class ALCHEMISTASCENSION_API UGEC_DamageCaculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
public:

	UGEC_DamageCaculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecuteParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};