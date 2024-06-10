#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int dtoi(double n);

double HandleNegativeZero(double value);

bool AreQuatsEqual(const FQuat& A, const FQuat& B);

template <typename Collection, typename Predicate>
Collection filter(const Collection& input, Predicate pred) {
    Collection result;
    std::copy_if(input.begin(), input.end(), std::back_inserter(result), pred);
    return result;
}
