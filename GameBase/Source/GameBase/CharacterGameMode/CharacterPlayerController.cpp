// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGameMode/CharacterPlayerController.h"
#include "CharacterDefaultCharacter.h"
#include "EnhancedInputSubsystems.h"

void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(InputMapping, 0);
}

void ACharacterPlayerController::PlayerMove(FVector _Dir, float _Speed)
{
	GetPawn()->AddMovementInput(_Dir);

	ACharacterDefaultCharacter* Ch = GetPawn<ACharacterDefaultCharacter>();
}

void ACharacterPlayerController::PlayerRotation(FVector _Dir, float _RotSpeed)
{
	AddYawInput(_Dir.X);
	AddPitchInput(_Dir.Y);
}

void ACharacterPlayerController::PlayerRunIn()
{
	IsRun = true;
}

void ACharacterPlayerController::PlayerRunOut()
{
	IsRun = false;
}

void ACharacterPlayerController::MouseLeftButton()
{
}

void ACharacterPlayerController::MouseRightButton()
{
}
