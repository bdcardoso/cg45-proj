#include "frog.h"
#include <cassert>

void frog::draw() {
    glColor3ub(5, 55, 5);

    glPushMatrix();
        glTranslatef(0.0, 0.55, 0.0);
        glRotatef(10, 0.0, 0.0, 1.0);
        glScalef(2.0, 0.75, 1.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // Head
    glPushMatrix();
        glTranslatef(1.1, 0.75, 0);
        glScalef(0.75, 0.70, 1.25);
        glutSolidCube(1.0);
    glPopMatrix();

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
    dynamic_object::update(dt);
}

void frog::keydown(unsigned char key) {
    switch (key) {
    case 'o':
        speed(speed() - vector3(SPEED_X, 0, 0));
        break;
    case 'p':
        speed(speed() + vector3(SPEED_X, 0, 0));
        break;
    case 'q':
        speed(speed() - vector3(0, 0, SPEED_Z));
        break;
    case 'a':
        speed(speed() + vector3(0, 0, SPEED_Z));
        break;
    default:
        break;
    }
}

void frog::keyup(unsigned char key) {
    switch (key) {
    case 'o':
        speed(speed() + vector3(SPEED_X, 0, 0));
        break;
    case 'p':
        speed(speed() - vector3(SPEED_X, 0, 0));
        break;
    case 'q':
        speed(speed() + vector3(0, 0, SPEED_Z));
        break;
    case 'a':
        speed(speed() - vector3(0, 0, SPEED_Z));
        break;
    default:
        break;
    }
}

