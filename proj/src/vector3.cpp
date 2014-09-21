#include "vector3.h"

vector3::vector3() : _x(0.0), _y(0.0), _z(0.0) {}
vector3::vector3(double x, double y, double z) : _x(x), _y(y), _z(z) {}

double vector3::x() const {
    return _x;
}

double vector3::y() const {
    return _y;
}

double vector3::z() const {
    return _z;
}

void vector3::x(double newx) {
    _x = newx;
}

void vector3::y(double newy) {
    _y = newy;
}

void vector3::z(double newz) {
    _z = newz;
}

void vector3::set(double x, double y, double z) {
    _x = x;
    _y = y;
    _z = z;
}

vector3 vector3::operator+(const vector3 &rhs) {
    return vector3(_x + rhs._x, _y + rhs._y, _z + rhs._z);
}

vector3 vector3::operator-(const vector3 &rhs) {
    return vector3(_x - rhs._x, _y - rhs._y, _z - rhs._z);
}

vector3 vector3::operator*(double scalar) {
    return vector3(_x * scalar, _y * scalar, _z * scalar);
}

