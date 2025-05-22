#include "RedZoneCube.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/WidgetComponent.h"
#include "RedZoneUI.h"
#include "MyProject/MyProjectCharacter.h"

ARedZoneCube::ARedZoneCube()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);	// �浹�� QueryOnly�� ���� (Overlap�� ����, ���� ���� ����)
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);	// ��� ä�ο� ���� Overlap �������� ����

}

void ARedZoneCube::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("DynamicMaterial Created1"));

	if (Mesh)
	{
		//UE_LOG(LogTemp, Warning, TEXT("DynamicMaterial Created2"));

		DynamicMaterial = Mesh->CreateAndSetMaterialInstanceDynamic(0);		// ��Ƽ���� �ν��Ͻ��� �������� ����
		if (DynamicMaterial)
		{
			// ��Ƽ������ OpacityLevel �Ķ���͸� 0���� ���� (���� ����)
			//UE_LOG(LogTemp, Warning, TEXT("DynamicMaterial Created3"));
			DynamicMaterial->SetScalarParameterValue(TEXT("OpacityLevel"), 0.0f);
		}
	}
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARedZoneCube::OnPlayerOverlapBegin);
	Mesh->OnComponentEndOverlap.AddDynamic(this, &ARedZoneCube::OnPlayerOverlapEnd);
	redzoneStart = false; // RedZone ���� ���� �ʱ�ȭ	
	isBlock = false;

}

void ARedZoneCube::UpdateOpacityFromManager(float Alpha)
{
	if (!DynamicMaterial || bHasBlocked) return;
	// ��Ƽ������ ��ȿ���� �ʰų� �̹� Block ���¸� ����

	DynamicMaterial->SetScalarParameterValue(TEXT("OpacityLevel"), Alpha);
	// ��Ƽ������ OpacityLevel �Ķ���͸� ���� (0 ~ 1 ���� ��)

}

void ARedZoneCube::ForceBlock(float Duration)
{
	if (bHasBlocked) return;

	FadeDuration = Duration;
	ElapsedFadeTime = 0.0f;
	redzoneStart = true;
	// Tick Ȱ��ȭ
	GetWorld()->GetTimerManager().SetTimer(FadeTimerHandle, this, &ARedZoneCube::UpdateFade, 0.05f, true);
}
void ARedZoneCube::UpdateFade()
{
	if (!DynamicMaterial || bHasBlocked || FadeDuration <= 0.0f)
	{
		GetWorld()->GetTimerManager().ClearTimer(FadeTimerHandle);
		return;
	}

	ElapsedFadeTime += 0.05f;

	float Alpha = FMath::Clamp(ElapsedFadeTime / FadeDuration, 0.0f, 1.0f);
	DynamicMaterial->SetScalarParameterValue(TEXT("OpacityLevel"), Alpha);

	if (Alpha >= 1.0f)
	{
		// �浹 Block ��ȯ
		Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
		bHasBlocked = true;

		// Ÿ�̸� ����
		GetWorld()->GetTimerManager().ClearTimer(FadeTimerHandle);
		isBlock = true;
	}
}

void ARedZoneCube::OnPlayerOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (!redzoneStart || bWidgetShown || !WarningWidgetClass || isBlock) return;

	if (Cast<AMyProjectCharacter>(OtherActor))
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{
			SpawnedWidget = CreateWidget<UUserWidget>(PC, WarningWidgetClass);
			if (SpawnedWidget)
			{
				SpawnedWidget->AddToViewport();
				bWidgetShown = true;
			}
		}
	}
}

void ARedZoneCube::OnPlayerOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!redzoneStart || !bWidgetShown || !SpawnedWidget || isBlock) return;

	if (Cast<AMyProjectCharacter>(OtherActor))
	{
		SpawnedWidget->RemoveFromParent();
		SpawnedWidget = nullptr;
		bWidgetShown = false;
	}
}
