// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "ShopUI.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UShopUI : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void OnCloseClicked();


	UPROPERTY(meta = (BindWidget))
	class UButton* CloseButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shop", meta = (ExposeOnSpawn))
	UDataTable* ItemDataTable;  // BP���� ���� DT ����

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shop", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UShopItemSlot> ShopItemSlotClass;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* SlotContainer;

	UPROPERTY(meta = (BindWidget))
	class UWrapBox* SlotWrapBox;

public:
	// ���Կ��� RowName�� Ŭ���Ǿ��� �� ȣ���
	UFUNCTION()
	void OnBuyRequested(FName RowName);

	// ���� ������ �������Ʈ���� ó�� (�κ��丮 ����)
	UFUNCTION(BlueprintImplementableEvent, Category = "Shop")
	void HandleBuyItem_BP(FName RowName);


};
