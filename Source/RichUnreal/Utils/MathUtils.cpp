// Copyright 2017 Evgeny Osmet.

#include "MathUtils.h"

float FindAngleXZRadians(const FVector& Vector)
{
	return FMath::Atan2(Vector.Z, Vector.X);
}

float FindAngleXZDegrees(const FVector& Vector)
{
	return FMath::RadiansToDegrees(FindAngleXZRadians(Vector));
}

FRotator ToOrientationRotatorXZ(const FVector& Vector)
{
	return FRotator(FindAngleXZDegrees(Vector), 0.0f, 0.0f);
}