#include <cmath>
#include <iostream>

template <class T>
class Vector3D
{
	T x, y, z;
public:
	Vector3D(T xIn = 0.0f, T yIn = 0.0f, T zIn = 0.0f) : x(xIn), y(yIn), z(zIn) {}

	// accessors
	auto getX() const { return x; }
	auto getY() const { return y; }
	auto getZ() const { return z; }

	// binary arithmetic operators
	auto operator * (const T& scal) const { return Vector3D<T>(x * scal, y * scal, z * scal); }
	auto operator / (const T& scal) const { return Vector3D<T>(x / scal, y / scal, z / scal); }
	auto operator * (const Vector3D<T>& v) { return x * v.x + y * v.y + z * v.z; }
	auto operator + (const Vector3D<T>& v) { return Vector3D<T>(x + v.x, y + v.y, z + v.z); }
	auto operator - (const Vector3D<T>& v) { return Vector3D<T>(x - v.x, y - v.y, z - v.z); }

	// compound assignment operators
	auto &operator *= (const T& scal) { x *= scal, y *= scal, z *= scal; return *this; }
	auto &operator /= (const T& scal) { x /= scal, y /= scal, z /= scal; return *this; }
	auto &operator += (const Vector3D<T>& v) { x += v.x, y += v.y, z += v.z; return *this; }
	auto &operator -= (const Vector3D<T>& v) { x -= v.x, y -= v.y, z -= v.z; return *this; }

	// special functions
	auto mag2() const { return x * x + y * y + z * z; } // square of magnitude
	auto mag() const { return std::sqrt(mag2()); }

	// print function
	void print() const {std::cout << "( " << x << " , " << y << " , " << z << " )" << std::endl; }
};
