// Fill out your copyright notice in the Description page of Project Settings.


#include "ESImageQuizGameBox.h"
#include "Components/BoxComponent.h"
#include "MyProject/MyProjectCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameController.h"
// Sets default values
AESImageQuizGameBox::AESImageQuizGameBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetBoxExtent(FVector(80.0f, 80.0f, 80.0f));
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	//CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AESImageQuizGameBox::OnBeginOverlap);
}

// Called when the game starts or when spawned
void AESImageQuizGameBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AESImageQuizGameBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AESImageQuizGameBox::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
//    int32 OtherBoxIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (!HasAuthority()) return;
//	//UE_LOG(LogTemp, Warning, TEXT("Overlap with Job Center1")); 
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
//			PlayerController->Client_ShowGameUI(EGameUIType::ES_ImageQuiz);
//		}
//	}
//}