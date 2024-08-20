// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GlobalAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBASE_API UGlobalAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	template<typename EnumType>
	void ChangeAnimation(EnumType Key)
	{
		ChangeAnimation(static_cast<uint8>(Key));
	}

	void ChangeAnimation(uint8 Key);

	template<typename EnumType>
	void PushAnimation(EnumType _Key, UAnimMontage* _Montage)
	{
		PushAnimation(static_cast<uint8>(_Key), _Montage)
	}

	void PushAnimation(uint8 _Key, UAnimMontage* _Montage);

	//uint8 GetAnimationKey(class UAnimMontage* _AnimMontage);

private :
	UPROPERTY()
	TMap<uint8, UAnimMontage*> AnimMontages;
};
