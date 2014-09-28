#include "vector4.h"

vector4::vector4(const vector3 &in) : vector4(in.x(), in.y(), in.z(), 0) {}

vector4::vector4(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    _coords[0] = x;
    _coords[1] = y;
    _coords[2] = z;
    _coords[3] = w;
}

GLdouble vector4::x() const {
    return _coords[0];
}

void vector4::x(GLdouble newx) {
    _coords[0] = newx;
}

GLdouble vector4::y() const {
    return _coords[1];
}

void vector4::y(GLdouble newy) {
    _coords[1] = newy;
}

GLdouble vector4::z() const {
    return _coords[2];
}

void vector4::z(GLdouble newz) {
  _coords[2] = newz;
}

GLdouble vector4::w() const {
    return _coords[3];
}

void vector4::w(GLdouble neww) {
  _coords[3] = neww;
}

void vector4::set(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
  _coords[0] = x;
  _coords[1] = y;
  _coords[2] = z;
  _coords[3] = w;
}

const GLdouble *vector4::get() const {
  return _coords;
}

vector4 vector4::operator+(const vector4 &rhs) const {
  return vector4(x() + rhs.x(), y() + rhs.y(), z() + rhs.z(), w() + rhs.w());
}
