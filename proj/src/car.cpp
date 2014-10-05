#include "car.h"

void car::draw() {
    //Lower Body
    glPushMatrix();
    glTranslatef(0.0f, -0.08f, 0.0f);
    glScalef(0.78125f, 0.16f, 0.0f);
    glPushMatrix();
    glColor3ub(0, 0, 255);
    glTranslatef(1.0f, 1.0f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    //Upper Body
    glPushMatrix();
    glTranslatef(0.0625f, 0.24f, 0.0f);
    glScalef(0.3125f, 0.16f, 0.0f);
    glPushMatrix();
    glColor3ub(0, 0, 255);
    glTranslatef(1.0f, 1.0f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    //Left Triangle
    glPushMatrix();
    glTranslatef(0.75f, 1.08f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 255);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.125f, 0, 0);
    glVertex3f(0, 0.16f, 0);
    glEnd();
    glPopMatrix();

    //Right Triangle
    glPushMatrix();
    glTranslatef(1.375f, 1.08f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 255);
    glVertex3f(0, 0, 0);
    glVertex3f(0.0625f, 0, 0);
    glVertex3f(0, 0.16f, 0);
    glEnd();
    glPopMatrix();

    //Left Wheel
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glTranslatef(0.625f, 0.72f, 0.0f);
    glutSolidTorus(0.02, 0.0625, 20, 20);
    glPopMatrix();

    //Right Wheel
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glTranslatef(1.375f, 0.72f, 0.0f);
    glutSolidTorus(0.02, 0.0625, 20, 20);
    glPopMatrix();
}

void car::update(glut_time_t dt) {
    (void)dt;
}

