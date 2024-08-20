// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGameMode/CharacterPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Global/GameEnum.h"

ACharacterPlayerState::ACharacterPlayerState()
{
}

void ACharacterPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACharacterPlayerState, PlayerHP);
	DOREPLIFETIME(ACharacterPlayerState, PlayerMP);
	DOREPLIFETIME(ACharacterPlayerState, AttackDamage);
	DOREPLIFETIME(ACharacterPlayerState, AbilityPower);
}

void ACharacterPlayerState::InitPlayerState()
{

}

void ACharacterPlayerState::HpUpdate_Implementation(EPlayerAttackType _AttackType, int _Damage)
{
	PlayerHP -= _Damage;
}

void ACharacterPlayerState::MpUpdate_Implementation(int _UseMPValue)
{
	PlayerMP -= _UseMPValue;
}
