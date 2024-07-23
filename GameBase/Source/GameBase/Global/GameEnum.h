﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameEnum.generated.h"


UENUM(BlueprintType)
enum class EUpAnimationState : uint8
{
	Idle UMETA(DisplayName = "기본"),
	Mode UMETA(DisplayName = "걷기"),
	Dash UMETA(DisplayName = "대쉬"),
	Attack UMETA(DisplayName = "공격"),
	Max UMETA(DisplayName = "Max"),
};

UENUM(BlueprintType)
enum class EDownAnimationState : uint8
{
	Idle UMETA(DisplayName = "기본"),
	Move UMETA(DisplayName = "걷기"),
	Dash UMETA(DisplayName = "대쉬"),
	Max UMETA(DisplayName = "Max"),
};

UENUM(BlueprintType)
enum class EPlayerDir : uint8
{
	Left UMETA(DisplayName = "왼쪽"),
	Right UMETA(DisplayName = "오른쪽"),
	Front UMETA(DisplayName = "앞"),
	Back UMETA(DisplayName = "뒤"),
	Max UMETA(DisplayName = "Xax"),
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
