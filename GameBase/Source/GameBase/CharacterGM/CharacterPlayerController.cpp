// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGM/CharacterPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterGMCharacter.h"
#include "Global/GameEnum.h"
#include "EnhancedInputSubsystems.h"

void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(InputMapping, 0);
}

void ACharacterPlayerController::PlayerMoving(FVector _Dir)
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	float Speed = 100.0f;
	if (false == IsRun)
	{
		FVector MoveVector = Speed * DeltaTime * _Dir;
		GetPawn()->AddActorLocalOffset(MoveVector);
	}
	else
	{
		FVector MoveVector = (Speed * 2.0f) * DeltaTime * _Dir;
		GetPawn()->AddActorLocalOffset(MoveVector);
	}


	if (0.0f < _Dir.X)
	{
		ChangeAnimation(EPlayerDir::Front);
	}
	else if (0.0f > _Dir.X)
	{
		ChangeAnimation(EPlayerDir::Back);
	}
	else if (0.0f < _Dir.Y)
	{
		ChangeAnimation(EPlayerDir::Right);
	}
	else if (0.0f > _Dir.Y)
	{
		ChangeAnimation(EPlayerDir::Left);
	}
	else
	{
		ChangeAnimation(EPlayerDir::Max);
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
