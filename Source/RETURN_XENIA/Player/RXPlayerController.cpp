// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/RXPlayerController.h"
#include "Components/WidgetComponent.h"
#include "Character/RXPlayer.h"
#include "UI/RXHUDWidget.h"

ARXPlayerController::ARXPlayerController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}
void ARXPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// HUD ������ ȭ�鿡 �߰� -> ���������� �������Ʈ���� ĳ��
	if (RXHUDWidgetClass) // HSHUDWidgetClass�� ��ȿ���� Ȯ��
	{
		ARXHUDWidget = CreateWidget<URXHUDWidget>(GetWorld(), RXHUDWidgetClass);
		if (ARXHUDWidget)
		{
			// HUD�� ȭ�鿡 �߰�
			ARXHUDWidget->AddToViewport();
		}
	}
}

void ARXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}