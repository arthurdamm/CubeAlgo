// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeAlgorithm.h"

int dtoi(double n) {
    int result = static_cast<int64>(fabs(round(n)));
    // UE_LOG(LogTemp, Display, TEXT("dtoi(%f)=%d"), n, result);
    return result;
}

CubeAlgorithm::CubeAlgorithm(AActor* actor)
{
    if (actor == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("CubeAlgorithm() nullptr"));
    } else {
        this->actor = actor;
        UE_LOG(LogTemp, Error, TEXT("CubeAlgorithm() %p %s %s"), actor, *actor->GetName(), *actor->GetActorLabel());
    }
    // UE_LOG(LogTemp, Warning, TEXT("sizes: %d %d %d"), sizeof(float), sizeof(double), sizeof(long double));
    populateRotators();
    FVector test = FVector(0, 1, 1);
    test = layerToRotator[0].TransformVector(test);
    // UE_LOG(LogTemp, Error, TEXT("TEST: %s"), *test.ToString());
    init();
}

CubeAlgorithm::~CubeAlgorithm()
{
}

void CubeAlgorithm::print() {
    if (actor == nullptr) {
        UE_LOG(LogTemp, Error, TEXT("CubeAlgorithm() nullptr print()"));
    } else {
        UE_LOG(LogTemp, Error, TEXT("CubeAlgorithm::%s::print()"), *actor->GetActorLabel());
    }
    UE_LOG(LogTemp, Error, TEXT("%s"), *ToString());
}

FString CubeAlgorithm::ToString() {
    FString row, page = "\n";
    for (size_t z = 0; z < N; z++) {
        for (size_t y = 0; y < N; y++) {
            row = "";
            for (size_t x = 0; x < N; x++) {
                row += cubes[x][y][z].ToString();
            }
            page += row + '\n';
        }
    }
    return page;
}

void CubeAlgorithm::init() {
    for (size_t z = 0; z < N; z++) {
        for (size_t y = 0; y < N; y++) {    
            for (size_t x = 0; x < N; x++) {
                cubes[x][y][z].indices[0] = x;
                cubes[x][y][z].indices[1] = y;
                cubes[x][y][z].indices[2] = z;
                cubes[x][y][z].originalIndices[0] = x;
                cubes[x][y][z].originalIndices[1] = y;
                cubes[x][y][z].originalIndices[2] = z;
                cubes[x][y][z].location = FVector(x, y, z); 
            }
        }
    }
}

void CubeAlgorithm::populateRotators() {
    for (int layer = 0; layer < MAX_LAYERS; layer++) {
        if (layer >= 0 && layer < N) {
            layerToRotator[layer] = FRotationMatrix(FRotator(0, 0, 90));
        } else if (layer >= N && layer < 2 * N) {
            layerToRotator[layer] = FRotationMatrix(FRotator(90, 0, 0));
        } else if (layer >= 2 * N && layer < 3 * N) {
            layerToRotator[layer] = FRotationMatrix(FRotator(0, 90, 0));
        }
    }
}

void CubeAlgorithm::rotateLayer(int layer, int direction) {
    UE_LOG(LogTemp, Error, TEXT("CubeAlgorithm::rotateLayer(%d, %d)"), layer, direction);
    std::vector<Cube> layerCubes = getLayer(layer);
    FVector indices;
    for (auto& cube : layerCubes) {
        indices.X = cube.indices[0] - 1;
        indices.Y = cube.indices[1] - 1;
        indices.Z = cube.indices[2] - 1;
        UE_LOG(LogTemp, Warning, TEXT("cube before: %s"), *cube.ToString());
        // UE_LOG(LogTemp, Warning, TEXT("indices before: %s"), *indices.ToString());
        cube.facing = layerToRotator[layer].TransformVector(cube.facing);
        indices = layerToRotator[layer].TransformVector(indices);
        // cube.rotation += layerToRotator[layer].Rotator();
        cube.rotation = (FQuat(cube.rotation) * FQuat(layerToRotator[layer].Rotator())).Rotator();

        // UE_LOG(LogTemp, Warning, TEXT("%s"), *cube.ToString());
        // UE_LOG(LogTemp, Error, TEXT("indices after: %s"), *indices.ToString());
        cube.indices[0] = dtoi(indices.X + 1);
        cube.indices[1] = dtoi(indices.Y + 1);
        cube.indices[2] = dtoi(indices.Z + 1);
        UE_LOG(LogTemp, Error, TEXT("cube after: %s"), *cube.ToString());
        cubes[cube.indices[0]][cube.indices[1]][cube.indices[2]] = cube;
        UE_LOG(LogTemp, Display, TEXT("."));
    }
}

std::vector<Cube> CubeAlgorithm::getLayer(int layer) {
    std::vector<Cube> layerCubes;
    for (size_t a = 0; a < N; a++) {
        for (size_t b = 0; b < N; b++) {
            size_t x = 0, y = 0, z = 0;
            adjustCoordinatesToLayer(layer, a, b, x, y, z);
            layerCubes.push_back(cubes[x][y][z]);
            // UE_LOG(LogTemp, Display, TEXT("Before: layer:%d x:%d y:%d z:%d"), layer, x, y, z);

        }
    }
    return layerCubes;
}

void CubeAlgorithm::adjustCoordinatesToLayer(size_t layer, size_t a, size_t b, size_t &x, size_t &y, size_t &z) {
    if (layer >= 0 && layer <= 2) {
        x = layer - 0;
        y = a;
        z = b;
    } else if (layer >= 3 && layer <= 5) {
        x = a;
        y = layer - 3;
        z = b;
    } else if (layer >= 6 && layer <= 8) {
        x = a;
        y = b;
        z = layer - 6;
    }
}