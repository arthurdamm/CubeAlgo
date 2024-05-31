#pragma once

#include "CoreMinimal.h"

struct Cube {
	FVector location;
	FVector facing;
	FRotator rotation;
	FQuat orientation;
	int indices[3];
	int originalIndices[3];
	Cube(): location(0, 0, 0), facing(1, 0, 0), rotation(0, 0, 0), indices{0}, originalIndices{0} {
		orientation = FQuat(rotation);
	}
	// FString ToString() {
	// 	return "<L:(" + location.ToString() + ") F:(" + facing.ToString() + " R:(" + rotation.ToString()
	// 		+ ") [" + FString::FromInt(indices[0]) + "][" + FString::FromInt(indices[1])
	// 		+ "][" + FString::FromInt(indices[2]) + "](" + FString::FromInt(originalIndices[0]) + "][" + FString::FromInt(originalIndices[1])
	// 		+ "][" + FString::FromInt(originalIndices[2]) + "])>, ";
	// }

    FString ToString() const {
        return FString::Printf(
            TEXT("<L:(%.2f, %.2f, %.2f) F:(%.2f, %.2f, %.2f) R:(%.2f, %.2f, %.2f) [%d][%d][%d] ([%d][%d][%d])>, "),
            location.X, location.Y, location.Z,
            facing.X, facing.Y, facing.Z,
            rotation.Pitch, rotation.Yaw, rotation.Roll,
            indices[0], indices[1], indices[2],
            originalIndices[0], originalIndices[1], originalIndices[2]
        );
    }

	FString ToStringNormalized() const {
        return FString::Printf(
            TEXT("<L:(%.2f, %.2f, %.2f) F:(%.2f, %.2f, %.2f) R:(%.2f, %.2f, %.2f) [%d][%d][%d] ([%d][%d][%d])>, "),
            abs(location.X), abs(location.Y), abs(location.Z),
            abs(facing.X), abs(facing.Y), abs(facing.Z),
            abs(rotation.Pitch), abs(rotation.Yaw), abs(rotation.Roll),
            indices[0], indices[1], indices[2],
            originalIndices[0], originalIndices[1], originalIndices[2]
        );
    }

};
