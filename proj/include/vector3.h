#pragma once

#include "opengl.h"

class vector3 {
    // [0] -> x, [1] -> y, [2] -> z
    GLdouble _coords[3];

public:
    vector3(GLdouble x = 0, GLdouble y = 0, GLdouble z = 0);

    GLdouble x() const;

    GLdouble y() const;

    GLdouble z() const;

    void x(GLdouble newx);

    void y(GLdouble newy);

    void z(GLdouble newz);

    const GLdouble *get() const;

    void set(GLdouble x, GLdouble y, GLdouble z = 0);

    vector3 operator+(const vector3 &rhs) const;

    vector3 operator-(const vector3 &rhs) const;

    vector3 operator*(GLdouble scalar) const;
};

