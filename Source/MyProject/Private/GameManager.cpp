// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Components/AudioComponent.h"
#include "StatusWidget.h"
// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������Ʈ ����
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->SetupAttachment(RootComponent);
	AudioComponent->bAutoActivate = false; // �ڵ� ��� ����
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	if (SoundToPlay1)
	{
		AudioComponent->SetSound(SoundToPlay1);
		AudioComponent->Play();
	}
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AGameManager::lobby() //�κ� ����
{
	//�ó׸�ƽ ���� ���


}

void AGameManager::Start() //�ʵ��л� ����
{
	if (SoundToPlay1)
	{
		AudioComponent->SetSound(SoundToPlay1);
		AudioComponent->Play();
		StatusWidget->changeUI();
	}
}

void AGameManager::middle() //���� ����
{
	if (SoundToPlay2)
	{
		AudioComponent->SetSound(SoundToPlay2);
		AudioComponent->Play();
		StatusWidget->changeUI();
	}
}

void AGameManager::end() //�ڱ��� ����
{
	if (SoundToPlay3)
	{
		AudioComponent->SetSound(SoundToPlay3);
		AudioComponent->Play();
		StatusWidget->changeUI();
	}
}

