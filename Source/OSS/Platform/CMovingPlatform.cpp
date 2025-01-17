#include "CMovingPlatform.h"

ACMovingPlatform::ACMovingPlatform()
{
	// Todo. Enable Tick
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

	Speed = 100.0f;
	TargetLS = FVector(0, 0, 150);
}

void ACMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicatingMovement(true);
	}

	StartWS = GetActorLocation();
	TargetWS = GetTransform().TransformPosition(TargetLS);
}

void ACMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveCount > 0)
	{
		if (HasAuthority())
		{

			float TotalDistance = (StartWS - TargetWS).Size();

			FVector CurrentLocation = GetActorLocation();
			float AwayFromStart = (CurrentLocation - StartWS).Size();

			if (AwayFromStart >= TotalDistance)
			{
				FVector Temp = StartWS;
				StartWS = TargetWS;
				TargetWS = Temp;
			}

			FVector Direction = (TargetWS - StartWS).GetSafeNormal();
			CurrentLocation += Direction * Speed * DeltaTime;

			SetActorLocation(CurrentLocation);
		}
	}
}

void ACMovingPlatform::IncreaseActiveCount()
{
	ActiveCount++;
}

void ACMovingPlatform::DecreaseActiveCount()
{
	if (ActiveCount > 0)
	{
		ActiveCount--;
	}
}
