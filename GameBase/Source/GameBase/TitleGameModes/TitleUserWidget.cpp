// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameModes/TitleUserWidget.h"
#include "Components/ComboBoxString.h"
#include "DataTable/NetDataRow.h"
#include "Global/BaseGameInstance.h"

void UTitleUserWidget::LoginDataInit(UDataTable* _LoginData, UComboBoxString* _Combo)
{
	TArray<FNetDataRow*> arr;

	_LoginData->GetAllRows<FNetDataRow>(TEXT("GetAllRows"), arr);

	if (true == arr.IsEmpty())
	{
		return;
	}

	for (size_t i = 0; i < arr.Num(); i++)
	{
		FNetDataRow* Data = arr[i];
		Data->Name;
		Data->IP;

		FString Option = FString::Printf(TEXT("[%s][%s]"), *Data->Name, *Data->IP);
		_Combo->AddOption(Option);
	}

	_Combo->SetSelectedIndex(0);
}

void UTitleUserWidget::ChangeComboBox(FString _Text)
{
	_Text.RemoveAt(0);
	_Text.RemoveAt(_Text.Len() - 1);

	// _Text.ParseIntoArray()
	FString GetName;
	FString IP;
	_Text.Split(TEXT("]["), &GetName, &IP);

	IPAddress = IP;
}

void UTitleUserWidget::ServerStart()
{
	UBaseGameInstance* Inst = GetGameInstance<UBaseGameInstance>();

	if (nullptr == Inst)
	{
		return;
	}

	//Inst->
}

void UTitleUserWidget::Connect()
{

}
