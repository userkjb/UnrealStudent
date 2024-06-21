// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/BaseGameInstance.h"
#include "DataTable/NetDataRow.h"

const FNetDataRow* UBaseGameInstance::GetNetData()
{
	if (nullptr == NetData)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == NetDataRow)"), __FUNCTION__, __LINE__);
	}

	FNetDataRow* Data = NetData->FindRow<FNetDataRow>(TEXT(""), nullptr);
	if (nullptr == Data)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == NetDataRow)"), __FUNCTION__, __LINE__);
		return nullptr;
	}
	return Data;
}
