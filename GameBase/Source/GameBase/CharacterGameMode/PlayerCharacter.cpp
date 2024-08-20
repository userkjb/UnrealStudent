// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGameMode/PlayerCharacter.h"

#include "CharacterPlayerState.h"
#include "Net/UnrealNetwork.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Global/GameEnum.h"
#include "Global/MainGameBlueprintFunctionLibrary.h"

APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SpringArm Component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->TargetArmLength = 300.0f;
	SpringArmComponent->SetWorldRotation(FRotator(-30.0, 0.0, 0.0));

	// Camera Component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Perspective);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	UMainGameBlueprintFunctionLibrary::PushActor(EObjectType::Player, this);

	// State √ ±‚»≠.
	//InitPlayerState();


}

void APlayerCharacter::AnimationEnd(FString _CurMontage)
{
	Super::AnimationEnd(_CurMontage);

}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlayerCharacter, IdleUpDown);
	DOREPLIFETIME(APlayerCharacter, IdleUp);
	DOREPLIFETIME(APlayerCharacter, IdleDown);
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::InitPlayerState_Implementation()
{
	ACharacterPlayerState* MyPlayerState = Cast<ACharacterPlayerState>(GetPlayerState());
	if (nullptr == MyPlayerState)
	{
		return;
	}

	MyPlayerState->InitPlayerState();
}
