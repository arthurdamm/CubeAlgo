// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define N 3
#define MAX_LAYERS N*N

struct Cube {
	FVector location;
	FVector facing;
	FRotator rotation;
	int64 indices[3];
	Cube(): location(0, 0, 0), facing(1, 0, 0), indices{0} {}
	FString ToString() {
		return "<L:(" + location.ToString() + ") R:(" + rotation.ToString()
			+ ") [" + FString::FromInt(indices[0]) + "][" + FString::FromInt(indices[1])
			+ "][" + FString::FromInt(indices[2]) + "]>, ";
	}
};

/**
 * 
 */
class CUBEALGO_API CubeAlgorithm
{
private:
	

	FMatrix layerToRotator[MAX_LAYERS];

	void adjustCoordinatesToLayer(size_t layer, size_t a, size_t b, size_t &x, size_t &y, size_t &z);
	void populateRotators();
	std::vector<Cube> getLayer(int layer);

	
public:
	CubeAlgorithm();
	~CubeAlgorithm();
	void print();
	void init();
	// rotates given layer 90 degrees in positive or negative direction
	void rotateLayer(int layer, int direction);

	// 3D N^3 sized grid containing forward vectors at each (x,y,z)
	// position (small cube) in the large rubik's cube
	Cube cubes[N][N][N];
};
