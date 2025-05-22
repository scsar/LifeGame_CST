// Fill out your copyright notice in the Description page of Project Settings.


#include "RedZoneManager.h"

// Sets default values
ARedZoneManager::ARedZoneManager()

{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ARedZoneManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("RedZoneManager BeginPlay"));
	StartRedZone();

}

// Called every frame
void ARedZoneManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARedZoneManager::StartRedZone()
{
	// ������ ��ȣ�� ���� (1 ~ 16 ��, ���� �� ���� �͸�)
	TArray<int32> AvailableIndices;
	for (int i = 1; i <= 16; ++i)
	{
		if (!UsedRedZoneIndices.Contains(i))
		{
			AvailableIndices.Add(i);
		}
	}

	// ��� RedZone�� �̹� ���õǾ����� �� �̻� �������� ����
	if (AvailableIndices.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("��� RedZone�� �̹� ���Ǿ����ϴ�."));
		return;
	}

	// ��� ������ �ε��� �� �ϳ� ������ ����
	int32 RandomIndex = FMath::RandRange(0, AvailableIndices.Num() - 1);
	int32 RedZoneCount = AvailableIndices[RandomIndex];

	// ���õ� �ε��� ����
	UsedRedZoneIndices.Add(RedZoneCount);

	UE_LOG(LogTemp, Warning, TEXT("RedZoneCount: %d"), RedZoneCount);

	// Ÿ�̸� ����
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("closeRedZone"), RedZoneCount);

	GetWorld()->GetTimerManager().SetTimer(
		RedZoneTimerHandle,
		TimerDel,
		time,
		false
	);
}


void ARedZoneManager::closeRedZone(int RedZoneCount)
{
	if (RedZoneActors.IsValidIndex(RedZoneCount) && RedZoneActors[RedZoneCount])
	{
		// RedZoneCube Ÿ������ ĳ����
		ARedZoneCube* Cube = Cast<ARedZoneCube>(RedZoneActors[RedZoneCount]);
		if (Cube)
		{
			Cube->ForceBlock(safeTime); // Block ���·� ��ȯ
			UE_LOG(LogTemp, Warning, TEXT("RedZone %d is now blocking"), RedZoneCount);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("RedZoneActor %d is not of type ARedZoneCube!"), RedZoneCount);
		}
	}
	StartRedZone();
}

