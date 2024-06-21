// Fill out your copyright notice in the Description page of Project Settings.


#include "GB/BasePlayerController.h"
#include "EnhancedInputSubsystems.h"
//#include "EnhancedInputComponent.h"

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	//UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(InputMapping, 0);
}

void ABasePlayerController::PlayerMove(FVector _Dir, float _Speed)
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

void ABasePlayerController::PlayerRunIn()
{
	if (false == IsRun)
	{
		IsRun = true;
	}
}

void ABasePlayerController::PlayerRunOut()
{
	if (true == IsRun)
	{
		IsRun = false;
	}
}
