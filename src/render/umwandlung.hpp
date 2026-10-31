#pragma once
#include "core/vec3.hpp"
#include "raylib.h"

inline Vector3 zuVector3(const Vec3 &v)
{
    return Vector3{v.x, v.y, v.z};
}