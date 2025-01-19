// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/RXCircularPuzzelBase.h"
#include "Player/RXPlayerController.h"
#include "Character/RXPlayer.h"
#include "RXDebugHelper.h"
#include "Engine/Engine.h"

ARXCircularPuzzelBase::ARXCircularPuzzelBase()
{
    PrimaryActorTick.bCanEverTick = false;

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

void ARXCircularPuzzelBase::BeginPlay()
{
	Super::BeginPlay();

    Player = Cast<ARXPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
    PlayerController = Cast<ARXPlayerController>(Player->GetController());
}

int32 ARXCircularPuzzelBase::CalculateScore() const
{
    // �� ������ ���� ���õ� ���� ���� ����ġ�� �Բ� �ջ�
    int32 Score = 0;
    Score += OuterWheel[OuterIndex] * 100; // �ܰ� ����
    Score += MiddleWheel[MiddleIndex] * 10; // �߰� ����
    Score += InnerWheel[InnerIndex] * 1; // ���� ����
    return Score;
}

bool ARXCircularPuzzelBase::IsCorrectAnswer() const
{
    // ���� ������ �������� Ȯ��
    return CalculateScore() == TargetScore;
}

void ARXCircularPuzzelBase::StartCircularPuzzelMode_Implementation()
{
    // ���� ��� ī�޶�� ��ȯ
    SwitchToCamera(PuzzelModeCamera, 0.0f);
}

void ARXCircularPuzzelBase::EndCircularPuzzelMode_Implementation()
{
    // ���� �÷��̾� ī�޸��� ����
    SwitchToCamera(Player, 0.0f);
}

void ARXCircularPuzzelBase::RotateToClockWise_Implementation()
{
    switch (CurrentSelectedWheel)
    {
    case 0: // �ܰ� ����
        RotateWheel(OuterIndex, OuterWheel, true);
        D(FString::Printf(TEXT("Outer Wheel rotated clockwise to index: %d"), OuterIndex));
        break;
    case 1: // �߰� ����
        RotateWheel(MiddleIndex, MiddleWheel, true);
        D(FString::Printf(TEXT("Middle Wheel rotated clockwise to index: %d"), MiddleIndex));
        break;
    case 2: // ���� ����
        RotateWheel(InnerIndex, InnerWheel, true);
        D(FString::Printf(TEXT("Inner Wheel rotated clockwise to index: %d"), InnerIndex));
        break;
    default:
        break;
    }
}

void ARXCircularPuzzelBase::RotateToCounterClockWise_Implementation()
{
    switch (CurrentSelectedWheel)
    {
    case 0: // �ܰ� ����
        RotateWheel(OuterIndex, OuterWheel, false);
        D(FString::Printf(TEXT("Outer Wheel rotated counter-clockwise to index: %d"), OuterIndex));
        break;
    case 1: // �߰� ����
        RotateWheel(MiddleIndex, MiddleWheel, false);
        D(FString::Printf(TEXT("Middle Wheel rotated counter-clockwise to index: %d"), MiddleIndex));
        break;
    case 2: // ���� ����
        RotateWheel(InnerIndex, InnerWheel, false);
        D(FString::Printf(TEXT("Inner Wheel rotated counter-clockwise to index: %d"), InnerIndex));
        break;
    default:
        break;
    }
}

void ARXCircularPuzzelBase::SwitchSelectedWheel_Implementation()
{
    CurrentSelectedWheel = (CurrentSelectedWheel + 1) % 3;
    switch (CurrentSelectedWheel)
    {
    case 0:
        D("Switched to Outer Wheel.");
        break;
    case 1:
        D("Switched to Middle Wheel.");
        break;
    case 2:
        D("Switched to Inner Wheel.");
        break;
    default:
        break;
    }
}

void ARXCircularPuzzelBase::RotateWheel(int32& CurrentIndex, const TArray<int32>& Wheel, bool bClockwise)
{
    // ���� �ε����� �ð�/�ݽð� ��ȯ
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

void ARXCircularPuzzelBase::SwitchToCamera(AActor* NewCamera, float BlendTime) const
{
    if (PlayerController && NewCamera)
    {
        PlayerController->SetViewTargetWithBlend(NewCamera, BlendTime);
    }
}
