#pragma once

#include "opengl.h"

class vector4 {
public:
    typedef GLfloat scalar_t;

    vector4(scalar_t x = 0, scalar_t y = 0, scalar_t z = 0, scalar_t w = 0);

    scalar_t &x();
    const scalar_t &x() const;
    scalar_t &y();
    const scalar_t &y() const;
    scalar_t &z();
    const scalar_t &z() const;
    scalar_t &w();
    const scalar_t &w() const;

    const scalar_t *get() const;
    void set(scalar_t x, scalar_t y, scalar_t z, scalar_t w);

private:
    // [0] -> x, [1] -> y, [2] -> z, [3] -> w
    scalar_t coords_[4];
};

vector4 operator+(vector4 lhs, vector4 rhs);
vector4 operator-(vector4 lhs, vector4 rhs);
vector4 operator*(vector4 lhs, vector4::scalar_t factor);
vector4 operator*(vector4::scalar_t factor, vector4 rhs);
