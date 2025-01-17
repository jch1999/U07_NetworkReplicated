#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/CMenuInterface.h"
#include "CMenuBase.generated.h"

UCLASS()
class OSS_API UCMenuBase : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetOwningInstance(ICMenuInterface* InInstance);

	void StartUp();
	void ShutDown();

protected:
	ICMenuInterface* OwningInstance;
};
