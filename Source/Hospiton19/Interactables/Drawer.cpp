// Fill out your copyright notice in the Description page of Project Settings.


#include "Drawer.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Engine/Engine.h"

// Sets default values
ADrawer::ADrawer(const FObjectInitializer &ObjInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PullDistance = 0.0F;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	DrawerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DrawerMesh"));
	DrawerMesh->SetupAttachment(RootScene);
	DrawerMesh->SetCollisionProfileName(FName("BlockAllDynamic"));

	HandlePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("HandlePoint"));
	HandlePoint->SetupAttachment(DrawerMesh);
	HandlePoint->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void ADrawer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADrawer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PullingComponent)
	{
		FVector DrawerMeshForward = DrawerMesh->GetRightVector();
		FVector PullAmount = PullingComponent->GetComponentLocation() - RootScene->GetComponentLocation() + InitialOffset;
		FVector PullDirection = PullAmount;
		PullDirection.Normalize();
		//PullAmount.Z = 0;
		PullAmount = PullAmount.ProjectOnTo(DrawerMeshForward);
		PendingPullDistance = PullAmount.Size() * FVector::DotProduct(DrawerMeshForward, PullDirection);

		float Distance = FMath::Clamp<float>(PullDistance + PendingPullDistance, 0, MaxPullDistance);

		DrawerMesh->SetRelativeLocation(FVector(0, Distance, 0));
	}
}

void ADrawer::StartPulling_Implementation(USceneComponent * InPullingComp)
{
	PullingComponent = InPullingComp;
	InitialOffset = RootScene->GetComponentLocation() - InPullingComp->GetComponentLocation();
}

void ADrawer::StopPulling_Implementation()
{
	PullingComponent = nullptr;
	PullDistance += PendingPullDistance;
}

