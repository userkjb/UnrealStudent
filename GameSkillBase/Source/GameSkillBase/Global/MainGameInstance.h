// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DataTable/NetDataRow.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMESKILLBASE_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public :
	const struct FNetDataRow* GetNetData(FName _Name);

public :
	UFUNCTION()
	FORCEINLINE UDataTable* GetNetDataTable()
	{
		return NetDataTable;
	}

private :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	UDataTable* NetDataTable = nullptr;
};
