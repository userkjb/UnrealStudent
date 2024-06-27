// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameEnum.generated.h"


UENUM(BlueprintType)
enum class EAnimationState : uint8
{
	Idle,
	Run,
	Attack,
};

UENUM(BlueprintType)
enum class EPlayerDir : uint8
{
	Left UMETA(DisplayName = "왼쪽"),
	Right UMETA(DisplayName = "오른쪽"),
	Front UMETA(DisplayName = "앞"),
	Back UMETA(DisplayName = "뒤"),
	Max UMETA(DisplayName = "X"),
};

UENUM(BlueprintType)
enum class EPlayerItemSlot : uint8
{
	LWeapon,
	RWeapon,
	BothWeapon,
	SlotMax,
};




/**
 * 
 */
UCLASS()
class GAMEBASE_API UGameEnum : public UObject
{
	GENERATED_BODY()
	
};
