#include "game_object.h"

game_object::game_object() : scale_(1.0, 1.0, 1.0) {}

vector3 &game_object::scale() { return scale_; }

void game_object::scale(const vector3 &s) { scale_ = s; }

void game_object::scale(const GLdouble factor) {
    scale_ = vector3(factor, factor, factor);
}
