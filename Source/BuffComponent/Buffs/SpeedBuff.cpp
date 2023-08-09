// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedBuff.h"
#include "BuffComponent/Components/BuffManager.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void USpeedBuff::ApplyBuff(UBuffManager* BuffManager)
{
	if (!BuffManager && !GetWorld())
		return;

	Manager = BuffManager;
	BuffManager->GetActiveBuffs().Add(this);
	Char = Cast<ACharacter>(BuffManager->GetOwner());
	if(!Char && !Char->GetCharacterMovement())
		return;

	Char->GetCharacterMovement()->MaxWalkSpeed = BuffValue;
	FTimerDelegate DestroyTimerDelegate;
	DestroyTimerDelegate.BindLambda([&]
		{
			Char->GetCharacterMovement()->MaxWalkSpeed = Manager->GetInitialSpeed();
			this->ConditionalBeginDestroy();
		});
	GetWorld()->GetTimerManager().SetTimer(DestroyBuffTimer, DestroyTimerDelegate, LifeSpan, false);
}
