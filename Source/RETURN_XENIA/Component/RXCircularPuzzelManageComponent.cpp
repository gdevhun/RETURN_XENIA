

#include "Component/RXCircularPuzzelManageComponent.h"
#include "Player/RXPlayerController.h"
#include "Character/RXPlayer.h"

URXCircularPuzzelManageComponent::URXCircularPuzzelManageComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// �ʱ�ȭ
	TargetScore = 0;
	OuterWheel = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	MiddleWheel = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	InnerWheel = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	CurrentSelectedWheel = 0; // �ܰ� ���� ����
	OuterIndex = 0;
	MiddleIndex = 0;
	InnerIndex = 0;
}


void URXCircularPuzzelManageComponent::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<ARXPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	PlayerController = Cast<ARXPlayerController>(Player->GetController());
	
}

int32 URXCircularPuzzelManageComponent::CalculateScore() const
{
	// �� ������ ���� ���õ� ���� ���� ����ġ�� �Բ� �ջ�
	int32 Score = 0;
	Score += OuterWheel[OuterIndex] * 100; // �ܰ� ����
	Score += MiddleWheel[MiddleIndex] * 10; // �߰� ����
	Score += InnerWheel[InnerIndex] * 1; // ���� ����
	return Score;
}

bool URXCircularPuzzelManageComponent::IsCorrectAnswer() const
{
	// ���� ������ �������� Ȯ��
	return CalculateScore() == TargetScore;
}

void URXCircularPuzzelManageComponent::StartCircularPuzzelMode_Implementation()
{
	// ī�޶� ��ȯ
	SwitchToCamera(PuzzelModeCamera, 0.0f);
}

void URXCircularPuzzelManageComponent::EndCircularPuzzelMode_Implementation()
{
	// ���� �÷��̾� ī�޶�� ����
	SwitchToCamera(Player, 0.0f);
}

void URXCircularPuzzelManageComponent::RotateToClockWise_Implementation()
{
	switch (CurrentSelectedWheel)
	{
	case 0: // �ܰ� ����
		RotateWheel(OuterIndex, OuterWheel, true);
		UE_LOG(LogTemp, Log, TEXT("Outer Wheel rotated clockwise to index: %d"), OuterIndex);
		break;
	case 1: // �߰� ����
		RotateWheel(MiddleIndex, MiddleWheel, true);
		UE_LOG(LogTemp, Log, TEXT("Middle Wheel rotated clockwise to index: %d"), MiddleIndex);
		break;
	case 2: // ���� ����
		RotateWheel(InnerIndex, InnerWheel, true);
		UE_LOG(LogTemp, Log, TEXT("Inner Wheel rotated clockwise to index: %d"), InnerIndex);
		break;
	default:
		break;
	}
}

void URXCircularPuzzelManageComponent::RotateToCounterClockWise_Implementation()
{
	switch (CurrentSelectedWheel)
	{
	case 0: // �ܰ� ����
		RotateWheel(OuterIndex, OuterWheel, false);
		UE_LOG(LogTemp, Log, TEXT("Outer Wheel rotated counter-clockwise to index: %d"), OuterIndex);
		break;
	case 1: // �߰� ����
		RotateWheel(MiddleIndex, MiddleWheel, false);
		UE_LOG(LogTemp, Log, TEXT("Middle Wheel rotated counter-clockwise to index: %d"), MiddleIndex);
		break;
	case 2: // ���� ����
		RotateWheel(InnerIndex, InnerWheel, false);
		UE_LOG(LogTemp, Log, TEXT("Inner Wheel rotated counter-clockwise to index: %d"), InnerIndex);
		break;
	default:
		break;
	}
}

void URXCircularPuzzelManageComponent::SwitchSelectedWheel_Implementation()
{
	CurrentSelectedWheel = (CurrentSelectedWheel + 1) % 3;
	switch (CurrentSelectedWheel)
	{
	case 0:
		UE_LOG(LogTemp, Log, TEXT("Switched to Outer Wheel."));
		break;
	case 1:
		UE_LOG(LogTemp, Log, TEXT("Switched to Middle Wheel."));
		break;
	case 2:
		UE_LOG(LogTemp, Log, TEXT("Switched to Inner Wheel."));
		break;
	default:
		break;
	}
}

void URXCircularPuzzelManageComponent::ExitCircularPuzzel_Implementation()
{
	// ���� �÷��̾� ī�޶�� ����
	SwitchToCamera(Player, 0.0f);
}

void URXCircularPuzzelManageComponent::RotateWheel(int32& CurrentIndex, const TArray<int32>& Wheel, bool bClockwise)
{
	// ���� �ε����� �ð�/�ݽð� �������� ȸ��
	int32 MaxIndex = Wheel.Num();
	if (bClockwise)
	{
		CurrentIndex = (CurrentIndex + 1) % MaxIndex;
	}
	else
	{
		CurrentIndex = (CurrentIndex - 1 + MaxIndex) % MaxIndex;
	}
}

void URXCircularPuzzelManageComponent::SwitchToCamera(AActor* NewCamera, float BlendTime) const
{
	if (PlayerController && NewCamera)
	{
		PlayerController->SetViewTargetWithBlend(NewCamera, BlendTime);
	}
}
