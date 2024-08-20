// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Global/GameEnum.h"
#include "PlayerDataRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerDataRow : public FTableRowBase
{
	GENERATED_BODY()

public :
	FORCEINLINE FString GetPlayerName() const
	{
		return PlayerName;
	}

	FORCEINLINE int GetPlayerHP() const
	{
		return Hp;
	}

	FORCEINLINE int GetPlayerMP() const
	{
		return Mp;
	}

	FORCEINLINE int GetPlayerAttackDamage() const
	{
		return AttackDamage;
	}

	FORCEINLINE int GetPlayerAbilityPower() const
	{
		return AbilityPower;
	}

	FORCEINLINE int GetPlayerMoveSpeed() const
	{
		return MoveSpeed;
	}

	FORCEINLINE int GetPlayerAttackSpeed() const
	{
		return AttackSpeed;
	}

	FORCEINLINE TSubclassOf<class UAnimInstance> GetPlayerAnimInstance() const
	{
		return PlayerAnimInstance;
	}

	FORCEINLINE TMap<EPlayerUpAnimationState, class UAnimMontage*> GetPlayerUpAnimMontages() const
	{
		return AnimUpMontages;
	}

	FORCEINLINE TMap<EPlayerDownAnimationState, class UAnimMontage*> GetPlayerDownAnimMontages() const
	{
		return AnimDownMontages;
	}

	FORCEINLINE TMap<EPlayerUDAnimationState, class UAnimSequence*> GetPlayerUDAnimSequences() const
	{
		return AnimUDSequences;
	}

private :
	/// <summary>
	/// Player 이름
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	FString PlayerName = TEXT("");

	/// <summary>
	/// Player HP
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	int Hp = -1;

	/// <summary>
	/// Player MP
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	int Mp = -1;

	/// <summary>
	/// Player AD
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	int AttackDamage = -1;

	/// <summary>
	/// Player AP
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	int AbilityPower = -1;

	/// <summary>
	/// Player 이동 속도
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))

	int MoveSpeed = 1;

	/// <summary>
	/// Player 공격 속도
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	int AttackSpeed = 1;

	/// <summary>
	/// Player Anim Instance
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	TSubclassOf<class UAnimInstance> PlayerAnimInstance;

	/// <summary>
	/// Player Up Montage
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	TMap<EPlayerUpAnimationState, class UAnimMontage*> AnimUpMontages = TMap<EPlayerUpAnimationState, class UAnimMontage*>();

	/// <summary>
	/// Player Down Montage
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	TMap<EPlayerDownAnimationState, class UAnimMontage*> AnimDownMontages = TMap<EPlayerDownAnimationState, class UAnimMontage*>();

	/// <summary>
	/// Player Animation Sequence
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	TMap<EPlayerUDAnimationState, class UAnimSequence*> AnimUDSequences = TMap<EPlayerUDAnimationState, class UAnimSequence*>();
};
