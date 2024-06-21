// Fill out your copyright notice in the Description page of Project Settings.


#include "GB/BaseCharacter.h"
#include "Actor/Bullet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::SpawnBullet(FTransform _Transform)
{
	
	UClass* bullet = ABullet::StaticClass();
	FTransform Trans;
	Trans.SetLocation(FVector(0.0f, 0.0f, 100.0f));

	GetWorld()->SpawnActor<AActor>(bullet, Trans);
}

