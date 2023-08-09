// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuff.h"
#include "SingleHealthBuff.generated.h"


UCLASS()
class BUFFCOMPONENT_API USingleHealthBuff : public UBaseBuff
{
	GENERATED_BODY()
	
protected:

	virtual void ApplyBuff(UBuffManager* BuffManager);
};
