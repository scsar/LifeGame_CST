// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RedZoneCube.generated.h"

UCLASS()
class MYPROJECT_API ARedZoneCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARedZoneCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void UpdateOpacityFromManager(float Alpha);

	void ForceBlock(float Duration); // �浹 ��ȯ ���� ȣ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* Mesh;

	UFUNCTION()
	void OnPlayerOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPlayerOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> WarningWidgetClass; // ������ ���� Ŭ����

private:
	UPROPERTY()
	UUserWidget* SpawnedWidget = nullptr; // ������ ���� ����

	bool bWidgetShown = false; // �ߺ� ���� ����

	UMaterialInstanceDynamic* DynamicMaterial;

	float FadeDuration = 0.0f;        // ��ü ����� �ð�
	float ElapsedFadeTime = 0.0f;     // ���� �ð�
	bool redzoneStart = false; // RedZone ���� ����
	bool bHasBlocked = false;
	bool isBlock = false;

	FTimerHandle FadeTimerHandle;

	void UpdateFade(); // Opacity ���� �Լ�

};
