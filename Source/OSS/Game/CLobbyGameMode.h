#pragma once

#include "CoreMinimal.h"
#include "Game/OSSGameMode.h"
#include "CLobbyGameMode.generated.h"

UCLASS()
class OSS_API ACLobbyGameMode : public AOSSGameMode
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;

private:
	void StartGame();

private:
	uint32 NumberOfPlayers;

	FTimerHandle GameStartTimer;
};
