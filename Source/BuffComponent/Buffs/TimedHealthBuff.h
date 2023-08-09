// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuff.h"
#include "TimedHealthBuff.generated.h"


UCLASS()
class BUFFCOMPONENT_API UTimedHealthBuff : public UBaseBuff
{
	GENERATED_BODY()

protected:

	virtual void ApplyBuff(UBuffManager* BuffManager);

	virtual void BeginDestroy() override;

	FTimerHandle DestroyBuffTimer;
	FTimerHandle BuffTimer;

	FTimerDelegate BuffTimerDelegate;
	FTimerDelegate DestroyTimerDelegate;

	UBuffManager* Manager;

	float TotalBuffTime = 0.f;
};
