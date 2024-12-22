// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BL_AnimInstance.generated.h"

class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class BASICLOCOMOTION_API UBL_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Locomotion|Reference")
	ACharacter* Character;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Locomotion|Reference")
	UCharacterMovementComponent* MovementComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Locomotion|State|Ground")
	FVector Velocity;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Locomotion|State|Ground")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, Category = "Locomotion|State|InAir")
	bool bIsInAir = false;

	UPROPERTY(VisibleDefaultsOnly, Category = "Locomotion|State|InAir")
	bool bInAirUp = false;

	UPROPERTY(VisibleDefaultsOnly, Category = "Locomotion|State|InAir")
	bool bInAirDown = false;

	UPROPERTY(VisibleDefaultsOnly, Category = "Locomotion|State|Ground")
	bool bIsCrouching = false;

protected:
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite,Category = "Locomotion|State|InAir")
	bool bIsJumping = false;
	
public:
	
	virtual void NativeBeginPlay() override;
	
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE ACharacter* GetCharacter() const {return Character; }

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE UCharacterMovementComponent* GetMovementComponent() const {return MovementComponent; }

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE FVector GetVelocity() const {return Velocity; }

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE float GetGroundSpeed() const {return GroundSpeed; }

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE bool GetIsInAir() const {return bIsInAir; }

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE bool GetInAirUp() const {return bInAirUp; }

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE bool GetInAirDown() const {return bInAirDown; }

	UFUNCTION(BlueprintCallable,BlueprintPure)
	FORCEINLINE bool GetIsCrouching() const {return bIsCrouching; }
};
