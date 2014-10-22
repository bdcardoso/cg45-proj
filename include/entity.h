#pragma once
#include "opengl.h"
#include "vector3.h"

class entity {
protected:
    vector3 position_;

public:
    typedef vector3::scalar_t scalar_t;

    entity();

    vector3 &position();
    void position(scalar_t x, scalar_t y, scalar_t z);
    void position(const vector3 &p);
};
