// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public :
	void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* InputMapping;

	UFUNCTION(BlueprintCallable)
	void PlayerMove(FVector _Dir, float _Speed);

	UFUNCTION(BlueprintCallable)
	void PlayerRunIn();

	UFUNCTION(BlueprintCallable)
	void PlayerRunOut();

private:
	bool IsRun = false;
};
