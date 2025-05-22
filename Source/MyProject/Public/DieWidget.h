// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/SpectatorPawn.h" // ���⵵ �ʿ�!

#include "DieWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UDieWidget : public UUserWidget
{
	GENERATED_BODY()
	

public :
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* WatchingButton;                 // �ݱ� ��ư

	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButton;                 // �ݱ� ��ư

	UFUNCTION()
	void OnWatchingClicked();      // �ݱ� ��ư ���� �� ����
	UFUNCTION()
	void OnExitClicked();      // �ݱ� ��ư ���� �� ����



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spectator")
	TSubclassOf<ASpectatorPawn> SpectatorPawnClass;

};
