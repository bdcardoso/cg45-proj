#include "frog.h"



void frog::leg::draw() {
    glPushMatrix();
    glTranslatef(-0.15, 0.35, 0.2);
    glRotatef(10, 0.0, 0.0, 1.0);
    glRotatef(40, 0.0, 1.0, 0.0);
    glScalef(1.0, 0.45, 0.45);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15, 0.35, 2.15);
    glRotatef(20, 0.0, 0.0, 1.0);
    glRotatef(10, 0.0, 1.0, 0.0);
    glScalef(1.0, -0.40, 0.40);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.25, 0.05, 2.25);
    glScalef(0.75, 0.1, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9, 0.65, 0.2);
    glRotatef(-30, 0.0, 0.0, 1.0);
    glRotatef(-40, 0.0, 1.0, 0.0);
    glScalef(0.65, 0.3, 0.30);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.75, 0.4, 1.9);
    glRotatef(80, 0.0, 0.0, 1.0);
    glRotatef(-10, 0.0, 1.0, 0.0);
    glScalef(0.7, -0.25, 0.25);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9, 0.05, 1.9);
    glScalef(0.55, 0.1, 0.3);
    glutSolidCube(1.0);
    glPopMatrix();
}
