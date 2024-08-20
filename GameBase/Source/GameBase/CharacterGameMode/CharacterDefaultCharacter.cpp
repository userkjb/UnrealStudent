// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterDefaultCharacter.h"

#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACharacterDefaultCharacter::ACharacterDefaultCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
}

// Called when the game starts or when spawned
void ACharacterDefaultCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterDefaultCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterDefaultCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

