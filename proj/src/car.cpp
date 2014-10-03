#include "car.h"

void car::draw() {
    // Frame
    glColor3ub(255, 0, 0);
    glPushMatrix();
    glScalef(4.0, 0.4, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3ub(0, 255, 0);
    // Wheels
    glPushMatrix();
    glTranslatef(0.0, 2.0, 0.0);
    glutSolidTorus(0.5, 1.5, 20, 20);
    glPopMatrix();
}

void car::update(glut_time_t dt) {
    (void)dt;
}

