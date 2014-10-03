#include "car.h"

void car::draw() {
    glutSolidSphere(1.0, 9, 9);
}

void car::update(glut_time_t dt) {
    (void)dt;
}

