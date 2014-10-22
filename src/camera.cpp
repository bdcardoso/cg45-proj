#include "camera.h"

camera::camera(GLdouble near, GLdouble far) : near_(near), far_(far) {}

void camera::up(const vector3 &upv) { up_ = upv.normalized(); }
vector3 &camera::up() { return up_; }
void camera::eye(const vector3 &eyev) { position(eyev); }
vector3 &camera::eye() { return position(); }
void camera::at(const vector3 &atv) { at_ = atv.normalized(); }
vector3 &camera::at() { return at_; }
