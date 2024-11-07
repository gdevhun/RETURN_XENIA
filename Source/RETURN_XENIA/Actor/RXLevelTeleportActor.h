// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RXLevelTeleportActor.generated.h"

UCLASS()
class RETURN_XENIA_API ARXLevelTeleportActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ARXLevelTeleportActor();

protected:

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class USphereComponent> SphereComponent;

	// ī�װ� TeleportSettings �˻� �� �������Ʈ �����Ϳ��� �����������.
	UPROPERTY(EditAnywhere, Category="TeleportSettings")
	TObjectPtr<class APlayerStart> TargetLocation; // ���� ���� ������ �̵���ų Ÿ�� �����̼�

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TeleportSettings")
	FName NextLevelName;  // �ٸ��������� �̵�

	
};
