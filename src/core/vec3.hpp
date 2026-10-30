#pragma once
#include <cmath>

class Vec3
{
public:
    float x = 0, y = 0, z = 0;

    Vec3()
    {
    }

    Vec3(float x_, float y_, float z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }

    Vec3 operator+(const Vec3 &other) const
    {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3 &other) const
    {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator*(float skalar) const
    {
        return Vec3(x * skalar, y * skalar, z * skalar);
    }

    Vec3 operator/(float skalar) const
    {
        return Vec3(x / skalar, y / skalar, z / skalar);
    }

    float length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }
};