#include "light_source.h"

light_source::light_source(GLenum number) { num_ = number; }

bool light_source::state() const { return state_; }

void light_source::state(bool state) { state_ = state; }

GLenum light_source::num() const { return num_; }

void light_source::ambient(const vector4 &amb) { ambient_ = amb; }

void light_source::position(const vector4 &position) { position_ = position; }

void light_source::direction(const vector3 &direction) {
    direction_ = direction;
}

void light_source::cutoff(GLdouble cutoff) { cutoff_ = cutoff; }

void light_source::exponent(GLdouble exponent) { exponent_ = exponent; }

void light_source::diffuse(const vector4 &diffuse) { diffuse_ = diffuse; }

void light_source::specular(const vector4 &specular) { specular_ = specular; }
