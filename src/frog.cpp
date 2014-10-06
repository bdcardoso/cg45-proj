#include "frog.h"
#include <cassert>
#include <cstdio>

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

void frog::leg::update(glut_time_t dt) {
    (void)dt;
}

void frog::draw() {
    glColor3ub(5, 55, 5);

    // Body
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
    assert(dt != 0);
    dynamic_object::update(dt);
    
    speed(0, 0, 0);
}

void frog::leg::keypress(unsigned char key) {
	(void)key;
}

void frog::keypress(unsigned char key) {
	static const vector3 FROG_SPEED(5.0, 0.0, 0.0);
	
	// FIXME
	switch (key) {
	case 'a':
		speed(FROG_SPEED * -1);
		break;
	case 'd':
		speed(FROG_SPEED);
		break;
	}
}

