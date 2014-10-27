#include "timberlog.h"

constexpr auto COLOR_RED = 255, COLOR_GREEN = 100, COLOR_BLUE = 20, SLICES = 20,
               STACKS = 20;

constexpr auto RADIUS_0 = 0.5f, RADIUS_Z = 0.5f, HEIGHT = 6.0f,
               COORD_X = HEIGHT / -2, COORD_Y = 0.0f, COORD_Z = 0.0f;

void timberlog::draw() {
    glColor3ub(COLOR_RED, COLOR_GREEN, COLOR_BLUE);

    // Timberlog
    glPushMatrix();
    glTranslatef(COORD_X, COORD_Y, COORD_Z);
    glRotatef(90, 0.0, 1.0, 0.0);
    glScalef(3.0, 1.0, 1.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, HEIGHT, SLICES, STACKS);
    glPopMatrix();
}

void timberlog::update(glut_time_t dt) {
    dynamic_object::update(dt);
    
    if(speed().x() < 4.0){
		speed().x() += 0.001;
	}

    if (position().x() > 2.75) {
        position().x() = -2.90;
    }
}
