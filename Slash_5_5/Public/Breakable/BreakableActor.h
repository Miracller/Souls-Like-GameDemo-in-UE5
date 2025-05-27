// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "Physics/Experimental/ChaosEventType.h"
#include "BreakableActor.generated.h"

class UGeometryCollectionComponent;

UCLASS()
class SLASH_5_5_API ABreakableActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	ABreakableActor();
	virtual void Tick(float DeltaTime) override;

	void GetHit_Implementation(const FVector& ImpactPoint);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* Capsule;
	  
private:

	FTimerHandle TimerHandle; // 定时器句柄，用于后续管理 

	UPROPERTY(EditAnywhere, Category = "Breakable Properties")
	TArray<TSubclassOf<class ATreasure>> TreasureClass;

	void TriggerDelay(float DelayTime);
	void OnDelayCompleted();

	// 防止GetHit函数被多次调用造成无限循环
	bool bBroken = false;
	bool bBroken2 = false;

	// Call OnChaosBreakEvent from C++
	UFUNCTION()
	void OnChaosCallback(const FChaosBreakEvent& BreakEvent);
};
