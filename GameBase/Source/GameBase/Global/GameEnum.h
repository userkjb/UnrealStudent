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
	Left,
	Right,
	Front,
	Back,
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
