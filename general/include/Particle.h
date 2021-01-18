#pragma once
#include "Vector3D.h"

template <typename T>
class Particle
{
    T mass;
    Vector3D<T> pos;
    Vector3D<T> vel;
public:
    Particle(T m, Vector3D<T> p, Vector3D<T> v) : mass(m), pos(p), vel(v) {}

    // accessors
    auto getMass() const { return mass; }
    auto getPos() const { return pos; }
    auto getVel() const { return vel; }

    // mutators
    void setMass(T m) { mass = m; }
    void setPos(Vector3D<T> p) { pos = p; }
    void setVel(Vector3D<T> v) { vel = v; }

    // position/velocity increment/decrement functions
    void incPos(Vector3D<T> inc) { pos += inc; }
    void incVel(Vector3D<T> inc) { vel += inc; }
    void decPos(Vector3D<T> dec) { pos -= dec; }
    void decVel(Vector3D<T> dec) { vel -= dec; }

    // Particle algebra
    auto operator + (Particle<T> part) const;
    auto operator - (Particle<T> part) const;
    auto operator * (T scal) const;
    auto operator / (T scal) const;

    // Particle modifiers
    auto &operator += (Particle<T> part);
    auto &operator -= (Particle<T> part);
    auto &operator *= (T scal);
    auto &operator /= (T scal);

    // distance
    auto distance(Particle<T> part) const;
};
