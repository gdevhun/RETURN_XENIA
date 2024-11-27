// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RXShieldCoolTimeWidget.h"
#include "Components/Image.h"
#include "Player/RXPlayerStatComponent.h"

URXShieldCoolTimeWidget::URXShieldCoolTimeWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void URXShieldCoolTimeWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AActor* Owner = GetOwningPlayerPawn();
	if (Owner)
	{
		PlayerStatComp = Owner->FindComponentByClass<URXPlayerStatComponent>();
		if (PlayerStatComp)
		{
			// ��������Ʈ ����
			PlayerStatComp->OnPlayerShieldSecRegenChanged.AddUObject(this, &URXShieldCoolTimeWidget::UpdateCoolTimeImage);
			PlayerStatComp->OnPlayerShieldFull.AddUObject(this, &URXShieldCoolTimeWidget::UpdateCoolTimeFullImage);
		}
	}
}

void URXShieldCoolTimeWidget::UpdateCoolTimeImage(int32 ImageIdx)
{
	// �̹��� �ε����� ������ �ʰ����� �ʵ��� ��ȣ
	if (CoolTimeImages.IsValidIndex(ImageIdx-1))
	{
		if (SecondShowImage)
		{
			// �̹��� �귯�� ������Ʈ
			SecondShowImage->SetBrushFromTexture(CoolTimeImages[ImageIdx-1]);
		}
	}
}

void URXShieldCoolTimeWidget::UpdateCoolTimeFullImage()
{
	if (SecondShowImage)
	{
		// ���� ������ ȹ��� �귯�� ������Ʈ
		SecondShowImage->SetBrushFromTexture(CoolTimeImages[7]);
	}
}
