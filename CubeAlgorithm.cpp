// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeAlgorithm.h"

CubeAlgorithm::CubeAlgorithm(AActor* actor)
{
    if (actor == nullptr) {
        // UE_LOG(LogTemp, Display, TEXT("CubeAlgorithm() nullptr"));
    } else {
        this->actor = actor;
        // UE_LOG(LogTemp, Display, TEXT("CubeAlgorithm() %p %s %s"), actor, *actor->GetName(), *actor->GetActorLabel());
    }

    populateCenterForLayer();
    initializeCubes();
}

CubeAlgorithm::~CubeAlgorithm()
{
}

void CubeAlgorithm::print() {
    if (actor == nullptr) {
        UE_LOG(LogTemp, Display, TEXT("CubeAlgorithm() nullptr print()"));
    } else {
        UE_LOG(LogTemp, Display, TEXT("CubeAlgorithm::%s::print()"), *actor->GetActorLabel());
    }
    UE_LOG(LogTemp, Display, TEXT("%s"), *ToString());
}

FString CubeAlgorithm::ToString() {
    FString row, page = "\n";
    int parity = 0;
    for (size_t z = 0; z < N; z++) {
        for (size_t y = 0; y < N; y++) {
            row = "";
            for (size_t x = 0; x < N; x++) {
                row += grid.cubes[x][y][z].ToString();
                if (parity % 2 == 1) {
                    row += "\n";
                }
                parity++;
            }
            page += row;

        }
    }
    return page;
}

FString CubeAlgorithm::ToStringNormalized() {
    FString row, page = "\n";
    int parity = 0;
    for (size_t z = 0; z < N; z++) {
        for (size_t y = 0; y < N; y++) {
            row = "";
            for (size_t x = 0; x < N; x++) {
                row += grid.cubes[x][y][z].ToStringNormalized();
                if (parity % 2 == 1) {
                    row += "\n";
                }
                parity++;
            }
            page += row;

        }
    }
    return page;
}

void CubeAlgorithm::initializeCubes() {
    for (size_t z = 0; z < N; z++) {
        for (size_t y = 0; y < N; y++) {
            for (size_t x = 0; x < N; x++) {
                grid.cubes[x][y][z].indices[0] = x;
                grid.cubes[x][y][z].indices[1] = y;
                grid.cubes[x][y][z].indices[2] = z;
                grid.cubes[x][y][z].originalIndices[0] = x;
                grid.cubes[x][y][z].originalIndices[1] = y;
                grid.cubes[x][y][z].originalIndices[2] = z;
                grid.cubes[x][y][z].location = FVector(x, y, z); 
            }
        }
    }
}

FVector CubeAlgorithm::getRotationAxisForLayer(int layer) {
    FVector RotationAxis;
    if (layer >= 0 && layer < N) {
        RotationAxis = FVector(-1, 0, 0); // X-axis layers
    } else if (layer >= N && layer < 2 * N) {
        RotationAxis = FVector(0, -1, 0); // Y-axis layers
    } else if (layer >= 2 * N && layer < 3 * N) {
        RotationAxis = FVector(0, 0, 1); // Z-axis layers
    }
    return RotationAxis;
}

void CubeAlgorithm::populateCenterForLayer() {
    centersByLayer[0] = FVector(0, 1, 1);
    centersByLayer[1] = FVector(1, 1, 1);
    centersByLayer[2] = FVector(2, 1, 1);
    centersByLayer[3] = FVector(1, 0, 1);
    centersByLayer[4] = FVector(1, 1, 1);
    centersByLayer[5] = FVector(1, 2, 1);
    centersByLayer[6] = FVector(1, 1, 0);
    centersByLayer[7] = FVector(1, 1, 1);
    centersByLayer[8] = FVector(1, 1, 2);
}


FVector CubeAlgorithm::getCenterForLayer(int layer) {
    return centersByLayer[layer];
}

void CubeAlgorithm::rotateLayer(int layer, int direction) {
    // UE_LOG(LogTemp, Warning, TEXT("CubeAlgorithm::rotateLayer(%d, %d)"), layer, direction);

    FVector RotationAxis = getRotationAxisForLayer(layer);
    FQuat QuatRotation = FQuat(RotationAxis, FMath::DegreesToRadians(90.0f * direction));

    std::vector<Cube> layerCubes = getLayer(layer);
    for (auto& cube : layerCubes) {
        // UE_LOG(LogTemp, Error, TEXT("cube before: %s"), *cube.ToString());
        FVector relativePosition = cube.location - FVector(1.0f, 1.0f, 1.0f);
        FVector rotatedPosition = QuatRotation.RotateVector(relativePosition);
        cube.location = rotatedPosition + FVector(1.0f, 1.0f, 1.0f);

        // Update indices based on new position
        cube.indices[0] = dtoi(cube.location.X);
        cube.indices[1] = dtoi(cube.location.Y);
        cube.indices[2] = dtoi(cube.location.Z);

        cube.orientation = QuatRotation * cube.orientation;
        cube.orientation.Normalize();
        // UE_LOG(LogTemp, Error, TEXT("cube after: %s"), *cube.ToString());
    }
    for (auto& cube : layerCubes) {
        // Update the cube in the grid
        grid.cubes[cube.indices[0]][cube.indices[1]][cube.indices[2]] = cube;
    }
}

std::vector<Cube> CubeAlgorithm::getLayer(int layer) {
    std::vector<Cube> layerCubes;
    for (size_t a = 0; a < N; a++) {
        for (size_t b = 0; b < N; b++) {
            size_t x = 0, y = 0, z = 0;
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
            layerCubes.push_back(grid.cubes[x][y][z]);
        }
    }
    return layerCubes;
}

bool CubeAlgorithm::operator==(const CubeAlgorithm& other) const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (!(grid.cubes[i][j][k] == other.grid.cubes[i][j][k])) {
                    return false;
                }
            }
        }
    }
    return true;
}
