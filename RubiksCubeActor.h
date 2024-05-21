// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <cmath>

#include "CubeAlgorithm.h"
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "Containers/Queue.h"
#include "CubeActor.h"
#include "RubiksCubeActor.generated.h"

#define CUBE_MESH TEXT("StaticMesh'/Game/SM_RubiksCube.SM_RubiksCube'")

UCLASS()
class CUBEALGO_API ARubiksCubeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARubiksCubeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Base unit cube template
    UPROPERTY(EditAnywhere)
    UStaticMesh* CubeMesh;

    // Cube edge length constant
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rubik's Cube")
    float CubeEdgeLength = 210.0f; // Adjust size as needed

	UPROPERTY(EditAnywhere)
	FVector StartLocation;

    UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
    float MaxRotationAngle = 90;

    UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
    float rotationDelay = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rubik's Cube")
    TArray<int> InstantRotations;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rubik's Cube")
    TArray<int> AnimatedRotations;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rubik's Cube")
    bool loopAnimation = true;

	ACubeActor* Cubes[3][3][3];

    std::vector<ACubeActor*> CubesVector;
    FVector NormalsAtLayer[9];
    FVector CentersAtLayer[9];
    TQueue<int> RotationsQueue;



private:
    bool bIsRotating = false;
    float RotationAngle = 0.0f;
    float RotationSpeed = 90.0f; // degrees per second
    FVector RotationAxis = FVector(0, 0, 1); // Default Z-axis
    int LayerToRotate = 1; // Example: middle layer
    FQuat TargetRotation;
    double StartTime = 0;

	CubeAlgorithm algo = nullptr;


public:
    void StartRotation(int LayerIndex);
    void MaybeRotate(float DeltaTime);
    void DrawCubeFacingLine(FVector &EndPoint, AStaticMeshActor *CubeToRotate);
    void DrawNormalLine(FVector &EndPoint, FVector &RotationCenter);
    void PopulateCubesGrid();
    std::vector<AStaticMeshActor *> GetCubesInLayer(int layerIndex);
    int dtoi(double n);
    void RecalculateRotationCenters();
	void print();
};
