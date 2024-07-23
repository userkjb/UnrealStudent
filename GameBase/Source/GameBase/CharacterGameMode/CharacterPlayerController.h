// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharacterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API ACharacterPlayerController : public APlayerController
{
	GENERATED_BODY()

public :
	ACharacterPlayerController(const FObjectInitializer& ObjectInitializer);

protected :
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* InputMapping;

	UFUNCTION(BlueprintCallable)
	void PlayerMove(const FInputActionValue& InputValue);

	UFUNCTION(BlueprintCallable)
	void PlayerRotation(FVector _Dir, float _RotSpeed);

	UFUNCTION(BlueprintCallable)
	void PlayerRunIn();

	UFUNCTION(BlueprintCallable)
	void PlayerRunOut();

	UFUNCTION(BlueprintCallable)
	void MouseLeftButton();

	UFUNCTION(BlueprintCallable)
	void MouseRightButton();

private:
	UPROPERTY()
	bool IsRun = false;
};
