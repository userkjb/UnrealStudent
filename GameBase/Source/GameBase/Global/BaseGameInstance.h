// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BaseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public :

	/// <summary>
	/// NetDataTable 포인터를 받아오는 함수
	/// </summary>
	/// <param name="_Name">생성한 Net Data Table 행 이름</param>
	/// <returns>FNetDataRow</returns>
	const struct FNetDataRow* GetNetData(FName _Name);

private :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UDataTable* NetData;

	//UBaseGameInstance();
};
