// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseBuff.generated.h"

class UBuffManager;

UCLASS(Blueprintable)
class BUFFCOMPONENT_API UBaseBuff : public UObject
{
	GENERATED_BODY()

public:

	virtual void ApplyBuff(UBuffManager* BuffManager) {};
	virtual void DenyBuff(UBuffManager* BuffManager) {};

	UPROPERTY(EditDefaultsOnly)
	float BuffTime = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float BuffValue = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 0.5f;
};
