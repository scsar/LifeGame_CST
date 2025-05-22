// Fill out your copyright notice in the Description page of Project Settings.


#include "Restaurant.h"
#include "MyProject/MyProjectCharacter.h"
#include "Components/BoxComponent.h"
#include "GameController.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ARestaurant::ARestaurant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetBoxExtent(FVector(80.0f, 80.0f, 80.0f));
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	//CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ARestaurant::OnBeginOverlap);

}

// Called when the game starts or when spawned
void ARestaurant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARestaurant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ARestaurant::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
//	int32 OtherBoxIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (AMyProjectCharacter* Character = Cast<AMyProjectCharacter>(OtherActor))
//	{
//		AController* Controller = Character->GetController();
//		AGameController* PlayerController = Cast<AGameController>(Controller);
//
//
//		if (PlayerController && PlayerController->IsPlayingMiniGame())
//		{
//			// �κ��丮���� ������� ���ϸ鼭, ����/����ó��
//			CheckCookMissionComplete(PlayerController);
//				//TODO
//				// ���н�, �׳� �ٷ� ���н�ų����
//				// �ƴϸ� �����ϴٰ� �߸鼭 �׳� �ѱ沫�� ���ؾ���
//
//		}
//	}
//}
