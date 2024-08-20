// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MainGameBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API UMainGameBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public :
	static class UBaseGameInstance* GetMainGameInstance(const UWorld* WorldContextObject);
	
	static class AGlobalGameState* GetMainGameState(const UWorld* WorldContextObject);

	template<typename EnumType>
	static void PushActor(EnumType _GroupIndex, AActor* _Actor)
	{
		if (nullptr == _Actor->GetWorld())
		{
			return;
		}

		PushActor(static_cast<uint8>(_GroupIndex), _Actor);
	}

	UFUNCTION(BlueprintCallable, Category = "Game", meta = (UnsafeDuringActorConstruction = "true"))
	static void PushActor(uint8 _GroupIndex, AActor* _Actor);
};
