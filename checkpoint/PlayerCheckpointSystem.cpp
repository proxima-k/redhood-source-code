#include "PlayerCheckpointSystem.h"
#include "CheckpointManager.h"
#include "GameFramework/GameModeBase.h"


// Sets default values for this component's properties
UPlayerCheckpointSystem::UPlayerCheckpointSystem()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UPlayerCheckpointSystem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UPlayerCheckpointSystem::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerCheckpointSystem::ResetToLastCheckpoint()
{
	// if there is a checkpoint manager
		// get the last checkpoint
	// if there is none, then reload the level or just debug log

	ACheckpointManager* CheckpointManager = ACheckpointManager::GetInstance(GetWorld());
	
	if (CheckpointManager != nullptr)
	{
		APlayerCheckpoint* LastCheckpoint = CheckpointManager->GetCurrentCheckpoint();
		if (LastCheckpoint)
		{
			// reset the player to the last checkpoint
			// GetWorld()->GetAuthGameMode()->RestartPlayerAtPlayerStart()
			// set the player's rotation to the checkpoint's rotation
			GetOwner()->SetActorLocation(LastCheckpoint->GetActorLocation());
			GetOwner()->SetActorRotation(LastCheckpoint->GetActorRotation());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No checkpoints found!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No checkpoint manager found!"));
	}
}