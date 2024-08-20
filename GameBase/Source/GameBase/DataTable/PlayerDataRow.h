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


private :
	/// <summary>
	/// Player 이름
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources", meta = (AllowprivateAccess = "true"))
	FString PlayerName = "None";

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
};
