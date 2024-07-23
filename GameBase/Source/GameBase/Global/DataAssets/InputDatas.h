// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputDatas.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API UInputDatas : public UDataAsset
{
	GENERATED_BODY()
	
public :
	UInputDatas();
	~UInputDatas();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UInputMappingContext* InputMappint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UInputAction*> Actions;
};
