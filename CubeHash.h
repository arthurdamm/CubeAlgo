#pragma once

#include "CubeAlgorithm.h"

struct CubeHasher {
    size_t operator()(const Cube& cube) const {
        size_t seed = 0;
        auto hash_combine = [&seed](auto& val) {
            std::hash<std::decay_t<decltype(val)>> hasher;
            seed ^= hasher(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        };
        hash_combine(cube.orientation.X);
        hash_combine(cube.orientation.Y);
        hash_combine(cube.orientation.Z);
        hash_combine(cube.orientation.W);
        // Combine other fields if present
        return seed;
    }
};
struct GridHasher {
    size_t operator()(const CubeGrid grid) const {
        size_t seed = 0;
        CubeHasher cubeHasher;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < N; ++k)
                    seed ^= cubeHasher(grid.cubes[i][j][k]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

