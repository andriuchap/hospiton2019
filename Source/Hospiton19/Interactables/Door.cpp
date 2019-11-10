// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
ADoor::ADoor(const FObjectInitializer &ObjInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootScene);
	DoorMesh->SetCollisionProfileName(FName("BlockAllDynamic"));

	HandlePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("HandlePoint"));
	HandlePoint->SetupAttachment(DoorMesh);
	HandlePoint->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	ClosedRotation = DoorMesh->GetComponentRotation();
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PullingComponent != nullptr)
	{
		FVector PullingComponentLocation = PullingComponent->GetComponentLocation();
		// Assumes that the root location of the door mesh is at the hinge!
		FVector DoorHingeLocation = DoorMesh->GetComponentLocation();
		// put all positions on the same plane.
		PullingComponentLocation.Z = DoorHingeLocation.Z = 0;

		FVector HingeToPuller = PullingComponentLocation - DoorHingeLocation + InitialOffset;
		FRotator NewDoorRotation = HingeToPuller.ToOrientationRotator();

		DoorMesh->SetWorldRotation(NewDoorRotation);
	}
}

void ADoor::StartPulling_Implementation(USceneComponent * InPullingComp)
{
	PullingComponent = InPullingComp;
	InitialOffset = HandlePoint->GetComponentLocation() - InPullingComp->GetComponentLocation();
	InitialOffset.Z = 0;
}

void ADoor::StopPulling_Implementation()
{
	PullingComponent = nullptr;
}

