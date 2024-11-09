// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "GameplayTagContainer.h"
#include "RXPlayerStart.generated.h"

/**
 * 
 */
UCLASS()
class RETURN_XENIA_API ARXPlayerStart : public APlayerStart
{
	GENERATED_BODY()
	
public:
	// �±� �Ӽ� �߰�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DestinationTag")
	FGameplayTag StartTag;
};
