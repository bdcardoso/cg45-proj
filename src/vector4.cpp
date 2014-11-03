#include "vector4.h"

typedef vector4::scalar_t scalar_t;

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
