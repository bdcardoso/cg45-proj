#pragma once

#include "opengl.h"
#include "vector3.h"
#include "vector4.h"

class light_source {
    vector4 ambient_, diffuse_, specular_, position_;
    vector3 direction_;
    GLdouble cutoff_, exponent_;
    GLenum num_;
    bool state_;

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
