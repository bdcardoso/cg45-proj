#pragma once
#include "opengl.h"
#include "vector3.h"

class entity {
protected:
    vector3 _position;

public:
    entity();

    vector3 position() const;
    void position(GLdouble x, GLdouble y, GLdouble z);
    void position(const vector3 &p);
};
