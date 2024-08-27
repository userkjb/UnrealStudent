// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "InputDatas.generated.h"

USTRUCT()
struct FMyInputAction
{
	GENERATED_BODY()

public :
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UInputAction> Actions = nullptr;
};


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

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//class UInputMappingContext* InputMappint;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UInputMappingContext> InputMappint;


	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<class UInputAction*> Actions;
	UPROPERTY(EditDefaultsOnly)
	TArray<FMyInputAction> Actions;
};
