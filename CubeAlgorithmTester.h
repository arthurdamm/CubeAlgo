// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CubeAlgorithm.h"
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void addAlgo(CubeAlgorithm* algo);
	void testRotateLayer0();


};
