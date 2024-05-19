// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CubeAlgorithm.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

#define CUBE_MESH TEXT("StaticMesh'/Game/SM_RubiksCube.SM_RubiksCube'")


UCLASS()
class CUBEALGO_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	
	UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Rubik's Cube")
	UStaticMesh* CubeMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
