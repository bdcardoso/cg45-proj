#include "vector3.h"

typedef vector3::scalar_t scalar_t;

vector3::vector3(scalar_t x, scalar_t y, scalar_t z) {
    coords_[0] = x;
    coords_[1] = y;
    coords_[2] = z;
}

scalar_t &vector3::x() { return coords_[0]; }
const scalar_t &vector3::x() const { return coords_[0]; }
scalar_t &vector3::y() { return coords_[1]; }
const scalar_t &vector3::y() const { return coords_[1]; }
scalar_t &vector3::z() { return coords_[2]; }
const scalar_t &vector3::z() const { return coords_[2]; }

const scalar_t *vector3::get() const { return coords_; }

void vector3::set(scalar_t x, scalar_t y, scalar_t z) {
    coords_[0] = x;
    coords_[1] = y;
    coords_[2] = z;
}

vector3 operator+(const vector3 &lhs, const vector3 &rhs) {
    return vector3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

vector3 &operator+=(vector3 &lhs, const vector3 &rhs) {
    lhs.set(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
    return lhs;
}

vector3 operator-(const vector3 &lhs, const vector3 &rhs) {
    return vector3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

vector3 &operator-=(vector3 &lhs, const vector3 &rhs) {
    lhs.set(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
    return lhs;
}

vector3 operator*(const vector3 &lhs, const scalar_t &rhs) {
    return vector3(lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs);
}

vector3 operator*(const scalar_t &lhs, const vector3 &rhs) { return rhs * lhs; }

vector3 operator/(const vector3 &lhs, const scalar_t &rhs) {
    return vector3(lhs.x() / rhs, lhs.y() / rhs, lhs.z() / rhs);
}
