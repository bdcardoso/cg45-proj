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
    unsigned char toggle_key_;

public:
    light_source(GLenum number);

    vector4 &ambient();
    const vector4 &ambient() const;
    vector4 &diffuse();
    const vector4 &diffuse() const;
    vector3 &direction();
    const vector3 &direction() const;
    vector4 &position();
    const vector4 &position() const;
    vector4 &specular();
    const vector4 &specular() const;

    GLdouble &cutoff();
    GLdouble cutoff() const;
    GLdouble &exponent();
    GLdouble exponent() const;
    GLenum &num();
    GLenum num() const;
    bool &on();
    bool on() const;
    unsigned char &toggle_key();
    unsigned char toggle_key() const;

    void draw();
    void keydown(unsigned char key);
    void keyup(unsigned char key);
    void specialdown(int key);
    void specialup(int key);
    void update(glut_time_t dt);
};
