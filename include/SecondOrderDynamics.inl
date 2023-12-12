// Included by: include/SecondOrderDynamics.hpp
#include <math.h>
#include <iostream>

template <typename T>
SecondOrderDynamics<T>::SecondOrderDynamics(float f, float z, float r, T x0)
{
    const float PI = std::acos(-1);
    k1 = z / (PI * f);
    k2 = 1.f / ((2.f * PI * f) * (2.f * PI * f));
    k3 = r * z / (2.f * PI * f);

    xp = x0;
    y = x0;
    yd = 0.f;
}

template <typename T>
T SecondOrderDynamics<T>::update(float dt, T x)
{
    T xd = (x - xp) / dt;
    return update(dt, x, xd);
}

template <typename T>
T SecondOrderDynamics<T>::update(float dt, T x, T xd)
{
    xp = x;

    float k2_stable = std::max(k2, 1.1f * (dt*dt/4.f + dt*k1/2.f));
    y += yd * dt;
    yd += dt * (x + k3 * xd - y - k1 * yd) / k2_stable;
    return y;
}