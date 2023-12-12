#pragma once

template<typename T>
class SecondOrderDynamics
{
public:
    SecondOrderDynamics(float f, float z, float r, T x0);
    T update(float dt, T x);
    T update(float dt, T x, T xd);

private:
    T xp; // x previous
    T y, yd; // y and y derivative
    float k1, k2, k3; // dynamics constants
};

#include <SecondOrderDynamics.inl>