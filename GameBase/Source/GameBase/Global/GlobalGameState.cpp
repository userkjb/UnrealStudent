// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalGameState.h"

void AGlobalGameState::PushActor(uint8 _Index, AActor* _Actor)
{
	if (false == AllActor.Contains(_Index))
	{
		AllActor.Add(_Index, NewObject<UActorGroup>());
	}

	AllActor[_Index]->Actors.Add(_Actor);
}

UActorGroup* AGlobalGameState::GetActorGroup(uint8 _Index)
{
	if (false == AllActor.Contains(_Index))
	{
		AllActor.Add(_Index, NewObject<UActorGroup>());
	}
	return AllActor[_Index];
}
