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
	void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* InputMapping;

	UFUNCTION(BlueprintCallable)
	void PlayerMoving(FVector _Dir, float _Speed);

	UFUNCTION(BlueprintCallable)
	void PlayerDashStart();

	UFUNCTION(BlueprintCallable)
	void PlayerDashEnd();

	UFUNCTION(BlueprintCallable)
	void PlayerPitchRotation(FVector2D _RotDir);

	UFUNCTION(BlueprintCallable)
	void PlayerYawRotation(FVector2D _RotDir);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsRun = false;

private:
	UFUNCTION(BlueprintCallable)
	void ChangeAnimation(EPlayerDir _Animation);
};
