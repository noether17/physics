#pragma once
#include <cmath>
#include <iostream>

template <typename T>
class Vector3D
{
    T x, y, z;
public:
    // constructor
    Vector3D(T xIn = 0.0f, T yIn = 0.0f, T zIn = 0.0f) : x(xIn), y(yIn), z(zIn) {}

    // accessors
    auto getX() const { return x; }
    auto getY() const { return y; }
    auto getZ() const { return z; }

    // compound assignment operators
    auto& operator *= (T scal) { x *= scal; y *= scal; z *= scal; return *this; }
    auto& operator /= (T scal) { x /= scal; y /= scal; z /= scal; return *this; }
    auto& operator += (Vector3D<T> v) { x += v.x; y += v.y; z += v.z; return *this; }
    auto& operator -= (Vector3D<T> v) { x -= v.x; y -= v.y; z -= v.z; return *this; }

    // binary arithmetic operators
    auto operator * (T scal) const { Vector3D<T> tmp(*this); return *this * scal; }
    auto operator / (T scal) const { Vector3D<T> tmp(*this); return *this / scal; }
    auto operator * (Vector3D<T> v) const { return x * v.x + y * v.y + z * v.z; }
    auto operator + (Vector3D<T> v) const { Vector3D<T> tmp(*this); return *this += v; }
    auto operator - (Vector3D<T> v) const { Vector3D<T> tmp(*this); return *this -= v; }

    // special functions
    auto mag2() const { return *this * *this; } // square of magnitude
    auto mag() const { return std::sqrt(mag2()); }
    auto norm() const { auto _mag = mag(); return _mag ? *this / _mag : *this; }

    // print function
    void print() const {std::cout << "( " << x << " , " << y << " , " << z << " )" << std::endl; }
};
