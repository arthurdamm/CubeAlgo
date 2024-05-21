// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "CubeActor.generated.h"

UCLASS()
class CUBEALGO_API ACubeActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeActor();

    // UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
    // int[] originalIndices;

    // UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
    // int[] indices;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
