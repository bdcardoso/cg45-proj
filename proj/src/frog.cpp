#include "frog.h"
#include <cassert>

void frog::leg::draw() {
    glPushMatrix();
    glRotatef(25, 0.0, 0.0, 1.0);
    glRotatef(20, 0.0, 1.0, 0.0);
    glScalef(1.35, 0.35, 0.35);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.50, 0.0, 2.15);
    glRotatef(80, 0.0, 0.0, 1.0);
    glRotatef(-20, 0.0, 1.0, 0.0);
    glScalef(0.75, -0.25, 0.25);
    glutSolidCube(1.0);
    glPopMatrix();
}

void frog::leg::update(glut_time_t dt) {
    (void)dt;
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
    glTranslatef(1.1, 0.55, 0);
    glScalef(1.0, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glColor3ub(0, 0, 255);

    // Left leg
    glPushMatrix();
    glTranslatef(-0.3, 0.0, -1.0); 
    glScalef(1.0, 1.0,  1.0); // For symmetry
    _leftleg.draw();
    glPopMatrix();

    // Right leg
    glPushMatrix();
    glTranslatef(-0.3, 0.0,  1.0); 
    glScalef(1.0, 1.0, -1.0);
    _rightleg.draw();
    glPopMatrix();
}

void frog::update(glut_time_t dt) {
    assert(dt != 0);
}


