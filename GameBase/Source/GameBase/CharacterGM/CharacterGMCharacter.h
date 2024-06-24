// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Global/GlobalAnimInstance.h"
//#include "Global/GameEnum.h"
//#include "Net/UnrealNetwork.h"
#include "CharacterGMCharacter.generated.h"

UCLASS()
class GAMEBASE_API ACharacterGMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterGMCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(Reliable, Server)
	void ChangeAnimation(EPlayerDir _Type);
	void ChangeAnimation_Implementation(EPlayerDir _Type);

private :
	UGlobalAnimInstance* AnimationContext;

	UFUNCTION(BlueprintCallable)
	void ChangeSlotMesh(EPlayerItemSlot _Slot, UStaticMesh* _Mesh);


	UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> ItemMeshs;

	//UPROPERTY(Category = "Contents", Replicated, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPROPERTY(Category = "Contents", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EPlayerDir AniValue;
};
