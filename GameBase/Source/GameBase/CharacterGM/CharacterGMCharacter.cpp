// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGM/CharacterGMCharacter.h"
#include "Global/GameEnum.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACharacterGMCharacter::ACharacterGMCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UEnum* SlotEnum = StaticEnum<EPlayerItemSlot>();
	for (size_t i = 0; i < static_cast<size_t>(EPlayerItemSlot::SlotMax); i++)
	{
		FString Name = SlotEnum->GetNameStringByValue(i);

		//UStaticMeshComponent* NewSlotMesh = CreateDefaultSubobject<UStaticMeshComponent>(*Name);
		UStaticMeshComponent* NewSlotMesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(*Name);
		NewSlotMesh->SetupAttachment(GetMesh(), *Name);

		ItemMeshs.Push(NewSlotMesh);
	}

	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void ACharacterGMCharacter::BeginPlay()
{
	Super::BeginPlay();

	AnimationContext = Cast<UGlobalAnimInstance>(GetMesh()->GetAnimInstance());

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

void ACharacterGMCharacter::ChangeAnimation_Implementation(EPlayerDir _Type)
{
	AniValue = _Type;
}

void ACharacterGMCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACharacterGMCharacter, AniValue);
}

void ACharacterGMCharacter::ChangeSlotMesh(EPlayerItemSlot _Slot, UStaticMesh* _Mesh)
{
	uint8 SlotIndex = static_cast<uint8>(_Slot);
	if (ItemMeshs.Num() <= SlotIndex)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (ItemMeshs.Num() <= static_cast<uint8>(_Slot))"), __FUNCTION__, __LINE__);
		return;
	}

	ItemMeshs[SlotIndex]->SetStaticMesh(_Mesh);
}

