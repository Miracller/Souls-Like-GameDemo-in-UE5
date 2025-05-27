// Fill out your copyright notice in the Description page of Project Settings.


#include "Breakable/BreakableActor.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Items/Treasure.h"
#include "Components/CapsuleComponent.h"


ABreakableActor::ABreakableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	GeometryCollection = CreateDefaultSubobject<UGeometryCollectionComponent>(TEXT("GeometryCollection"));
	SetRootComponent(GeometryCollection);

	GeometryCollection->SetGenerateOverlapEvents(true);
	GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(GetRootComponent());
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);

}

void ABreakableActor::BeginPlay()
{
	Super::BeginPlay();
	
	// AddDynamic
	GeometryCollection->OnChaosBreakEvent.AddDynamic(this, &ABreakableActor::OnChaosCallback);
}

void ABreakableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABreakableActor::TriggerDelay(float DelayTime)
{
	// 设置定时器，延迟 DelayTime 秒后执行 OnDelayCompleted 函数
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&ABreakableActor::OnDelayCompleted,
		DelayTime,
		false // 是否循环执行（此处为单次）
	);
}

// 生成Treasure物件
void ABreakableActor::OnDelayCompleted()
{
	UWorld* World = GetWorld();
	// GitHit & Spawn treasure
	if (World && TreasureClass.Num() > 0)
	{
		FVector Location = GetActorLocation();
		Location.Z += 75.f;

		const int32 Selection = FMath::RandRange(0, TreasureClass.Num() - 1);
		World->SpawnActor<ATreasure>(TreasureClass[Selection], Location, GetActorRotation());
	}
}

// Call OnChaosBreakEvent from C++
void ABreakableActor::OnChaosCallback(const FChaosBreakEvent& BreakEvent)
{
	// todo
	if (bBroken2) return;
	bBroken2 = true;
	UE_LOG(LogTemp, Warning, TEXT("You are using Chaos Breaking Callback Func from C++!!!!"));
}

void ABreakableActor::GetHit_Implementation(const FVector& ImpactPoint)
{	
	if (bBroken) return;
	bBroken = true;
	this->TriggerDelay(.5f);
	//bBroken = false;
}