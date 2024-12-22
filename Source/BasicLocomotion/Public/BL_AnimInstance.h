// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BL_AnimInstance.generated.h"

class ACharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class BASICLOCOMOTION_API UBL_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly,Category = "Locomotion|Reference")
	ACharacter* Character;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly,Category = "Locomotion|Reference")
	UCharacterMovementComponent* MovementComponent;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly,Category = "Locomotion|State|Ground")
	float GroundSpeed;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Locomotion|State|Ground")
	bool bInGroundMovement = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Locomotion|State|InAir")
	bool bIsInAir = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Locomotion|State|InAir")
	bool bInAirUp = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Locomotion|State|InAir")
	bool bInAirDown = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Locomotion|State|Ground")
	bool bIsCrouching = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Locomotion|State|InAir")
	bool bIsJumping = false;
	
public:
	
	virtual void NativeBeginPlay() override;
	
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable,BlueprintPure, meta = (BlueprintThreadSafe), Category = "Locomotion|Reference")
	FORCEINLINE ACharacter* GetCharacter() const {return Character; }

	UFUNCTION(BlueprintCallable,BlueprintPure, meta = (BlueprintThreadSafe), Category = "Locomotion|Reference")
	FORCEINLINE UCharacterMovementComponent* GetMovementComponent() const {return MovementComponent; }

	UFUNCTION(BlueprintCallable,BlueprintPure, meta = (BlueprintThreadSafe), Category = "Locomotion|State|Ground")
	FORCEINLINE float GetGroundSpeed() const {return GroundSpeed; }

	UFUNCTION(BlueprintCallable,BlueprintPure, meta = (BlueprintThreadSafe), Category = "Locomotion|State|Ground")
	FORCEINLINE bool GetInIdle() const {return !bInGroundMovement; }

	UFUNCTION(BlueprintCallable,BlueprintPure, meta = (BlueprintThreadSafe), Category = "Locomotion|State|Ground")
	FORCEINLINE bool GetStanding() const {return !bIsCrouching; }

	UFUNCTION(BlueprintCallable,BlueprintPure, meta = (BlueprintThreadSafe), Category = "Locomotion|State|Ground")
	FORCEINLINE bool GetInGround() const { return !bIsInAir; }
};
