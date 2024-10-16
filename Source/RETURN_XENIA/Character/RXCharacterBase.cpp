// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RXCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARXCharacterBase::ARXCharacterBase()
{
	// Pawn
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// Movement
	GetCharacterMovement()->bOrientRotationToMovement = true;  // �̵� ���⿡ ���� ȸ��
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);  // ȸ�� �ӵ�
	GetCharacterMovement()->JumpZVelocity = 700.f;  // ���� �ӵ�
	GetCharacterMovement()->AirControl = 0.35f;  // ���߿����� ����
	GetCharacterMovement()->MaxWalkSpeed = 500.f;  // �ִ� �ȱ� �ӵ�
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;  // �ּ� �ȱ� �ӵ�
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;  // �ȱ� ���� �ӵ�

	// Mesh
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetCollisionProfileName(TEXT("CharacterMesh"));


}

