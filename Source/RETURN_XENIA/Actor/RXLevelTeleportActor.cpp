// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SphereComponent.h"
#include "Character/RXPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "System/RXGameInstance.h" 
#include "RXDebugHelper.h"
#include "Actor/RXLevelTeleportActor.h"

ARXLevelTeleportActor::ARXLevelTeleportActor()
{

    // Sphere Component CDO ���� �� ����
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SphereComponent->SetupAttachment(RootComponent);
    SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    SphereComponent->SetCollisionObjectType(ECC_WorldDynamic);
    SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
    SphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);


    // Sphere Component�� �������� ���� ����
    SphereComponent->SetSphereRadius(80.0f); // ������ ����
    SphereComponent->ShapeColor = FColor::Green; // ���� ���� (����׿�)

}

void ARXLevelTeleportActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARXLevelTeleportActor::TeleportToOtherLevel()
{
    // ���� �ν��Ͻ��� �����Ͽ� DestinationTag�� ����
    if (URXGameInstance* GameInstance = Cast<URXGameInstance>(GetGameInstance()))
    {
        GameInstance->SetDestinationTag(DestinationTag);
    }

    // ���� ��ȯ
    UGameplayStatics::OpenLevel(this, NextLevelName);
    
}



