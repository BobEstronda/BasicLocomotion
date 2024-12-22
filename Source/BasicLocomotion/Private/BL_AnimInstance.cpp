// Fill out your copyright notice in the Description page of Project Settings.


#include "BL_AnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void UBL_AnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Character = Cast<ACharacter>(TryGetPawnOwner());
	if (!Character) return;
	
	MovementComponent = Cast<UCharacterMovementComponent>(Character->GetCharacterMovement());
}

void UBL_AnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (!Character || !MovementComponent) return;

	Velocity = Character->GetVelocity();
	GroundSpeed = Velocity.Size2D();
	bInGroundMovement = GroundSpeed > 0.f;

	bIsInAir = MovementComponent->IsFalling();
	const float& ZVelocity = Velocity.Z;
	bInAirUp = ZVelocity > 0.f && bIsInAir;
	bInAirDown = ZVelocity < 0.f && bIsInAir;
	
	bIsCrouching = MovementComponent->IsCrouching() && !bIsInAir;
}
