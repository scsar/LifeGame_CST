// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enemy.h"
#include "BoxerMissionUI.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UBoxerMissionUI : public UUserWidget
{
	GENERATED_BODY()
public:
	static UBoxerMissionUI* CurrentInstance; // ��𼭵� ���� �����ϰ�

	virtual void NativeOnInitialized() override;


	UPROPERTY(meta = (BindWidget))
	class UTextBlock* QuestionText;             // �̼� ���� �ؽ�Ʈ

	void UpdateQuestionText();     // �̼� ���� 

	void EndGame();

	void HideSelf();// �̼� ���� ���ֱ�

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	TSubclassOf<AEnemy> EnemyFactory;

	void CreateEnemy();
};
