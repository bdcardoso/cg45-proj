#include "vector4.h"

vector4::vector4(const vector3 &in) : vector4(in.x(), in.y(), in.z(), 0) {}

vector4::vector4(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    coords_[0] = x;
    coords_[1] = y;
    coords_[2] = z;
    coords_[3] = w;
}

GLdouble vector4::x() const { return coords_[0]; }

void vector4::x(GLdouble newx) { coords_[0] = newx; }

GLdouble vector4::y() const { return coords_[1]; }

void vector4::y(GLdouble newy) { coords_[1] = newy; }

GLdouble vector4::z() const { return coords_[2]; }

void vector4::z(GLdouble newz) { coords_[2] = newz; }

GLdouble vector4::w() const { return coords_[3]; }

void vector4::w(GLdouble neww) { coords_[3] = neww; }

void vector4::set(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    coords_[0] = x;
    coords_[1] = y;
    coords_[2] = z;
    coords_[3] = w;
}

const GLdouble *vector4::get() const { return coords_; }

vector4 vector4::operator+(const vector4 &rhs) const {
    return vector4(x() + rhs.x(), y() + rhs.y(), z() + rhs.z(), w() + rhs.w());
}
