#include "dynamic_object.h"
#include "vector3.h"
#include "opengl.h"

//STILL MISSING FIRST FUNCTION

void dynamic_object::update(GLdouble delta_t){
//TODO

}

void dynamic_object::speed(GLdouble x, GLdouble y, GLdouble z) {
    speed(vector3(x, y, z));

}

void dynamic_object::speed(const vector3 &s) {
    _speed = s;
}
