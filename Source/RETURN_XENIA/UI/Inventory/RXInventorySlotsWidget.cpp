// Fill out your copyright notice in the Description page of Project Settings.

#include "System/RXGameInstance.h"
#include "Components/UniformGridPanel.h"
#include "UI/RXMainMenuWidget.h"
#include "UI/Inventory/RXInventorySlotWidget.h"
#include "UI/Inventory/RXInventorySlotsWidget.h"

URXInventorySlotsWidget::URXInventorySlotsWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void URXInventorySlotsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// �������� MainMenuWidget �˻�
	MainMenuWidget = GetTypedOuter<URXMainMenuWidget>();

	URXGameInstance* GI = GetWorld()->GetGameInstance<URXGameInstance>();
	if (!GI || !GridPanel_Item) return;

	TArray<FString> ItemNames = { TEXT("KnotChar1"), TEXT("KnotChar2"), TEXT("KnotChar3"), TEXT("KnotChar4"),
		TEXT("KnotChar5"), TEXT("Heart"), TEXT("HintPaper") };

	const int X_COUNT = 3;
	const int Y_COUNT = 4;
	int32 CurrentItemIndex = 0;

	// ȹ��� ������ ����Ʈ�� ���͸�
	TArray<int32> AcquiredItemIndices;
	for (int32 i = 0; i < ItemNames.Num(); i++)
	{
		if (GI->IsItemStatusAcquired(ItemNames[i]))
		{
			AcquiredItemIndices.Add(i);
		}
	}

	// ���Կ� ������ �߰�
	for (int32 Y = 0; Y < Y_COUNT; Y++)
	{
		for (int32 X = 0; X < X_COUNT; X++)
		{
			// ���� ȹ��� �������� �ε����� ������ �ʰ��ϸ� �� ���� �߰�
			if (CurrentItemIndex >= AcquiredItemIndices.Num())
			{
				if (EmptySlotClass)
				{
					UUserWidget* SlotWidget = CreateWidget<UUserWidget>(GetOwningPlayer(), EmptySlotClass);
					GridPanel_Item->AddChildToUniformGrid(SlotWidget, Y, X);
				}
			}
			else
			{
				// ȹ��� ������ �߰�
				int32 ItemIndex = AcquiredItemIndices[CurrentItemIndex];
				if (ItemIndex < ItemClass.Num())
				{
					URXInventorySlotWidget* SlotWidget = CreateWidget<URXInventorySlotWidget>(GetOwningPlayer(), ItemClass[ItemIndex]);
					SlotWidget->SetMainMenuWidget(MainMenuWidget);

					GridPanel_Item->AddChildToUniformGrid(SlotWidget, Y, X);

					CurrentItemIndex++; // ������ �߰� �� �ε��� ����
				}
			}
		}
	}
}
