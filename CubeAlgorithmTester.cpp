// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeAlgorithmTester.h"

// Sets default values
ACubeAlgorithmTester::ACubeAlgorithmTester()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(CUBE_MESH);
    if (MeshObj.Succeeded())
    {
        CubeMesh = MeshObj.Object;
        UE_LOG(LogTemp, Warning, TEXT("MeshObj: SUCCEEDED!"));
    } else {
		UE_LOG(LogTemp, Warning, TEXT("MeshObj: FAILED"));
	}
}

// Called when the game starts or when spawned
void ACubeAlgorithmTester::BeginPlay()
{
	Super::BeginPlay();

	AActor* DummyActor = NewObject<AActor>();
	CubeAlgorithm algo1(DummyActor);
	
	addAlgo(&algo1);
	testRotateLayer0();
	testQuatRotation();

	spawnCube();
	
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

void ACubeAlgorithmTester::testQuatRotation()
{
	FVector vectorToRotate = FVector(1, 0, 0);
	FVector RotationAxis(1, 0, 0);
	double RotationDegreesRadians = PI / 2;
	FQuat QuatRotation = FQuat(RotationAxis, RotationDegreesRadians);
	FVector rotatedVector = QuatRotation.RotateVector(vectorToRotate);
	UE_LOG(LogTemp, Warning, TEXT("rotatedVector: %s"), *rotatedVector.ToString());

	FRotator rotation = FRotator(0, 0, 0);
	FRotator newRotation = (FQuat(rotation) * QuatRotation).Rotator();
	UE_LOG(LogTemp, Display, TEXT("newRotation: %s"), *newRotation.ToString());
}

ACubeActor* ACubeAlgorithmTester::spawnCube(FVector location, FVector facing, FRotator rotation)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ACubeActor* NewCube = GetWorld()->SpawnActor<ACubeActor>(ACubeActor::StaticClass(), location, FRotator::ZeroRotator, SpawnParams);

	if (!NewCube || !NewCube->GetStaticMeshComponent())
	{
		UE_LOG(LogTemp, Error, TEXT("ACubeAlgorithmTester::spawnCube failed!"));
		return nullptr;
	}
	NewCube->StartLocation = location;
	NewCube->CubeEdgeLength = CUBE_EDGE_LENGTH;
	NewCube->GetStaticMeshComponent()->SetStaticMesh(CubeMesh);  // Referencing CubeMesh here
	NewCube->GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);  // Set mobility to Movable
	NewCube->SetActorRotation(rotation);
	return NewCube;
}