#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

UINTERFACE()
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

class GP3_TEAM03_API IInteractableInterface
{
	GENERATED_BODY()

public:
    // can be added in Unreal Engine Editor and implemented in Blueprint
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact(AActor* Interactor, UPlayerInteractSystem* InteractSystem);
};
