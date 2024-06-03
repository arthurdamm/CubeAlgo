int dtoi(double n) {
    return static_cast<int>(fabs(round(n)));
}

double HandleNegativeZero(double value) {
    if (value == -0.0) {
        return 0.0;
    }
    return value;
}

bool AreQuatsEqual(const FQuat& A, const FQuat& B)
{
    return (A.Equals(B, 1e-6f) || A.Equals(-B, 1e-6f));
}
