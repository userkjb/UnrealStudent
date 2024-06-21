// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "PlayerDataRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerDataRow : public FTableRowBase
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	FString PlayerName = "None";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	int Hp = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	int Mp = 10;
};
