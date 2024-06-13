// Fill out your copyright notice in the Description page of Project Settings.


#include "RubiksCubeActor.h"
#include "CubeActor.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/TextRenderComponent.h"

#include "HAL/PlatformTime.h"

// Sets default values
ARubiksCubeActor::ARubiksCubeActor()
{
	UE_LOG(LogTemp, Error, TEXT("ARubiksCubeActor()!!!"));
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create a root component and set it as the root
    USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = RootComp;
    // Set the root component's mobility to Movable
    RootComponent->SetMobility(EComponentMobility::Movable);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(CUBE_MESH);
    if (MeshObj.Succeeded())
    {
        CubeMesh = MeshObj.Object;
        UE_LOG(LogTemp, Warning, TEXT("MeshObj: SUCCEEDED!"));
    } else {
		UE_LOG(LogTemp, Warning, TEXT("MeshObj: FAILED"));
	}
}

void ARubiksCubeActor::print() {
	UE_LOG(LogTemp, Warning, TEXT("%s::print()"), *GetActorLabel());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ToString());
}

FString ARubiksCubeActor::ToString() {
    FString page = "\n";
    for (int k = 0; k < 3; k++)
    {
        for (int j = 0; j < 3; j++)
        {
            FString row = "";
            for (int i = 0; i < 3; i++)
            {
                row += Cubes[i][j][k]->ToStringNormalized();
            }
            page += row + "\n";
        }
    }
    return page;
}


// Called when the game starts or when spawned
void ARubiksCubeActor::BeginPlay()
{
	Super::BeginPlay();

    StartTime = FPlatformTime::Seconds();
	// SetActorLocation(StartLocation);
    StartLocation = GetActorLocation();
	FVector BasePosition = StartLocation;
	UE_LOG(LogTemp, Warning, TEXT("---Starting CubeActor location: %s"), *BasePosition.ToString());

    algo = CubeAlgorithm(this);
    algo.print();
    for (auto rotation : InstantRotations) {
        algo.rotateLayer(rotation, 1);
        algo.print();
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                FVector Position = BasePosition + FVector(i * CubeEdgeLength, j * CubeEdgeLength, k * CubeEdgeLength);
				// FRotator Rotation = algo.grid.cubes[i][j][k].facing.Rotation();
                FActorSpawnParameters SpawnParams;
                SpawnParams.Owner = this;
                SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
                
                ACubeActor* NewCube = GetWorld()->SpawnActor<ACubeActor>(ACubeActor::StaticClass(), Position, FRotator::ZeroRotator, SpawnParams);
                
                if (NewCube && NewCube->GetStaticMeshComponent())
                {
					UE_LOG(LogTemp, Warning, TEXT("Spawned Cube at %s"), *Position.ToString());
                    NewCube->StartLocation = StartLocation;
                    NewCube->CubeEdgeLength = CubeEdgeLength;
                    NewCube->GetStaticMeshComponent()->SetStaticMesh(CubeMesh);  // Referencing CubeMesh here
                    NewCube->GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);  // Set mobility to Movable
					// NewCube->SetActorRotation(algo.grid.cubes[i][j][k].rotation);
                    NewCube->SetActorRotation(algo.grid.cubes[i][j][k].orientation.Rotator());

                    NewCube->SetOriginalIndices(algo.grid.cubes[i][j][k].originalIndices[0],
                        algo.grid.cubes[i][j][k].originalIndices[1],
                        algo.grid.cubes[i][j][k].originalIndices[2]);
                    NewCube->SetIndices(i, j, k);
                    NewCube->cubealgo = algo.grid.cubes[i][j][k].ToString();
                    

					// NewCube->SetActorRotation(algo.grid.cubes[i][j][k].facing.Rotation()); // hopefully correct?
					UTextRenderComponent* TextRender = NewObject<UTextRenderComponent>(NewCube);
                    if (TextRender)
                    {
                        TextRender->SetText(FText::FromString("Front Face"));
                        TextRender->SetupAttachment(NewCube->GetStaticMeshComponent());
                        TextRender->SetRelativeLocation(FVector(110, 0, 0));  // Adjust position as needed
                        TextRender->SetRelativeRotation(FRotator(0, 0, 0));  // Adjust rotation as needed
                        TextRender->SetHorizontalAlignment(EHTA_Center);
                        TextRender->SetWorldSize(50.0f);
                        TextRender->RegisterComponent();
                    }
                    CubesVector.push_back(NewCube);
                    
                    if (j == 1 && k == 1) {
                        NormalsAtLayer[0 + i] = FVector(-1, 0, 0);
                        CentersAtLayer[0 + i] = NewCube->GetActorLocation();
                        UE_LOG(LogTemp, Warning, TEXT("CentersAtLayer[%d][%d][%d]: %s"), i, j, k, *CentersAtLayer[0 + i].ToString());
                    }
                    if (i == 1 && k == 1) {
                        NormalsAtLayer[3 + j] = FVector(0, -1, 0);
                        CentersAtLayer[3 + j] = NewCube->GetActorLocation();
                        UE_LOG(LogTemp, Warning, TEXT("CentersAtLayer[%d][%d][%d]: %s"), i, j, k, *CentersAtLayer[3 + j].ToString());
                    }
                    if (i == 1 && j == 1) {
                        NormalsAtLayer[6 + k] = FVector(0, 0, 1);
                        CentersAtLayer[6 + k] = NewCube->GetActorLocation();
                        UE_LOG(LogTemp, Warning, TEXT("CentersAtLayer[%d][%d][%d]: %s"), i, j, k, *CentersAtLayer[6 + k].ToString());
                    }
                }
            }
        }
    }

    for (auto rotation : AnimatedRotations) {
        RotationsQueue.Enqueue(rotation);
    }
    if (loopAnimation) {
        for (int i = AnimatedRotations.Num() - 1; i >= 0; i--) {
            RotationsQueue.Enqueue(-AnimatedRotations[i]);
        }
    }

    PopulateCubesGrid();
	print();
	UE_LOG(LogTemp, Warning, TEXT("ROTATING!!!!..."));
    UE_LOG(LogTemp, Warning, TEXT("MaxRotationAngle: %f\n"), MaxRotationAngle);
}

