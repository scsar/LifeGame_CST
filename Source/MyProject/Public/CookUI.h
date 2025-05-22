// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CookUI.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UCookUI : public UUserWidget
{
	GENERATED_BODY()


protected:
    virtual void NativeOnInitialized() override;

    UFUNCTION()
    void OnCloseClicked();      // �ݱ� ��ư ���� �� ����

public:
    UPROPERTY(meta = (BindWidget))
    class UButton* CloseButton;                 // �ݱ� ��ư

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* QuestionText;      

    void UpdateQuestionText(TArray<FName> Recipe);

    void EndGame(bool bIsWin);      // bool��(���� �Ǵ� ����)�� ���� ���� ��� ó��



    void HideSelf();

    bool isPlaying;
	
};
