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

    vector4 position();

    void draw();
    void keydown(unsigned char key);
    void keyup(unsigned char key);
    void specialdown(int key);
    void specialup(int key);
    void update(glut_time_t dt);
};
