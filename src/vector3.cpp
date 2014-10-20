#include "vector3.h"

vector3::vector3(GLdouble x, GLdouble y, GLdouble z) {
    _coords[0] = x;
    _coords[1] = y;
    _coords[2] = z;
}

GLdouble vector3::x() const { return _coords[0]; }

GLdouble vector3::y() const { return _coords[1]; }

GLdouble vector3::z() const { return _coords[2]; }

void vector3::x(GLdouble newx) { _coords[0] = newx; }

void vector3::y(GLdouble newy) { _coords[1] = newy; }

void vector3::z(GLdouble newz) { _coords[2] = newz; }

void vector3::set(GLdouble x, GLdouble y, GLdouble z) {
    _coords[0] = x;
    _coords[1] = y;
    _coords[2] = z;
}

const GLdouble *vector3::get() const { return _coords; }

vector3 vector3::operator+(const vector3 &rhs) const {
    return vector3(x() + rhs.x(), y() + rhs.y(), z() + rhs.z());
}

vector3 &vector3::operator+=(const vector3 &rhs) {
    x(x() + rhs.x());
    y(y() + rhs.y());
    z(z() + rhs.z());
    return *this;
}

vector3 vector3::operator-(const vector3 &rhs) const {
    return vector3(x() - rhs.x(), y() - rhs.y(), z() - rhs.z());
}

vector3 vector3::operator*(GLdouble scalar) const {
    return vector3(x() * scalar, y() * scalar, z() * scalar);
}
