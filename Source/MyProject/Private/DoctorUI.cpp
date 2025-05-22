// Fill out your copyright notice in the Description page of Project Settings.


#include "DoctorUI.h"
#include "GameController.h"
#include "MyProject/MyProjectCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UDoctorUI::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (CloseButton)
    {
        CloseButton->OnClicked.AddDynamic(this, &UDoctorUI::OnCloseClicked);
    }
}

void UDoctorUI::OnCloseClicked()
{
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


void UDoctorUI::UpdateQuestionText(int32 CollectedPatientCount)
{
    if (QuestionText)
    {
        QuestionText->SetText(FText::FromString(FString::Printf(TEXT("Care Patient : %d Left"), CollectedPatientCount)));
    }
}

void UDoctorUI::EndGame(bool bIsWin)
{
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



void UDoctorUI::HideSelf()
{
    AGameController* PlayerController =
        Cast<AGameController>(UGameplayStatics::GetPlayerController(this, 0));

    if (PlayerController)
    {
        PlayerController->Server_SetIsPlayingMiniGame(false);

        PlayerController->HideGameUI(EGameUIType::JC_Doctor);
    }
}