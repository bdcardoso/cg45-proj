#include "dynamic_object.h"
#include "vector3.h"
#include "opengl.h"

dynamic_object::dynamic_object() {}

// By default we just advance the position
void dynamic_object::update(GLdouble dt) {
    _position += _speed * dt;
}

void dynamic_object::speed(GLdouble x, GLdouble y, GLdouble z) {
    _speed.set(x, y, z);
}

void dynamic_object::speed(const vector3 &s) {
    _speed = s;
}