void ARubiksCubeActor::PopulateCubesGrid() {
    for (ACubeActor* Cube : CubesVector) {
        FVector gridPosition = (Cube->GetActorLocation() - StartLocation) / CubeEdgeLength;
        int x = dtoi(gridPosition.X), y = dtoi(gridPosition.Y), z = dtoi(gridPosition.Z);
        // UE_LOG(LogTemp, Warning, TEXT("%s -> %s -> [%d][%d][%d] %s"), *Cube->GetActorLocation().ToString(), *gridPosition.ToString(), x, y, z, *Cube->GetActorForwardVector().ToString());
        Cubes[x][y][z] = Cube;
        Cube->UpdateIndices(x, y, z);
    }   
}

std::vector<AStaticMeshActor *> ARubiksCubeActor::GetCubesInLayer(int layerIndex) {
    std::vector<AStaticMeshActor *> CubesInLayer;
    UE_LOG(LogTemp, Error, TEXT("GetCubesInLayer(%d)"), layerIndex);
    for (int a = 0; a <= 2; a++) {
        for (int b = 0; b <= 2; b++) {
            AStaticMeshActor *Cube = NULL;
            if (layerIndex <= 2) {
                Cube = Cubes[layerIndex][a][b];
            } else if (layerIndex <= 5) {
                Cube = Cubes[a][layerIndex - 3][b];
            } else if (layerIndex <= 8) {
                Cube = Cubes[a][b][layerIndex - 6];
            } else {
                UE_LOG(LogTemp, Error, TEXT("ERROR: a:%d b:%d layerIndex:%d"), a, b, layerIndex);
            }
            // UE_LOG(LogTemp, Error, TEXT("Cube: %lu"), Cube);
            CubesInLayer.push_back(Cube);
        }
    }
    for (AStaticMeshActor * c : CubesInLayer) {
        // UE_LOG(LogTemp, Error, TEXT("PRINT: %lu"), c);
    }
    return CubesInLayer;    
}

// In CubeActor.cpp

void ARubiksCubeActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    MaybeRotate(DeltaTime);
}


