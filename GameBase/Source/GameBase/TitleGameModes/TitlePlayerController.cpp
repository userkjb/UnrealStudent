// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameModes/TitlePlayerController.h"
#include "EnhancedInputSubsystems.h"

void ATitlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	//UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(InputMapping, 0);
}

void ATitlePlayerController::PlayerMove(FVector _Dir, float _Speed)
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

void ATitlePlayerController::PlayerRunIn()
{
	if (false == IsRun)
	{
		IsRun = true;
	}
}

void ATitlePlayerController::PlayerRunOut()
{
	if (true == IsRun)
	{
		IsRun = false;
	}
}
