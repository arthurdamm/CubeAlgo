// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeAlgorithm.h"

CubeAlgorithm::CubeAlgorithm()
{
    UE_LOG(LogTemp, Error, TEXT("CubeAlgorithm()"));
    test();
}

CubeAlgorithm::~CubeAlgorithm()
{
}

void PerformRotations()
{
    FVector VecX(1, 0, 0);  // Vector along the X-axis
    FVector VecZ(0, 0, 1);  // Vector along the Z-axis

    // Roll around the Y-axis
    FRotator RollRotator(0, 0, 90);  // Pitch, Yaw, Roll
    FMatrix RollMatrix = FRotationMatrix(RollRotator);
    FVector RotatedVecX = RollMatrix.TransformVector(VecX);
    FVector RotatedVecZ = RollMatrix.TransformVector(VecZ);

    UE_LOG(LogTemp, Warning, TEXT("Original Vector X: %s, Rotated Vector X by Roll: %s"), *VecX.ToString(), *RotatedVecX.ToString());
    UE_LOG(LogTemp, Warning, TEXT("Original Vector Z: %s, Rotated Vector Z by Roll: %s"), *VecZ.ToString(), *RotatedVecZ.ToString());
}

void CubeAlgorithm::test() {
    UE_LOG(LogTemp, Error, TEXT("CubeAlgorithm::test()"));

    FVector vector = FVector(1, 0, 0);
    FRotator rotator = FRotator(0, 90, 0);
    FMatrix rotationMatrix = FRotationMatrix(rotator);
    FVector rotatedVector = rotationMatrix.TransformVector(vector);
    UE_LOG(LogTemp, Error, TEXT("vvector: %s rotatedVector: %s"), *vector.ToString(), *rotatedVector.ToString());
    PerformRotations();
}

void CubeAlgorithm::print() {
    FString row = "";
    for (size_t z = 0; z < N; z++) {
        for (size_t y = 0; y < N; y++) {    
            for (size_t x = 0; x < N; x++) {
                row += cubes[x][y][z].ToString() + " ";

            }
            UE_LOG(LogTemp, Error, TEXT("%s"), *row);
        }
    }
}
