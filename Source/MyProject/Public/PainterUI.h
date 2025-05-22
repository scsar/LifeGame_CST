#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PainterUI.generated.h"

class UProgressBar;
class UCanvasPanel;
class UTexture2D;

UCLASS()
class MYPROJECT_API UPainterUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	// ���콺 ����
	bool bIsDrawing = false;
	FVector2D LastDrawPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Painter")
	float PaintAmount = 1.0f;

	// ����Ʈ ���跮
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Painter")
	float PaintUsagePerStroke = 0.0001f;

	// �׸��� ���� (Canvas)
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* PaintCanvas;

	UPROPERTY(meta = (BindWidget))
	class UButton* CloseButton;

	// ���� �� ǥ�ÿ�
	UPROPERTY(meta = (BindWidget))
	UProgressBar* PaintProgressBar;

	UPROPERTY(meta = (BindWidget))
	class UButton* BrushColorBlack;

	UPROPERTY(meta = (BindWidget))
	class UButton* BrushColorRed;

	UPROPERTY(meta = (BindWidget))
	class UButton* BrushColorGreen;

	UPROPERTY(meta = (BindWidget))
	class UButton* BrushColorBlue;

	UFUNCTION()
	void OnCloseClicked();

	// ��/�귯�ÿ� �ؽ�ó
	UPROPERTY(EditAnywhere, Category = "Brush")
	UTexture2D* BrushTexture;

	// ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Brush")
	FLinearColor CurrentBrushColor = FLinearColor::Black;

	UFUNCTION()
	void SelectBlackBrush()
	{
		CurrentBrushColor = FLinearColor::Black;
	}

	UFUNCTION()
	void SelectRedBrush()
	{
		CurrentBrushColor = FLinearColor::Red;
	}

	UFUNCTION()
	void SelectBlueBrush()
	{
		CurrentBrushColor = FLinearColor::Blue;
	}

	UFUNCTION()
	void SelectGreenBrush()
	{
		CurrentBrushColor = FLinearColor::Green;
	}



	void SpawnBrushDot(const FVector2D& Pos);
	void SpawnBrushLine(const FVector2D& From, const FVector2D& To);
	FVector2D GetMouseLocalPosition();
	void ConsumePaint();
	bool IsMouseInsidePaintCanvas();

	UFUNCTION(BlueprintCallable)
	void FinishMission();
};