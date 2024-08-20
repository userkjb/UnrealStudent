// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalAnimInstance.h"

void UGlobalAnimInstance::ChangeAnimation(uint8 Key)
{

}

void UGlobalAnimInstance::PushAnimation(uint8 _Key, UAnimMontage* _Montage)
{
	if (true == AnimMontages.Contains(_Key))
	{
		return;
	}

	AnimMontages.Add(_Key, _Montage);
}
