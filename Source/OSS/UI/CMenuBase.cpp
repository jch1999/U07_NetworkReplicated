#include "CMenuBase.h"

void UCMenuBase::SetOwningInstance(ICMenuInterface* InInstance)
{
	OwningInstance = InInstance;
}

void UCMenuBase::StartUp()
{
	AddToViewport();

	bIsFocusable = true;


	FInputModeUIOnly InputMode;

	UWorld* World = GetWorld();
	if (!World)return;

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC) return;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetWidgetToFocus(TakeWidget());

	PC->SetInputMode(InputMode);
	PC->bShowMouseCursor = true;
}

void UCMenuBase::ShutDown()
{
	RemoveFromParent();

	bIsFocusable = false;

	FInputModeGameOnly InputMode;

	UWorld* World = GetWorld();
	if (!World)return;

	APlayerController* PC = World->GetFirstPlayerController();
	if (!PC) return;

	PC->SetInputMode(InputMode);
	PC->bShowMouseCursor = true;
}