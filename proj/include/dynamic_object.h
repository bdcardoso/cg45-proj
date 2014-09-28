#pragma once

#include "opengl.h"
#include "vector3.h"


class dynamic_object {

protected:
    vector3 _speed;

public:
    dynamic_object();

    void update(double delta_t);

    void speed(const vector3 &speed);

    void speed(GLdouble x, GLdouble y, GLdouble z);

    vector3 speed() const;


};