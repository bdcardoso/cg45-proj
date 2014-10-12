#pragma once

#include "opengl.h"

class vector3 {
    typedef GLdouble scalar_t;
    // [0] -> x, [1] -> y, [2] -> z
    scalar_t _coords[3];

public:
    vector3(scalar_t x = 0, scalar_t y = 0, scalar_t z = 0);

    scalar_t x() const;
    scalar_t y() const;
    scalar_t z() const;

    void x(scalar_t newx);
    void y(scalar_t newy);
    void z(scalar_t newz);

    const scalar_t *get() const;
    void set(scalar_t x, scalar_t y, scalar_t z = 0);

    vector3 operator+(const vector3 &rhs) const;
    vector3 &operator+=(const vector3 &rhs);
    vector3 operator-(const vector3 &rhs) const;
    vector3 operator*(scalar_t scalar) const;

    scalar_t dot(const vector3 &rhs) const {
        return x() * rhs.x() +
               y() * rhs.y() +
               z() * rhs.z();
    }

    vector3 ext(const vector3 &rhs) const {
        return vector3(y() * rhs.z() - z() * rhs.y(),
                       z() * rhs.x() - x() * rhs.z(),
                       x() * rhs.y() - y() * rhs.x());
    }
};

