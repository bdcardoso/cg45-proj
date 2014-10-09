#include "frog.h"

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

