#include "vector4.h"

vector4::vector4() : vector4(0, 0, 0, 0) {
}

vector4::vector4(const vector3 &in) : vector4(in.x(), in.y(), in.z(), 0) {
}

vector4::vector4(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _coords[0] = x;
    _coords[1] = y;
    _coords[2] = z;
    _coords[3] = w;
}

GLdouble vector4::x() {
    return _coords[0];
}

GLdouble vector4::y() {
    return _coords[1];
}

GLdouble vector4::z() {
    return _coords[2];
}

GLdouble vector4::w() {
    return _coords[3];
}

