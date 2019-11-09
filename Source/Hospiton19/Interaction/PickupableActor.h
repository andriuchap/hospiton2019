// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InputCoreTypes.h"
#include "InteractionTypes.h"
#include "PickupableActor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPickupableActor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HOSPITON19_API IPickupableActor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Pickup(class USceneComponent* InAttachTarget, USceneComponent* InHandMesh, EControllerHand InHandType, bool InFlipSocket);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Drop();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	EHandPose SetGripType();
};