void ARubiksCubeActor::MaybeRotate(float DeltaTime) {
    if (!StartTime || FPlatformTime::Seconds() - StartTime < rotationDelay) {
        return;
    }

    if (!bIsRotating) {
        if (!RotationsQueue.IsEmpty()) {
            UE_LOG(LogTemp, Error, TEXT("Rotating..."));
            int dequeuedLayer = 0;
            if (!RotationsQueue.Dequeue(dequeuedLayer)) {
                UE_LOG(LogTemp, Error, TEXT("RotationsQueue.Dequeue failed!"));
            }
            StartRotation(dequeuedLayer);
        } else {
            if (loopAnimation) {
                for (auto rotation : AnimatedRotations) {
                    RotationsQueue.Enqueue(rotation);
                }
                for (int i = AnimatedRotations.Num() - 1; i >= 0; i--) {
                    RotationsQueue.Enqueue(-AnimatedRotations[i]);
                }
            }
        }
    }
    if (bIsRotating)
    {
        float DeltaRotation = RotationSpeed * DeltaTime;
        RotationAngle += DeltaRotation;
        // UE_LOG(LogTemp, Warning, TEXT("Angle: %f \t Delta: %f"), RotationAngle, DeltaRotation);

        if (RotationAngle >= MaxRotationAngle)
        {
            DeltaRotation -= (RotationAngle - MaxRotationAngle);
            RotationAngle = MaxRotationAngle;
            bIsRotating = false; // Stop rotation after 90 degrees
            StartTime = FPlatformTime::Seconds();

            UE_LOG(LogTemp, Warning, TEXT("ROTATION stopped"));
        }

        FQuat QuatRotation = FQuat(RotationAxis, FMath::DegreesToRadians(DeltaRotation));
        FVector RotationCenter = CentersAtLayer[LayerToRotate];
        FVector EndPoint;
        // UE_LOG(LogTemp, Warning, TEXT("Rotation Center: %s"), *RotationCenter.ToString());
        // UE_LOG(LogTemp, Warning, TEXT("Rotating cubes: %d"),  GetCubesInLayer(LayerToRotate)->size());

        int i = 0;
        for (AStaticMeshActor* CubeToRotate : GetCubesInLayer(LayerToRotate)) {
            if (CubeToRotate)
            {
                i++;
                FVector RelativePosition = CubeToRotate->GetActorLocation() - RotationCenter;
                FVector RotatedPosition = QuatRotation.RotateVector(RelativePosition);
                CubeToRotate->SetActorLocation(RotationCenter + RotatedPosition);
                CubeToRotate->AddActorWorldRotation(QuatRotation);
                // DrawCubeFacingLine(EndPoint, CubeToRotate);
            }

        }
        // UE_LOG(LogTemp, Warning, TEXT("Rotated this many: %d"), i);

        // DrawNormalLine(EndPoint, RotationCenter);

        if (!bIsRotating) {
            UE_LOG(LogTemp, Warning, TEXT("Rotation Stopped..."));
            PopulateCubesGrid();
			print();
            // RecalculateRotationCenters();
        }
    }
}

void ARubiksCubeActor::DrawCubeFacingLine(FVector &EndPoint, AStaticMeshActor *CubeToRotate)
{
    EndPoint = CubeToRotate->GetActorLocation() + CubeToRotate->GetActorForwardVector() * 1000.0f; // Extend the line along the rotation axis
    DrawDebugLine(
        GetWorld(),
        CubeToRotate->GetActorLocation(),
        EndPoint,
        FColor::Red,
        false, // Persistent lines
        0.1,   // Lifetime
        0,     // Depth priority
        10.0   // Thickness
    );
}

void ARubiksCubeActor::DrawNormalLine(FVector &EndPoint, FVector &RotationCenter)
{
    EndPoint = RotationCenter + RotationAxis * 1000.0f; // Extend the line along the rotation axis
    DrawDebugLine(
        GetWorld(),
        RotationCenter,
        EndPoint,
        FColor::Red,
        false, // Persistent lines
        0.1,   // Lifetime
        0,     // Depth priority
        10.0   // Thickness
    );
}

// In CubeActor.cpp

void ARubiksCubeActor::StartRotation(int LayerIndex)
{
    UE_LOG(LogTemp, Warning, TEXT("StartRotation: %d\t%lf"), LayerIndex, FPlatformTime::Seconds() - StartTime);
    if (!bIsRotating)
    {
        bIsRotating = true;
        LayerToRotate = abs(LayerIndex);
        RotationAxis = LayerIndex < 0 ? -NormalsAtLayer[-LayerIndex] : NormalsAtLayer[LayerIndex];
        UE_LOG(LogTemp, Warning, TEXT("RotationAxis: %s"), *RotationAxis.ToString());
        float Duration = 0.25f;
        RotationSpeed = 90.0f / Duration; // Calculate speed based on duration
        RotationAngle = 0.0f;
        TargetRotation = FQuat(RotationAxis, FMath::DegreesToRadians(90.0f));
    }
}

void ARubiksCubeActor::RecalculateRotationCenters() {
    for (int i = 0; i < 9; i++) { // assuming 9 layers for a 3x3 Rubik's cube
        FVector newCenter = FVector::ZeroVector;
        auto cubesInLayer = GetCubesInLayer(i);
        for (auto* cube : cubesInLayer) {
            newCenter += cube->GetActorLocation();
        }
        newCenter /= cubesInLayer.size();
        CentersAtLayer[i] = newCenter;
    }
}
