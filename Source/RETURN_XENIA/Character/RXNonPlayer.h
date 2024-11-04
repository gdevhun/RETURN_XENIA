// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RXCharacterBase.h"
#include "GameplayTagContainer.h"
#include "Interface/RXNPCDialogueInterface.h"
#include "RXNonPlayer.generated.h"

UCLASS()
class RETURN_XENIA_API ARXNonPlayer : public ARXCharacterBase, public IRXNPCDialogueInterface
{
	GENERATED_BODY()
public:
	//�����̰��� ��ȣ�ۿ� e���� �� �����ʿ�. 
	ARXNonPlayer();

protected: 	//RXNPCDialogueInterface Interface Virtual Func override Implementation

	virtual void BeginPlay() override;

	virtual void StartDialogue() override;
	virtual void DisplayDialogue() override;
	virtual void EndDialogue() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCType")
	FGameplayTag NPCType;

};
