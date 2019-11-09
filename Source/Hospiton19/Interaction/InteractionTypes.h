// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionTypes.generated.h"

UENUM(BlueprintType)
enum class EHandPose : uint8
{
	HP_Free UMETA(DisplayName = "Free"),
	HP_GrabLongbow UMETA(DisplayName= "Grab Longbow"),
	HP_GrabController UMETA(DisplayName = "Grab Controller"),
	HP_GrabSquishy UMETA(DisplayName = "Grab Squishy"),
	HP_GrabCube UMETA(DisplayName = "Grab Cube")
};