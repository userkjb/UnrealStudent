// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGameMode/CharacterPlayerController.h"
#include "CharacterDefaultCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputSubsystems.h"

ACharacterPlayerController::ACharacterPlayerController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void ACharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(InputMapping, 0);
}

void ACharacterPlayerController::PlayerMove(const FInputActionValue& InputValue)
{
	FVector2D MovementVector = InputValue.Get<FVector2D>();

	if (MovementVector.X != 0)
	{
		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.X);
	}

	if (MovementVector.Y != 0)
	{
		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetRightVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.Y);
	}

	ACharacterDefaultCharacter* Ch = GetPawn<ACharacterDefaultCharacter>();
}

void ACharacterPlayerController::PlayerRotation(const FInputActionValue& InputValue)
{
	FVector2D MouseXY = InputValue.Get<FVector2D>();
	AddYawInput(MouseXY.X);
	AddPitchInput(-MouseXY.Y);
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
