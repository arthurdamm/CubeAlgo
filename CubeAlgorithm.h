// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Utilities.h"
#include "CoreMinimal.h"
#include "Cube.h"

#define N 3
#define MAX_LAYERS N*N



/**
 * 
 */
class CUBEALGO_API CubeAlgorithm
{
private:
	

	FRotator layerToRotator[MAX_LAYERS];
	AActor* actor;
	void populateRotators();
	std::vector<Cube> getLayer(int layer);

	
public:
	CubeAlgorithm(AActor* actor);
	~CubeAlgorithm();
	void print();
	FString ToString();
	FString ToStringNormalized();
	void init();
	// rotates given layer 90 degrees in positive or negative direction
	void rotateLayer(int layer, int direction);
	FVector getRotationAxisForLayer(int layer);
	FVector getCenterForLayer(int layer);

	// 3D N^3 sized grid containing forward vectors at each (x,y,z)
	// position (small cube) in the large rubik's cube
	Cube cubes[N][N][N];
};
