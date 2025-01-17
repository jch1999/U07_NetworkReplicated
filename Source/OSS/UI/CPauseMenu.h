#pragma once

#include "CoreMinimal.h"
#include "CMenuBase.h"
#include "CPauseMenu.generated.h"

class UButton;

UCLASS()
class OSS_API UCPauseMenu : public UCMenuBase
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	UFUNCTION()
	void OnCancelPressed();

	UFUNCTION()
	void OnQuitPressed();

private:
	UPROPERTY(meta = (BindWidget))
	UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;
};
