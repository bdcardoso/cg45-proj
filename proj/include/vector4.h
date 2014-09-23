#pragma once
#include "vector3.h"
#include <GL/gl.h>

class vector4 {
    // [0] -> x, [1] -> y, [2] -> z, [3] -> w
    GLdouble _coords[4];

public:
    vector4();
    vector4(const vector3 &in);
    vector4(GLdouble x, GLdouble y, GLdouble z, GLdouble w);

    GLdouble x();
    GLdouble y();
    GLdouble z();
    GLdouble w();

    void x(GLdouble newx);
    void y(GLdouble newy);
    void z(GLdouble newz);
    void w(GLdouble neww);

    const GLdouble *get() const;
    void set(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
    
    vector4 &operator+(const vector4 &rhs);
    vector4 &operator-(const vector4 &rhs);
    vector4 &operator*(GLdouble scalar);
};

