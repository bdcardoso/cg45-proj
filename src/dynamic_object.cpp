#include "dynamic_object.h"

dynamic_object::dynamic_object() {}

// By default we just advance the position
void dynamic_object::update(glut_time_t dt) {
    game_object::update(dt);
    position() += speed() * dt;
}

vector3 &dynamic_object::speed() { return speed_; }

void dynamic_object::speed(scalar_t x, scalar_t y, scalar_t z) {
    speed().set(x, y, z);
}

void dynamic_object::speed(const vector3 &s) { speed_ = s; }
