﻿#include "JobCenter.h"
#include "Components/BoxComponent.h"
#include "MyProject/MyProjectCharacter.h"
#include "GameController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "JobCenterUI.h"

AJobCenter::AJobCenter()
{
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetBoxExtent(FVector(80.0f, 80.0f, 80.0f));
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	//CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AJobCenter::OnBeginOverlap);
}

void AJobCenter::BeginPlay()
{
	Super::BeginPlay();
}

void AJobCenter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//void AJobCenter::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
//	int32 OtherBoxIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (!HasAuthority()) return;  // ������ ó��
//	//UE_LOG(LogTemp, Warning, TEXT("Overlap with Job Center1")); // ������ �α� ���
//
//
//	if (AMyProjectCharacter* Character = Cast<AMyProjectCharacter>(OtherActor))
//	{
//		AController* Controller = Character->GetController();
//		AGameController* PlayerController = Cast<AGameController>(Controller);
//
//
//		if (PlayerController && !PlayerController->IsPlayingMiniGame())
//		{
//			//UE_LOG(LogTemp, Warning, TEXT("Overlap with Job Center3"));
//			PlayerController->SetIsPlayingMiniGame(true); 
//			PlayerController->Client_ShowGameUI(EGameUIType::JobCenter); // Ŭ�󿡼� UI ���
//		}
//	}
//
//
//}
