
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopItemSlot.generated.h"

class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBuyRequested, FName, RowName);


UCLASS()
class MYPROJECT_API UShopItemSlot : public UUserWidget
{
	GENERATED_BODY()


public:
	/** �ܺο��� ���޹޴� RowName (������ Ű) */
	UPROPERTY(BlueprintReadWrite, Category = "Shop")
	FName RowName;

	/** ��ư Ŭ�� �� ���� ��û �̺�Ʈ �߻� */
	UPROPERTY(BlueprintAssignable, Category = "Shop")
	FOnBuyRequested OnBuyClicked;

protected:
	virtual void NativeOnInitialized() override;

	/** ��ư Ŭ�� ó�� */
	UFUNCTION()
	void HandleBuyClicked();

public:
	/** ���Կ� RowName�� ������ �� ȣ���, ������ ä��� */
	UFUNCTION(BlueprintImplementableEvent, Category = "Shop")
	void InitializeFromRowName();

	/** ��ư ������, BP���� BindWidget */
	UPROPERTY(meta = (BindWidget))
	UButton* BuyButton;
};
