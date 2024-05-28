// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CubeAlgorithm.h"
#include "CubeActor.h"
#include "RubiksCubeActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeAlgorithmTester.generated.h"

UCLASS()
class CUBEALGO_API ACubeAlgorithmTester : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeAlgorithmTester();
	TArray<CubeAlgorithm*> algos = {};

	UPROPERTY(EditAnywhere)
    UStaticMesh* CubeMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void addAlgo(CubeAlgorithm* algo);
	void testRotateLayer0();
	void testQuatRotation();
	ACubeActor* spawnCube(FVector location=FVector(0, 0, 0), FVector facing=FVector(1, 0 , 0), FRotator rotation=FRotator(0, 0, 0));


};
