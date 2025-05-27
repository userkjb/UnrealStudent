// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"

const FNetDataRow* UMainGameInstance::GetNetData(FName _Name)
{
    if (nullptr == NetDataTable)
    {
        // BP_GameMode 에서 BP_DataTable을 넣어 줘야 함.
        UE_LOG(LogTemp, Fatal, TEXT("%S(%u) > if (nullptr == NetDataTable)"), __FUNCTION__, __LINE__);
    }

    FNetDataRow* Data = NetDataTable->FindRow<FNetDataRow>(_Name, nullptr);

    if (nullptr == Data)
    {
        UE_LOG(LogTemp, Error, TEXT("%S(%u) > %s Name Data Is Nullptr"), __FUNCTION__, __LINE__, *_Name.ToString());
        return nullptr;
    }

    return Data;
}
