#pragma once
#include "vector3.h"
#include "opengl.h"

class vector4 {
    // [0] -> x, [1] -> y, [2] -> z, [3] -> w
    GLdouble _coords[4];

public:
    vector4(const vector3 &in);
    vector4(GLdouble x = 0, GLdouble y = 0, GLdouble z = 0, GLdouble w = 0);

    GLdouble x() const;
    GLdouble y() const;
    GLdouble z() const;
    GLdouble w() const;

    void x(GLdouble newx);
    void y(GLdouble newy);
    void z(GLdouble newz);
    void w(GLdouble neww);

    const GLdouble *get() const;
    void set(GLdouble x, GLdouble y, GLdouble z, GLdouble w = 0.0);
    
    vector4 operator+(const vector4 &rhs) const;
    vector4 operator-(const vector4 &rhs) const;
    vector4 operator*(GLdouble scalar) const;
};

