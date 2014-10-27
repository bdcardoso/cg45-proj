#include "game_object.h"

game_object::game_object() : scale_(1.0, 1.0, 1.0) {}

vector3 &game_object::scale() { return scale_; }
const vector3 &game_object::scale() const { return scale_; }

void game_object::scale(const GLdouble factor) {
    scale() = vector3(factor, factor, factor);
}

const class bounding_box &game_object::bounding_box() const { return bb_; }
class bounding_box &game_object::bounding_box() {
    return bb_;
}
