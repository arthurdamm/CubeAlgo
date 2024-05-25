// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeActor.h"

// Sets default values
ACubeActor::ACubeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACubeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeActor::SetOriginalIndices(int x, int y, int z) {
	originalIndices.Empty();
	originalIndices.Append({x, y, z});
}

void ACubeActor::SetIndices(int x, int y, int z)
{
	indices.Empty();
	indices.Append({x, y, z});
}

void ACubeActor::UpdateIndices(int x, int y, int z)
{
	indices.Empty();
	indices.Append({x, y, z});
}

FString ACubeActor::ToString() {
	FVector location = GetActorLocation();
	FVector forwardVector = GetActorForwardVector();
	FRotator rotation = GetActorRotation();
	return FString::Printf(
            TEXT("<L:(%.2f, %.2f, %.2f) F:(%.2f, %.2f, %.2f) R:(%.2f, %.2f, %.2f) [%d][%d][%d](%d][%d][%d])>, "),
            location.X, location.Y, location.Z,
            forwardVector.X, forwardVector.Y, forwardVector.Z,
            rotation.Pitch, rotation.Yaw, rotation.Roll,
            indices[0], indices[1], indices[2],
            originalIndices[0], originalIndices[1], originalIndices[2]
        );
}

FString ACubeActor::ToStringNormalized() {
	FVector gridPosition = (GetActorLocation() - StartLocation) / CubeEdgeLength;
    float x = dtoi(gridPosition.X), y = dtoi(gridPosition.Y), z = dtoi(gridPosition.Z);
	// UE_LOG(LogTemp, Error, TEXT("%s %d %d %d (%.2f, %.2f, %.2f)"), *gridPosition.ToString(), x, y, z, x, y, z);
	FVector location = GetActorLocation();
	FVector forwardVector = GetActorForwardVector();
	FRotator rotation = GetActorRotation();
	return FString::Printf(
            TEXT("<L:(%.2f, %.2f, %.2f) F:(%.2f, %.2f, %.2f) R:(%.2f, %.2f, %.2f) [%d][%d][%d](%d][%d][%d])>, "),
            x, y, z,
            forwardVector.X, forwardVector.Y, forwardVector.Z,
            rotation.Pitch, rotation.Yaw, rotation.Roll,
            indices[0], indices[1], indices[2],
            originalIndices[0], originalIndices[1], originalIndices[2]
        );
}