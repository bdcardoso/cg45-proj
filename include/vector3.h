#pragma once

#include "opengl.h"

class vector3 {
public:
    typedef GLdouble scalar_t;

    vector3(scalar_t x = 0, scalar_t y = 0, scalar_t z = 0);

    scalar_t x() const;
    scalar_t y() const;
    scalar_t z() const;

    void x(scalar_t newx);
    void y(scalar_t newy);
    void z(scalar_t newz);

    const scalar_t *get() const;
    void set(scalar_t x, scalar_t y, scalar_t z = 0);

    scalar_t dot(const vector3 &rhs) const;
    vector3 ext(const vector3 &rhs) const;
    vector3 normalized() const;

private:
    // [0] -> x, [1] -> y, [2] -> z
    scalar_t coords_[3];
};

vector3 operator+(const vector3 &lhs, const vector3 &rhs);
vector3 &operator+=(vector3 &lhs, const vector3 &rhs);
vector3 operator-(const vector3 &lhs, const vector3 &rhs);
vector3 operator*(const vector3 &lhs, const vector3::scalar_t &rhs);
vector3 operator*(const vector3::scalar_t &lhs, const vector3 &rhs);
vector3 operator/(const vector3 &lhs, const vector3::scalar_t &rhs);
