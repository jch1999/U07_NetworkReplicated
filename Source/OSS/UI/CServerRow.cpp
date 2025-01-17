// Fill out your copyright notice in the Description page of Project Settings.


#include "CServerRow.h"
#include "Components/Button.h"
#include "CMainMenu.h"

void UCServerRow::SetUp(UCMainMenu* InParent, uint32 InIndex)
{
	Parent = InParent;
	SelfIndex = InIndex;

	RowButton->OnClicked.AddDynamic(this, &UCServerRow::OnClicked);
}

void UCServerRow::OnClicked()
{
	Parent->SetSelectedIndex(SelfIndex);
}
