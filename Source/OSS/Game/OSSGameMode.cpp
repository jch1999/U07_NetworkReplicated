#include "OSSGameMode.h"
#include "Characters/OSSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOSSGameMode::AOSSGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
