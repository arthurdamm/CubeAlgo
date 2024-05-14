// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define N 3
/**
 * 
 */
class CUBEALGO_API CubeAlgorithm
{
private:
	FVector cubes[N][N][N];
public:
	CubeAlgorithm();
	~CubeAlgorithm();
	void test();
	void print();

};
