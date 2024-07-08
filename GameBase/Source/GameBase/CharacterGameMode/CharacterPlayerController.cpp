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

void ACharacterPlayerController::PlayerMove(FVector _Dir, float _Speed)
{
	FRotator Rotator = GetControlRotation();
	FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
	GetPawn()->AddMovementInput(_Dir);

	ACharacterDefaultCharacter* Ch = GetPawn<ACharacterDefaultCharacter>();
}

void ACharacterPlayerController::PlayerRotation(FVector _Dir, float _RotSpeed)
{
	//AddYawInput(_Dir.X);
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
