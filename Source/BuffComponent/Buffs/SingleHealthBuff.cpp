// Fill out your copyright notice in the Description page of Project Settings.


#include "SingleHealthBuff.h"
#include "BuffComponent/Components/BuffManager.h"

void USingleHealthBuff::ApplyBuff(UBuffManager* BuffManager)
{
	if(!BuffManager)
		return;

	float Health = BuffManager->GetCurrentHealth() - BuffValue;
	BuffManager->SetCurrentHealth(Health);
	MarkAsGarbage();
}
