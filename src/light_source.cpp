#include "light_source.h"

light_source::light_source(GLenum number) { _num = number; }

bool light_source::state() const { return _state; }

void light_source::state(bool state) { _state = state; }

GLenum light_source::num() const { return _num; }

void light_source::ambient(const vector4 &amb) { _ambient = amb; }

void light_source::position(const vector4 &position) { _position = position; }

void light_source::direction(const vector3 &direction) {
    _direction = direction;
}

void light_source::cutoff(GLdouble cutoff) { _cutoff = cutoff; }

void light_source::exponent(GLdouble exponent) { _exponent = exponent; }

void light_source::diffuse(const vector4 &diffuse) { _diffuse = diffuse; }

void light_source::specular(const vector4 &specular) { _specular = specular; }
