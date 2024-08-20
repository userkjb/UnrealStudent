// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Global/GameEnum.h"
#include "MonsterDataRow.generated.h"

/**
* 
*/
USTRUCT(BlueprintType)
struct FMonsterDataRow : public FTableRowBase
{
	GENERATED_BODY()

public :
	FORCEINLINE FString GetName() const
	{
		return Name;
	}

	FORCEINLINE class USkeletalMesh* GetMonsterSkeletalmesh() const
	{
		return MonsterSkeletalmesh;
	}

private :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name", meta = (AllowprivateAccess = "true"))
	FString Name = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMesh", meta = (AllowprivateAccess = "true"))
	class USkeletalMesh* MonsterSkeletalmesh = nullptr;
};

