#include "game_object.h"

game_object::game_object() : scale_(1.0, 1.0, 1.0) {}

vector3 &game_object::scale() { return scale_; }
const vector3 &game_object::scale() const { return scale_; }
void game_object::scale(const GLdouble factor) {
    scale() = vector3(factor, factor, factor);
}

vector3 &game_object::position() { return position_; }
const vector3 &game_object::position() const { return position_; }

class bounding_box &game_object::bounding_box() {
    return bb_;
}
const class bounding_box &game_object::bounding_box() const { return bb_; }

void game_object::draw() {}
void game_object::keydown(unsigned char key) { (void)key; }
void game_object::keyup(unsigned char key) { (void)key; }
void game_object::specialdown(int key) { (void)key; }
void game_object::specialup(int key) { (void)key; }
void game_object::update(glut_time_t dt) { (void)dt; }
