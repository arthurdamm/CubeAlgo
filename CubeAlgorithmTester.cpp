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
	// testRotateLayer0();
	// testQuatRotation();
	// testQuatRotationRelative();
	testQuatRotationEuclid();
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
	double RotationDegreesRadians = PI / 2;
	FQuat QuatRotationAroundX = FQuat(FVector(1, 0, 0), RotationDegreesRadians);
	FQuat QuatRotationAroundY = FQuat(FVector(0, 1, 0), -RotationDegreesRadians);
	FQuat QuatRotationAroundZ = FQuat(FVector(0, 0, 1), RotationDegreesRadians);
	FVector facing(1, 0, 0);

	FVector rotatedVector = QuatRotationAroundY.RotateVector(vectorToRotate);
	UE_LOG(LogTemp, Warning, TEXT("rotatedVector: %s"), *rotatedVector.ToString());
	FRotator rotationAfterY = (FQuat(FRotator(0, 0, 0)) * QuatRotationAroundY).Rotator();
	UE_LOG(LogTemp, Display, TEXT("rotationAfterY: %s"), *rotationAfterY.ToString());

	spawnCube(FVector(0, 0, 500), facing, FRotator(0, 0, 0));
	spawnCube(FVector(0, 0, 1000), facing, QuatRotationAroundX.Rotator());
	spawnCube(FVector(0, 0, 1500), facing, QuatRotationAroundY.Rotator());
	spawnCube(FVector(0, 0, 2000), facing, QuatRotationAroundZ.Rotator());

	// FQuat QuatRotationAroundZ = FQuat(FVector(1, 0, 0), RotationDegreesRadians);
	// FQuat QuatRotationAroundX = FQuat(FVector(0, 0, 1), RotationDegreesRadians);
	// spawnCube(FVector(0, 500, 500), facing, (QuatRotationAroundX).Rotator());
	spawnCube(FVector(0, 1000, 500), facing, (QuatRotationAroundX * QuatRotationAroundY).Rotator());
	spawnCube(FVector(0, 1500, 500), facing, (QuatRotationAroundX * QuatRotationAroundZ).Rotator());
	spawnCube(FVector(0, 2000, 500), facing, (QuatRotationAroundY * QuatRotationAroundZ).Rotator());

	spawnCube(FVector(0, 500, 1000), facing, FRotator(0, 0, 90));
	spawnCube(FVector(0, 1000, 1000), facing, FRotator(90, 0, 90));
	spawnCube(FVector(0, 1500, 1000), facing, FRotator(90, 90, 90));


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

void ACubeAlgorithmTester::testQuatRotationRelative()
{
	FVector facing(1, 0, 0);

	// Define the original rotations
	FQuat QuatRotationAroundX = FQuat(FVector(1, 0, 0), PI / 2);
	FQuat QuatRotationAroundY = FQuat(FVector(0, 1, 0), -PI / 2);

	auto* defaultCube = spawnCube(FVector(0, 0, 500), facing, FRotator());
	DrawActorFacingLine(defaultCube);
	UE_LOG(LogTemp, Warning, TEXT("defaultCube: facing:%s"), *defaultCube->GetActorForwardVector().ToString());

	facing = defaultCube->GetActorForwardVector();

	// First cube - rotated around X globally
	auto* defaultCubeAroundX = spawnCube(FVector(0, 0, 1000), facing, QuatRotationAroundX.Rotator());
	DrawActorFacingLine(defaultCubeAroundX);
	UE_LOG(LogTemp, Warning, TEXT("defaultCubeAroundX: facing:%s"), *defaultCubeAroundX->GetActorForwardVector().ToString());

	// To rotate the next cube around Y globally after X rotation,
	// we must reset to the original facing before applying Y rotation.
	FVector newFacingAfterX = QuatRotationAroundX.RotateVector(facing);
	FQuat QuatRotationAroundYGlobal = FQuat(FVector(0, 1, 0), -PI / 2);
	FVector finalFacing = QuatRotationAroundYGlobal.RotateVector(newFacingAfterX);
	FRotator finalRotator = finalFacing.Rotation();

	auto* defaultCubeAroundXY = spawnCube(FVector(0, 0, 1500), facing, finalRotator);
	DrawActorFacingLine(defaultCubeAroundXY);
	UE_LOG(LogTemp, Warning, TEXT("defaultCubeAroundXY: facing:%s"), *defaultCubeAroundXY->GetActorForwardVector().ToString());
	UE_LOG(LogTemp, Warning, TEXT("facing: %s newFacingAfterX: %s finalFacing: %s "), *facing.ToString(), *newFacingAfterX.ToString(), *finalFacing.ToString());

}

void ACubeAlgorithmTester::testQuatRotationEuclid()
{
	UE_LOG(LogTemp, Warning, TEXT("testQuatRotationEuclid()"));
	FVector facing(1, 0, 0);

	auto* defaultCube = spawnCube(FVector(0, 0, 500), facing, FRotator());
	DrawActorFacingLine(defaultCube);
	UE_LOG(LogTemp, Warning, TEXT("defaultCube: facing:%s"), *defaultCube->GetActorForwardVector().ToString());

	auto* defaultCubeAroundX = spawnCube(FVector(0, 0, 1000), facing, FRotator(0, 0, 90));
	DrawActorFacingLine(defaultCubeAroundX);
	UE_LOG(LogTemp, Warning, TEXT("defaultCubeAroundX: facing:%s"), *defaultCubeAroundX->GetActorForwardVector().ToString());

	auto* defaultCubeAroundXY = spawnCube(FVector(0, 0, 1500), facing, FRotator(0, 0, 90) + FRotator(90, 0, 0));
	DrawActorFacingLine(defaultCubeAroundXY);
	UE_LOG(LogTemp, Warning, TEXT("defaultCubeAroundXY: facing:%s"), *defaultCubeAroundXY->GetActorForwardVector().ToString());

	auto* defaultCubeAroundXYZ = spawnCube(FVector(0, 0, 2000), facing, FRotator(0, 0, 90) + FRotator(90, 0, 0) + FRotator(0, 90, 0));
	DrawActorFacingLine(defaultCubeAroundXYZ);
	UE_LOG(LogTemp, Warning, TEXT("defaultCubeAroundXY: facing:%s"), *defaultCubeAroundXYZ->GetActorForwardVector().ToString());

}

void ACubeAlgorithmTester::DrawActorFacingLine(AStaticMeshActor *actor)
{
    FVector EndPoint = actor->GetActorLocation() + actor->GetActorForwardVector() * 200.0f; // Extend the line along the rotation axis
    DrawDebugLine(
        GetWorld(),
        actor->GetActorLocation(),
        EndPoint,
        FColor::Red,
        false, // Persistent lines
        100,   // Lifetime
        0,     // Depth priority
        10.0   // Thickness
    );
}