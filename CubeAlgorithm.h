// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define N 3
#define MAX_LAYERS N*N

struct Cube {
	FVector location;
	FVector facing;
	FRotator rotation;
	int indices[3];
	int originalIndices[3];
	Cube(): location(0, 0, 0), facing(1, 0, 0), rotation(0, 0, 0), indices{0}, originalIndices{0} {}
	// FString ToString() {
	// 	return "<L:(" + location.ToString() + ") F:(" + facing.ToString() + " R:(" + rotation.ToString()
	// 		+ ") [" + FString::FromInt(indices[0]) + "][" + FString::FromInt(indices[1])
	// 		+ "][" + FString::FromInt(indices[2]) + "](" + FString::FromInt(originalIndices[0]) + "][" + FString::FromInt(originalIndices[1])
	// 		+ "][" + FString::FromInt(originalIndices[2]) + "])>, ";
	// }

    FString ToString() const {
        return FString::Printf(
            TEXT("<L:(%.2f, %.2f, %.2f) F:(%.2f, %.2f, %.2f) R:(%.2f, %.2f, %.2f) [%d][%d][%d](%d][%d][%d])>, "),
            location.X, location.Y, location.Z,
            facing.X, facing.Y, facing.Z,
            rotation.Pitch, rotation.Yaw, rotation.Roll,
            indices[0], indices[1], indices[2],
            originalIndices[0], originalIndices[1], originalIndices[2]
        );
    }

};

/**
 * 
 */
class CUBEALGO_API CubeAlgorithm
{
private:
	

	FMatrix layerToRotator[MAX_LAYERS];
	AActor* actor;

	void adjustCoordinatesToLayer(size_t layer, size_t a, size_t b, size_t &x, size_t &y, size_t &z);
	void populateRotators();
	std::vector<Cube> getLayer(int layer);

	
public:
	CubeAlgorithm(AActor* actor);
	~CubeAlgorithm();
	void print();
	FString ToString();
	void init();
	// rotates given layer 90 degrees in positive or negative direction
	void rotateLayer(int layer, int direction);

	// 3D N^3 sized grid containing forward vectors at each (x,y,z)
	// position (small cube) in the large rubik's cube
	Cube cubes[N][N][N];
};
