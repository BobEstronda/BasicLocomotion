// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BLP_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BASICLOCOMOTIONPARAMETERS_API UBLP_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:

	/* Vai guardar a referencia do character.
	 Will save the character reference.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "BLP|Reference")
	ACharacter* CharacterReference;

	/* Vai guardar a referencia do character movement component.
	 Will save the reference of the character movement component.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "BLP|Reference")
	UCharacterMovementComponent* CharacterMovementComponentRef;
	
	/* Velocidade do personagem ao se mover no chão
	Character's speed when moving on the ground*/
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "BLP|State")
	float GroundSpeed;

	/*Se for verdadeiro está parado.
	If it is true it is stopped.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "BLP|State")
	bool bIdle;

	/*Se for verdadeiro está caminhando.
	If it is true it is walking.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "BLP|State")
	bool bWalk;

	/*Se for verdadeiro está Correndo.
	If it is true is Running.*/
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "BLP|State")
	bool bRunning;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "BLP|State")
	bool bIsInAir;

	/* Variavel usada na função "UpdateBasicsStates" para comparação com a variavel "GroundSpeed".
	 Variable used in the "UpdateBasicsStates" function for comparison with the "GroundSpeed" variable.*/
	UPROPERTY(BlueprintReadWrite, Category = "BLP|State|Comparing")
	float WalkSpeed;

	/* Variavel usada na função "UpdateBasicsStates" para comparação com a variavel "GroundSpeed".
	 Variable used in the "UpdateBasicsStates" function for comparison with the "GroundSpeed" variable.*/
	UPROPERTY(BlueprintReadWrite, Category = "BLP|State|Comparing")
	float RunningSpeed;

private:

	virtual void NativeBeginPlay() override;
	
	/*Função de substituição da função Thread Safe Update Animation. É Executado em um thread de trabalho imediatamente antes da atualização do gráfico.
	Native thread safe update override point. Executed on a worker thread just prior to graph update.*/
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	/*Função responsavel por pegar a referencia do character
	Function responsible for grabbing the character reference*/
	void RequestCharacterRef();
	
	/*Função responsavel por pegar a referencia do character movement component
	Function responsible for grabbing the character movement component ref*/
	void RequestCharacterMovementComponentRef();
	
	/*Função responsavel por atualizar a velocidade do personagem "GroundSpeed"
	Function responsible for updating the speed of the character "GroundSpeed"*/
	void UpdateGroundSpeed();

	/*Função responsavel por atualizar os estados Terrestres de locomoção do character
	Function responsible for updating the character's Terrestrial states of locomotion*/
	void UpdateGroundStates();

	/*Função responsavel por atualizar o estado aereo do character
	 Function responsible for updating the character's air state*/
	void UpdateInAirState();
};
