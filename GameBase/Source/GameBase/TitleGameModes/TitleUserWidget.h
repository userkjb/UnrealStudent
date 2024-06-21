// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API UTitleUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
private :
	UFUNCTION(BlueprintCallable)
	void LoginDataInit(UDataTable* _LoginData, UComboBoxString* _Combo);

	UFUNCTION(BlueprintCallable)
	void ChangeComboBox(FString _Text);

	UFUNCTION(BlueprintCallable)
	void ServerStart();

	UFUNCTION(BlueprintCallable)
	void Connect();

	UPROPERTY(Category = "Contents", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString IPAddress = TEXT("127.0.0.1");

	UPROPERTY(Category = "Contents", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString Name = TEXT("");
};
