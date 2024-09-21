// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterGameMode/CharacterDefaultCharacter.h"
#include "Global/GameEnum.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API APlayerCharacter : public ACharacterDefaultCharacter
{
	GENERATED_BODY()
	
public :
	// Sets default values for this character's properties
	APlayerCharacter();

protected :
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void AnimationEnd(FString _CurMontage) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public :
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Reliable, Server)
	void InitPlayerState();
	void InitPlayerState_Implementation();

private :
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EPlayerUDAnimationState IdleUpDown = EPlayerUDAnimationState::None;
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EPlayerUpAnimationState IdleUp = EPlayerUpAnimationState::None;
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EPlayerDownAnimationState IdleDown = EPlayerDownAnimationState::None;
};
