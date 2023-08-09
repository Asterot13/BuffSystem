// Fill out your copyright notice in the Description page of Project Settings.


#include "BuffManager.h"


UBuffManager::UBuffManager()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UBuffManager::BeginPlay()
{
	Super::BeginPlay();

}

void UBuffManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UBuffManager::ActivateBuff(FName Buff)
{
	if (!BuffData)
		return;

	const auto BuffParams = BuffData->FindRow<FBuffParam>(Buff, "");
	if(BuffParams)
	{
		UBaseBuff* NewBuff = NewObject<UBaseBuff>(this, BuffParams->BuffClass);
		NewBuff->BuffTime = BuffParams->BuffTime;
		NewBuff->BuffValue = BuffParams->BuffValue;
		NewBuff->LifeSpan = BuffParams->LifeSpan;

		NewBuff->ApplyBuff(this);
	}
}
