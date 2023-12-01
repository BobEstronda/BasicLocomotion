// Fill out your copyright notice in the Description page of Project Settings.


#include "BLP_AnimInstance.h"
#include "GameFramework/Character.h"


void UBLP_AnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	RequestCharacterRef();

	RequestCharacterMovementComponentRef();
	
}

void UBLP_AnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (!CharacterReference)
	{
		return;
	}
	UpdateGroundSpeed();

	UpdateGroundStates();

	UpdateInAirState();
}

void UBLP_AnimInstance::RequestCharacterRef()
{
	CharacterReference = Cast<ACharacter>(TryGetPawnOwner());
}

void UBLP_AnimInstance::RequestCharacterMovementComponentRef()
{
	CharacterMovementComponentRef = CharacterReference->GetCharacterMovement();
}

void UBLP_AnimInstance::UpdateGroundSpeed()
{
	GroundSpeed = CharacterReference->GetVelocity().Size2D();
}

void UBLP_AnimInstance::UpdateGroundStates()
{
	bIdle = GroundSpeed == 0.0f;
	bWalk = GroundSpeed > 0.0f && GroundSpeed <= WalkSpeed;
	bRunning = GroundSpeed >= RunningSpeed;
}

void UBLP_AnimInstance::UpdateInAirState()
{
	bIsInAir = CharacterMovementComponentRef->IsFalling();
}
