#include "entity.h"

entity::entity() {}

vector3 &entity::position() { return position_; }

void entity::position(scalar_t x, scalar_t y, scalar_t z) {
    position().set(x, y, z);
}

void entity::position(const vector3 &v) { position_ = v; }
