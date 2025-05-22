// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MSImageQuizGameUI.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMSImageQuizGameUI : public UUserWidget
{
	GENERATED_BODY()
protected:
    virtual void NativeOnInitialized() override;

    UFUNCTION()
    void OnCloseClicked();      // �ݱ� ��ư ���� �� ����

    UFUNCTION()
    void OnAnswerSubmitted(const FText& Text, ETextCommit::Type CommitMethod);      // �Է� �ؽ�Ʈ �ڽ��� ���� ���� ��

public:
    UPROPERTY(meta = (BindWidget))
    class UButton* CloseButton;                 // �ݱ� ��ư

    UPROPERTY(meta = (BindWidget))
    class UImage* QuestionImage;                // ���� ���� �̹���

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* QuestionNumberText;       // ���� ��ȣ �ؽ�Ʈ

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ResultText;               // ���� ��� �ؽ�Ʈ

    UPROPERTY(meta = (BindWidget))
    class UEditableTextBox* AnswerInput;        // �Է� �ؽ�Ʈ �ڽ�

    FString CorrectAnswer;
    void UpdateQuestionNumber(int32 QuestionNumber);                    // ���� ��ȣ ����
    void SetQuestion(UTexture2D* NewQuestionImage, FString Answer);     // ������ ������ ������ �Ҵ�
    void SetRandomQuestion();                                           // ���� ���� ����

    void SetAnswerInputFocus();                                         // �� �Է� �ʵ� Ȱ��ȭ(��Ŀ��)

private:
    int32 CorrectCount;                     // ���� Ƚ��
    int32 CurrentQuestionNumber;            // ���� ���� ��ȣ
    TArray<FString> ImagePaths; // �̹��� ���� ��� �迭
    TArray<FString> Answers; // ���� �迭
    void EndGame(bool bIsWin);              // bool��(���� �Ǵ� ����)�� ���� ���� ��� ó��

};
