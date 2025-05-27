// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "NetDataRow.generated.h"

USTRUCT(BlueprintType)
struct FNetDataRow : public FTableRowBase
{
	GENERATED_BODY()

public :
	inline FString GetName()
	{
		return Name;
	}
	
	inline FString GetIP()
	{
		return IP;
	}

	inline FString GetPort()
	{
		return Port;
	}

	inline bool IsServer() const
	{
		return bServer;
	}

private :
	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = true))
	FString Name = "";
	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = true))
	FString IP = "";
	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = true))
	FString Port = "";
	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = true))
	bool bServer = false;
};