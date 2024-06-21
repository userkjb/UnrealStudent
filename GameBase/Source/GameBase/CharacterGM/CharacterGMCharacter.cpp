// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGM/CharacterGMCharacter.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACharacterGMCharacter::ACharacterGMCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ACharacterGMCharacter::BeginPlay()
{
	Super::BeginPlay();

	USpringArmComponent* SpringArm = GetComponentByClass<USpringArmComponent>();
	SpringArm->bUsePawnControlRotation = true;
}

// Called every frame
void ACharacterGMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterGMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

