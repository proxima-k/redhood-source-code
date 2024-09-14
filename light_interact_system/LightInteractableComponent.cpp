#include "LightInteractableComponent.h"

// Sets default values for this component's properties
ULightInteractableComponent::ULightInteractableComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void ULightInteractableComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ULightInteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}