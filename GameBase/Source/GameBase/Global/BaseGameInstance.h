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
	/// NetDataTable �����͸� �޾ƿ��� �Լ�
	/// </summary>
	/// <param name="_Name">������ Net Data Table �� �̸�</param>
	/// <returns>FNetDataRow</returns>
	const struct FNetDataRow* GetNetData(FName _Name);

private :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UDataTable* NetData;

	//UBaseGameInstance();
};
