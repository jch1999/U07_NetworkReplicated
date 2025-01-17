#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Interfaces/CMenuInterface.h"
#include "CGameInstance.generated.h"

class UUserWidget;
class UCMainMenu;
class FOnlineSessionSearch;

UCLASS()
class OSS_API UCGameInstance : public UGameInstance, public  ICMenuInterface
{
	GENERATED_BODY()
	
public:
	UCGameInstance();

protected:
	virtual void Init() override;

public:
	UFUNCTION(Exec)
	void Host(FString ServerName) override;

	UFUNCTION(Exec)
	void Join(uint32 Index) override;

	UFUNCTION(BlueprintCallable, Exec)
	void LoadMainMenu();

	UFUNCTION(BlueprintCallable, Exec)
	void LoadPauseMenu();

	void  StartSession();

	UFUNCTION(BlueprintCallable, Exec)
	virtual void OpenMainMenuLevel() override;
	void RefreshServerList() override;

private:
	void OnCreateSessionComplete(FName InSessionName, bool InSuccess);
	void OnDestorySessionComplete(FName InSessionName, bool InSuccess);
	void OnFindSessionComplete(bool InSuccess);
	void OnJoinSessionComplete(FName InSessionName, EOnJoinSessionCompleteResult::Type InResult);
	void OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);
	
	void CreateSession();

private:
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	UCMainMenu* MainMenu;

	TSubclassOf<UUserWidget> PauseMenuWidgetClass;

	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	FString DesiredServerName;
};
