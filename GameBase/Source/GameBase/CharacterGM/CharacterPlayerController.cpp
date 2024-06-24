// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGM/CharacterPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterGMCharacter.h"
#include "EnhancedInputSubsystems.h"

void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(InputMapping, 0);
}

void ACharacterPlayerController::PlayerMoving(FVector _Dir, float _Speed)
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	if (false == IsRun)
	{
		FVector MoveVector = _Speed * DeltaTime * _Dir;
		GetPawn()->AddActorLocalOffset(MoveVector);
	}
	else
	{
		FVector MoveVector = (_Speed * 2.0f) * DeltaTime * _Dir;
		GetPawn()->AddActorLocalOffset(MoveVector);
	}
}

void ACharacterPlayerController::PlayerDashStart()
{
	if (false == IsRun)
	{
		IsRun = true;
	}
}

void ACharacterPlayerController::PlayerDashEnd()
{
	if (true == IsRun)
	{
		IsRun = false;
	}
}

void ACharacterPlayerController::PlayerPitchRotation(FVector2D _RotDir)
{
	float x;
	float y;
	UKismetMathLibrary::BreakVector2D(_RotDir, x, y);

	//FRotator Value = { y, x, 0.0f };
	float DeltaTime = GetPawn()->GetWorld()->DeltaTimeSeconds;
	float TestRotSpeed = 100.0f;
	
	//FRotator InputVector = Value * DeltaTime * TestRotSpeed;

	//GetPawn()->AddActorLocalRotation(InputVector);
	float Value = y * DeltaTime * TestRotSpeed;
	GetPawn()->AddControllerPitchInput(Value);
}

void ACharacterPlayerController::PlayerYawRotation(FVector2D _RotDir)
{
	float x;
	float y;
	UKismetMathLibrary::BreakVector2D(_RotDir, x, y);
	float DeltaTime = GetPawn()->GetWorld()->DeltaTimeSeconds;
	float TestRotSpeed = 100.0f;

	GetPawn()->AddControllerYawInput(x * DeltaTime * TestRotSpeed);
}

void ACharacterPlayerController::ChangeAnimation(EPlayerDir _Animation)
{
	ACharacterGMCharacter* Ch = GetPawn<ACharacterGMCharacter>();
	Ch->ChangeAnimation(_Animation);
}
