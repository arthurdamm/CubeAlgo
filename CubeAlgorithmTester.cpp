// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeAlgorithmTester.h"

// Sets default values
ACubeAlgorithmTester::ACubeAlgorithmTester()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACubeAlgorithmTester::BeginPlay()
{
	Super::BeginPlay();

	AActor* DummyActor = NewObject<AActor>();
	CubeAlgorithm algo1(DummyActor);
	
	addAlgo(&algo1);
	testRotateLayer0();
	
}

// Called every frame
void ACubeAlgorithmTester::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeAlgorithmTester::addAlgo(CubeAlgorithm* algo)
{
	algos.Add(algo);
}

void ACubeAlgorithmTester::testRotateLayer0()
{
	UE_LOG(LogTemp, Warning, TEXT("ACubeAlgorithmTester::testRotateLayer0 start"));	
	for (auto* algo : algos) {
		algo->rotateLayer(0, 1);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *algo->ToString());
	}
	UE_LOG(LogTemp, Warning, TEXT("ACubeAlgorithmTester::testRotateLayer0 stop"));	
}
