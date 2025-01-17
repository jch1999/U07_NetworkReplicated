#include "CMovingPlatform_Trigger.h"
#include "Components/BoxComponent.h"
#include "CMovingPlatform.h"

ACMovingPlatform_Trigger::ACMovingPlatform_Trigger()
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>("BoxComp");
	RootComponent = BoxComp;
}

void ACMovingPlatform_Trigger::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &ACMovingPlatform_Trigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACMovingPlatform_Trigger::ActorEndOverlap);
}

void ACMovingPlatform_Trigger::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	for (const auto& Platform : PlatformsToTrigger)
	{
		Platform->IncreaseActiveCount();
	}
}

void ACMovingPlatform_Trigger::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	for (const auto& Platform : PlatformsToTrigger)
	{
		Platform->DecreaseActiveCount();
	}
}

