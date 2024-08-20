// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CharacterPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API ACharacterPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public :
	ACharacterPlayerState();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	/// <summary>
	/// Player State √ ±‚»≠
	/// </summary>
	UFUNCTION()
	void InitPlayerState();

	FORCEINLINE int GetPlayerHP() const
	{
		return PlayerHP;
	}

	FORCEINLINE int GetPlayerMP() const
	{
		return PlayerMP;
	}

	
	UFUNCTION(Reliable, Server)
	void HpUpdate(EPlayerAttackType _AttackType, int _Damage);
	void HpUpdate_Implementation(EPlayerAttackType _AttackType, int _Damage);

	UFUNCTION(Reliable, Server)
	void MpUpdate(int _UseMPValue);
	void MpUpdate_Implementation(int _UseMPValue);
	
private :

	UPROPERTY(Replicated)
	int PlayerHP = -1;

	UPROPERTY(Replicated)
	int PlayerMP = -1;

	UPROPERTY(Replicated)
	int AttackDamage = -1;

	UPROPERTY(Replicated)
	int AbilityPower = -1;

	UPROPERTY()
	int MoveSpeed = 1;

	UPROPERTY()
	int AttackSpeed = 1;
};
