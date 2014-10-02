#include "river.h"

river::river() {}

void river::draw() {

    // 8B4513
    glColor3ub(0x8b, 0x45, 0x13);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0,  1.0, 0.0);
        glVertex3f( 1.0,  1.0, 0.0);
        glVertex3f( 1.0, -1.0, 0.0);
        glVertex3f(-1.0, -1.0, 0.0);
    glEnd();

    // 4169E1
    glColor3ub(0x41, 0x69, 0xe1);
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.2, 0.0);
        glVertex3f(1.0, 0.2, 0.0);
        glVertex3f(1.0, 0.8, 0.0);
        glVertex3f(0.0, 0.8, 0.0);
    glEnd();
}

void river::update(GLdouble dt) {
    (void)dt;
}

