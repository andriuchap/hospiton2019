// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/PullableActor.h"
#include "Drawer.generated.h"

UCLASS()
class HOSPITON19_API ADrawer : public AActor, public IPullableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrawer(const FObjectInitializer &ObjInitializer);

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Drawer")
	class USceneComponent* RootScene;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Drawer")
	class UStaticMeshComponent* DrawerMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Drawer")
	class UArrowComponent* HandlePoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Drawer")
	float MaxPullDistance;

private:

	USceneComponent* PullingComponent;

	float PendingPullDistance;
	float PullDistance;
	FVector InitialOffset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void StartPulling_Implementation(USceneComponent* InPullingComp) override;

	virtual void StopPulling_Implementation() override;
};
