// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RXCharacterBase.h"
#include "Interface/RXNPCDialogueInterface.h"
#include "RXNonPlayer.generated.h"

/**
 * 
 */
UCLASS()
class RETURN_XENIA_API ARXNonPlayer : public ARXCharacterBase, public IRXNPCDialogueInterface
{
	GENERATED_BODY()
public:
	//�����̰��� ��ȣ�ۿ� e���� �� �����ʿ�. 


protected: 	//RXNPCDialogueInterface Interface Virtual Func override Implementation
	virtual void StartDialogue() override;
	virtual void DisplayDialogue() override;
	virtual void EndDialogue() override;
};
