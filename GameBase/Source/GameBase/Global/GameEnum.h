// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameEnum.generated.h"

UENUM(BlueprintType)
enum class EObjectType : uint8
{
	None UMETA(DisplayName = "None"),
	Player UMETA(DisplayName = "Player"),
	Monster UMETA(DisplayName = "Monster"),
	Item UMETA(DisplayName = "Item"),
	Max UMETA(DisplayName = "Max"),
};

/// <summary>
/// Player 공격 타입
/// </summary>
UENUM(BlueprintType)
enum class EPlayerAttackType : uint8
{
	None UMETA(DisplayName = "None"),
	AttackDamageType UMETA(DisplayName = "AD"),
	AbilityPowerType UMETA(DisplayName = "AP"),
	Max UMETA(DisplayName = "Max"),
};

UENUM(BlueprintType)
enum class EPlayerUDAnimationState : uint8
{
	None UMETA(DisplayName = "None"),
	Skill UMETA(DisplayName = "Skill"),
	Max UMETA(DisplayName = "Max"),
};

/// <summary>
/// Player 상체 상태
/// </summary>
UENUM(BlueprintType)
enum class EPlayerUpAnimationState : uint8
{
	None UMETA(DisplayName = "None"),

	Town_Idle UMETA(DisplayName = "마을 기본"),
	Dungeon_Idle UMETA(DisplayName = "던전 기본"),

	Move UMETA(DisplayName = "걷기"),
	Dash UMETA(DisplayName = "대쉬"),

	Attack UMETA(DisplayName = "공격"),
	Dash_Attack UMETA(DisplayName = "대쉬 공격"),
	
	Jump_Attack UMETA(DisplayName = "점프 공격"),

	Max UMETA(DisplayName = "Max"),
};

/// <summary>
/// Player 하체 상태
/// </summary>
UENUM(BlueprintType)
enum class EPlayerDownAnimationState : uint8
{
	None UMETA(DisplayName = "None"),

	Town_Idle UMETA(DisplayName = "평소 기본"),
	Attack_Idle UMETA(DisplayName = "공격 기본"),

	Move UMETA(DisplayName = "걷기"),
	Dash UMETA(DisplayName = "대쉬"),
	Jump UMETA(DisplayName = "점프"),

	Max UMETA(DisplayName = "Max"),
};

/// <summary>
/// Player 방향
/// </summary>
UENUM(BlueprintType)
enum class EPlayerDir : uint8
{
	None UMETA(DisplayName = "None"),
	Left UMETA(DisplayName = "왼쪽"),
	Right UMETA(DisplayName = "오른쪽"),
	Front UMETA(DisplayName = "앞"),
	Back UMETA(DisplayName = "뒤"),
	Max UMETA(DisplayName = "Xax"),
};

UENUM(BlueprintType)
enum class EPlayerItemSlot : uint8
{
	None UMETA(DisplayName = "None"),
	LWeapon UMETA(DisplayName = "왼손 슬롯"),
	RWeapon UMETA(DisplayName = "오른손 슬롯"),
	BothWeapon UMETA(DisplayName = "양손 슬롯"),
	Max UMETA(DisplayName = "Max"),
};




/**
 * 
 */
UCLASS()
class GAMEBASE_API UGameEnum : public UObject
{
	GENERATED_BODY()
	
};
