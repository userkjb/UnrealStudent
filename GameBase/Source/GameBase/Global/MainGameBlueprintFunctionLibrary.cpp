// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/MainGameBlueprintFunctionLibrary.h"
#include "BaseGameInstance.h"
#include "GlobalGameState.h"

UBaseGameInstance* UMainGameBlueprintFunctionLibrary::GetMainGameInstance(const UWorld* WorldContextObject)
{
	UBaseGameInstance* MainGameInst = WorldContextObject->GetGameInstanceChecked<UBaseGameInstance>();

	if (false == MainGameInst->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (false == Inst->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return MainGameInst;
}

AGlobalGameState* UMainGameBlueprintFunctionLibrary::GetMainGameState(const UWorld* WorldContextObject)
{
	if (nullptr == WorldContextObject)
	{
		return nullptr;
	}

	const UWorld* World = Cast<UWorld>(WorldContextObject);
	AGlobalGameState* GameState = World->GetGameState<AGlobalGameState>();
	return GameState;
}

void UMainGameBlueprintFunctionLibrary::PushActor(uint8 _GroupIndex, AActor* _Actor)
{
	if (nullptr == _Actor->GetWorld())
	{
		return;
	}

	const UWorld* World = Cast<UWorld>(_Actor->GetWorld());

	AGlobalGameState* GameState = World->GetGameState<AGlobalGameState>();
	if (nullptr == GameState)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (false == GameState->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		return;
	}

	GameState->PushActor(_GroupIndex, _Actor);
}
