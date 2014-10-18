#include "game_object.h"

game_object::game_object() : _scale(1.0, 1.0, 1.0) {}

vector3 &game_object::scale() {
    return _scale;
}

void game_object::scale(const vector3 &s) {
    _scale = s;
}

void game_object::scale(const GLdouble factor) {
    _scale = vector3(factor, factor, factor);
}

