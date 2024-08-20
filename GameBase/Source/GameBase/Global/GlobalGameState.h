// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "GlobalGameState.generated.h"

UCLASS()
class GAMEBASE_API UActorGroup : public UObject
{
	GENERATED_BODY()

public :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> Actors;
};

/**
 * 
 */
UCLASS()
class GAMEBASE_API AGlobalGameState : public AGameState
{
	GENERATED_BODY()
	
public :
	template<typename EnumType>
	void PushActor(EnumType _Index, AActor* _Actor)
	{
		PushActor(static_cast<uint8>(_Index), _Actor);
	}

	void PushActor(uint8 _Index, AActor* _Actor);

	template<typename EnumType>
	UActorGroup* GetActorGroup(EnumType _Index)
	{
		return GetActorGroup(static_cast<uint8>(_Index));
	}

	UActorGroup* GetActorGroup(uint8 _Index);

private :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TMap<uint8, UActorGroup*> AllActor;
};
