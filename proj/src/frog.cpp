#include "frog.h"
#include <cassert>

void frog::leg::draw() {
    glRotatef(20, 0.0, 0.0, 1.0);
    glRotatef(20, 0.0, 1.0, 0.0);
    glScalef(0.95, 0.3, -0.3);
    glutSolidCube(1.0);
}

void frog::leg::update(glut_time_t dt) {
    (void)dt;
}

frog::frog() : _angle(0) {

}

void frog::draw() {
    // Body
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glRotatef(10, 0.0, 0.0, 1.0);
    glScalef(2.0, 0.5, 1.6);
    glutSolidCube(1.0);
    glPopMatrix();

    // Head
    glPushMatrix();
    glColor3ub(255, 0, 0);
    glTranslatef(1.1, 0.45, 0);
    glScalef(1.0, 0.3, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3ub(0, 0, 255);

    // Left leg
    glPushMatrix();
    glTranslatef(-0.2, 0.0, -1.0); 
    glScalef(1.0, 1.0,  1.0); // For symmetry
    _leftleg.draw();
    glPopMatrix();

    // Right leg
    glPushMatrix();
    glTranslatef(-0.2, 0.0,  1.0); 
    glScalef(1.0, 1.0, -1.0);
    _rightleg.draw();
    glPopMatrix();
}

void frog::update(glut_time_t dt) {
    assert(dt != 0);
}


