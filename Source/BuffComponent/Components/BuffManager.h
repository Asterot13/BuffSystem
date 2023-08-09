// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "BuffComponent/Buffs/BaseBuff.h"
#include "BuffManager.generated.h"

USTRUCT(BlueprintType)
struct FBuffParam : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BuffTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BuffValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeSpan;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UBaseBuff> BuffClass;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUFFCOMPONENT_API UBuffManager : public UActorComponent
{
	GENERATED_BODY()

public:	

	UBuffManager();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
	FORCEINLINE TArray<UBaseBuff*>& GetActiveBuffs() { return ActiveBuffs; }

	FORCEINLINE const float GetInitialHealth() const { return InitialHealth; }
	FORCEINLINE const float GetInitialSpeed() const { return InitialSpeed; }
	FORCEINLINE void SetCurrentHealth(float HealthValue) { CurrentHealth = HealthValue; }
	FORCEINLINE void SetCurrentSpeed(float SpeedValue) { CurrentSpeed = SpeedValue; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetCurrentHealth() { return CurrentHealth; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE float GetCurrentSpeed() { return CurrentSpeed; }

	void ActivateBuff(FName Buff);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float InitialHealth = 100.f;

	UPROPERTY(EditDefaultsOnly)
	float InitialSpeed = 300.f;

	float CurrentHealth = 100.f;
	float CurrentSpeed = 300.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UDataTable* BuffData;

	TArray<UBaseBuff*> ActiveBuffs;
};
