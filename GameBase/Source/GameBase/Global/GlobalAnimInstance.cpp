// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalAnimInstance.h"

void UGlobalAnimInstance::ChangeAnimation(uint8 Key)
{
	if (false == AnimMontages.Contains(Key))
	{
		return;
	}

	UAnimMontage* NextMontage = AnimMontages[Key];

	if (nullptr == NextMontage)
	{
		return;
	}

	UAnimMontage* CurMontage = GetCurrentActiveMontage();
	if (CurMontage != NextMontage)
	{
		//uint8 PrevKey = GetAnimationKey(CurMontage);

		Montage_Play(NextMontage);
	}
}

void UGlobalAnimInstance::PushAnimation(uint8 _Key, UAnimMontage* _Montage)
{
	if (true == AnimMontages.Contains(_Key))
	{
		return;
	}

	AnimMontages.Add(_Key, _Montage);
}

//uint8 UGlobalAnimInstance::GetAnimationKey(UAnimMontage* _AnimMontage)
//{
//	for (TPair<uint8, class UAnimMontage*> Pair : AnimMontages)
//	{
//		if (Pair.Value == _AnimMontage)
//		{
//			return Pair.Key;
//		}
//	}
//	return -1;
//}
