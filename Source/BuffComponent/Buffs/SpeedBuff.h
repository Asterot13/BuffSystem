// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuff.h"
#include "SpeedBuff.generated.h"

/**
 * 
 */
UCLASS()
class BUFFCOMPONENT_API USpeedBuff : public UBaseBuff
{
	GENERATED_BODY()

protected:

	virtual void ApplyBuff(UBuffManager* BuffManager);

	FTimerHandle DestroyBuffTimer;

	ACharacter* Char;
	UBuffManager* Manager;
};
