// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/PullableActor.h"
#include "Door.generated.h"

UCLASS()
class HOSPITON19_API ADoor : public AActor, public IPullableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor(const FObjectInitializer &ObjInitializer);

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Door")
	class USceneComponent* RootScene;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Door")
	class UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Door")
	class UArrowComponent* HandlePoint;

private:
	USceneComponent* PullingComponent;

	FRotator ClosedRotation;
	FVector DoorHandleOffset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void StartPulling_Implementation(USceneComponent* InPullingComp) override;

	virtual void StopPulling_Implementation() override;

};