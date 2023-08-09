// Fill out your copyright notice in the Description page of Project Settings.


#include "TimedHealthBuff.h"
#include "BuffComponent/Components/BuffManager.h"

void UTimedHealthBuff::ApplyBuff(UBuffManager* BuffManager)
{
	if(!BuffManager && !GetWorld())
		return;

	Manager = BuffManager;
	BuffManager->GetActiveBuffs().Add(this);
	BuffTimerDelegate.BindLambda([&]
		{
			float Health = Manager->GetCurrentHealth() - BuffValue;
			Manager->SetCurrentHealth(Health);

			TotalBuffTime += GetWorld()->GetTimerManager().GetTimerElapsed(BuffTimer);
			if(TotalBuffTime >= LifeSpan)
			{
				GetWorld()->GetTimerManager().ClearTimer(BuffTimer);
			}
		});
	GetWorld()->GetTimerManager().SetTimer(BuffTimer, BuffTimerDelegate, BuffTime, true);

	DestroyTimerDelegate.BindLambda([&]
	{	
		this->ConditionalBeginDestroy();
	});
	GetWorld()->GetTimerManager().SetTimer(DestroyBuffTimer, DestroyTimerDelegate, LifeSpan, false);
}

void UTimedHealthBuff::BeginDestroy()
{
	BuffTimer.Invalidate();
	Manager->GetActiveBuffs().Remove(this);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

	Super::BeginDestroy();
}
