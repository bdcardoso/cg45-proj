#include "vector4.h"

typedef vector4::scalar_t scalar_t;

vector4::vector4(const vector3 &v) : vector4(v.x(), v.y(), v.z()) {}

vector4::vector4(scalar_t x, scalar_t y, scalar_t z, scalar_t w) {
    coords_[0] = x;
    coords_[1] = y;
    coords_[2] = z;
    coords_[3] = w;
}

const scalar_t *vector4::get() const { return coords_; }

void vector4::set(scalar_t x, scalar_t y, scalar_t z, scalar_t w) {
    coords_[0] = x;
    coords_[1] = y;
    coords_[2] = z;
    coords_[3] = w;
}

scalar_t &vector4::x() { return coords_[0]; }
scalar_t &vector4::y() { return coords_[1]; }
scalar_t &vector4::z() { return coords_[2]; }
scalar_t &vector4::w() { return coords_[3]; }
const scalar_t &vector4::x() const { return coords_[0]; }
const scalar_t &vector4::y() const { return coords_[1]; }
const scalar_t &vector4::z() const { return coords_[2]; }
const scalar_t &vector4::w() const { return coords_[3]; }
