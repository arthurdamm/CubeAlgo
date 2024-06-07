// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Utilities.h"
#include "CoreMinimal.h"
#include "Cube.h"

#define N 3
#define LAYERS N*N

/**
 * Abstractly manages a grid of cubes and the rotation of their layers
 */
class CUBEALGO_API CubeAlgorithm
{
private:
    // The actor associated with this CubeAlgorithm
    AActor* actor;

    // The centers of each layer used for rotation
    FVector centersByLayer[LAYERS];

    void populateCenterForLayer();
    
    // Returns a vector of Cubes in the specified layer
    std::vector<Cube> getLayer(int layer);  

public:
    // A 3D array of Cubes
    Cube cubes[N][N][N];

    // Constructor that takes an actor as an argument
    CubeAlgorithm(AActor* actor);  

    // Destructor
    ~CubeAlgorithm();  

    // Prints the state of the CubeAlgorithm
    void print();  

    // Returns a string representation of the CubeAlgorithm
    FString ToString();

    // Returns a normalized string representation of the CubeAlgorithm
    FString ToStringNormalized();  

    // Initializes the cubes in the CubeAlgorithm
    void initializeCubes();  

    // Rotates a layer of cubes in the specified direction
    void rotateLayer(int layer, int direction);  

    // Returns the rotation axis for a specified layer
    FVector getRotationAxisForLayer(int layer);

    // Returns the center of a specified layer
    FVector getCenterForLayer(int layer);

    bool operator==(const CubeAlgorithm& other) const;

};