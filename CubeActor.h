// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <array>
#include "Utilities.h"
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "CubeActor.generated.h"

UCLASS()
class CUBEALGO_API ACubeActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	ACubeActor();

    UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
    TArray<int> originalIndices = {0, 0, 0};

    UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
    TArray<int> indices = {0, 0, 0};

	UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
	FString cubealgo = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rubik's Cube")
    float CubeEdgeLength = 210.0f; // Adjust size as needed

	UPROPERTY(EditAnywhere)
	FVector StartLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetIndices(int x, int y, int z);
	void UpdateIndices(int x, int y, int z);
	FString ToString();
	FString ToStringNormalized();

};
