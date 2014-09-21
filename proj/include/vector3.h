#pragma once
#include <GL/gl.h>

class vector3 {
    // [0] -> x, [1] -> y, [2] -> z
    GLdouble _coords[3];

public:
    vector3();
    vector3(GLdouble x, GLdouble y, GLdouble z);

    GLdouble x() const;
    GLdouble y() const;
    GLdouble z() const;

    void x(GLdouble newx);
    void y(GLdouble newy);
    void z(GLdouble newz);

    const GLdouble *get() const;
    void set(GLdouble x, GLdouble y, GLdouble z);
    
    vector3 operator+(const vector3 &rhs);
    vector3 operator-(const vector3 &rhs);
    vector3 operator*(GLdouble scalar);
};

