// Fill out your copyright notice in the Description page of Project Settings.


#include "CookUI.h"
#include "GameController.h"
#include "MyProject/MyProjectCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


void UCookUI::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (CloseButton)
    {
        CloseButton->OnClicked.AddDynamic(this, &UCookUI::OnCloseClicked);
    }

    isPlaying = false;
}

void UCookUI::OnCloseClicked()
{
    isPlaying = false;
    if (QuestionText)
    {
        QuestionText->SetText(FText::FromString(TEXT("�̼��� ��ҵǾ����ϴ�.")));
    }

    // 2�� �� �ڵ����� UI ����
    FTimerHandle CancelTimerHandle;
    GetWorld()->GetTimerManager().SetTimer(CancelTimerHandle, FTimerDelegate::CreateLambda([this]()
        {
            HideSelf();
        }), 2.0f, false);
}


void UCookUI::UpdateQuestionText(TArray<FName> RecipeIngredients)
{
    if (QuestionText)
    {
        isPlaying = true;
        FString Result = "Find Ingredients ";

        for (int32 i = 0; i < RecipeIngredients.Num(); ++i)
        {
            Result += RecipeIngredients[i].ToString();

            // ��ǥ ������ �߰� (���������� ����)
            if (i < RecipeIngredients.Num() - 1)
            {
                Result += TEXT(", ");
            }
        }

        QuestionText->SetText(FText::FromString(Result));

        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
            {
                HideSelf();
            }), 3.0f, false);
    }
}

void UCookUI::EndGame(bool bIsWin)
{
    isPlaying = false;
    if (bIsWin)
    {
        QuestionText->SetText(FText::FromString(TEXT("����!!!")));
    }
    else
    {
        QuestionText->SetText(FText::FromString(TEXT("����...")));
    }

    FTimerHandle EndTimerHandle;
    GetWorld()->GetTimerManager().SetTimer(EndTimerHandle, FTimerDelegate::CreateLambda([this]() {
        HideSelf();
        }), 2.0f, false);
}



void UCookUI::HideSelf()
{
    AGameController* PlayerController =
        Cast<AGameController>(UGameplayStatics::GetPlayerController(this, 0));

    if (PlayerController)
    {
        if (!isPlaying)
        {
            PlayerController->SetIsPlayingMiniGame(false);
        }
        PlayerController->HideGameUI(EGameUIType::JC_Cook);
    }
}
