#pragma once

#include "opengl.h"
#include "vector3.h"
#include "vector4.h"


class light_source {
    vector4 _ambient, _diffuse, _specular, _position;
    vector3 _direction;
    GLdouble _cutoff, _exponent;
    GLenum _num;
    bool _state;

public:
    light_source(GLenum number);

    bool state() const;

    void state(bool newstate);

    GLenum num() const;

    void ambient(const vector4 &amb);

    void diffuse(const vector4 &dif);

    void position(const vector4 &pos);

    void specular(const vector4 &spec);

    void direction(const vector3 &dir);

    void cutoff(GLdouble cutoff);

    void exponent(GLdouble exp);

    void draw();
};

