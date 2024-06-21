// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "NetDataRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FNetDataRow : public FTableRowBase
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	FString Name = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	FString IP = TEXT("");
};
