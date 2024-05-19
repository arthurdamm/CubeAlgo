// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	UE_LOG(LogTemp, Error, TEXT("AMyActor()"));
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(CUBE_MESH);
	if (MeshObj.Succeeded()) {
		CubeMesh = MeshObj.Object;
		UE_LOG(LogTemp, Warning, TEXT("MeshObj: SUCCEEDED"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("MeshObj: FAILED"));
	}

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("AMyActor::BeginPlay()"));
	StartLocation = GetActorLocation();

	CubeAlgorithm cubes;


	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("AMyActor::tick()"));


}

