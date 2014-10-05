#include "river.h"
#include <cassert>

constexpr auto RIVER_LENGTH = 5.0,
               RIVER_WIDTH  = 2.0,
               RIVER_HEIGHT = 1.0,
               RIVER_BOTTOM = 0.1,
               RIVER_MARGIN = 0.2,
               WATER_DEPTH  = 0.8,
               // ----
               BOTTOM_RAISE = -RIVER_HEIGHT / 2,
               MARGIN_DELTA = (RIVER_WIDTH - RIVER_MARGIN) / 2,
               MARGIN_HEIGHT = RIVER_HEIGHT - RIVER_BOTTOM,
               WATER_RAISE = -(MARGIN_HEIGHT - WATER_DEPTH) / 2,
               WATER_WIDTH = RIVER_WIDTH - 2*RIVER_MARGIN;


river::river() {
    assert(RIVER_LENGTH > 0 && RIVER_WIDTH > 0 && RIVER_HEIGHT > 0 && RIVER_MARGIN > 0 && WATER_DEPTH > 0 && RIVER_BOTTOM > 0);
    assert(RIVER_WIDTH > 2*RIVER_MARGIN);
    assert(WATER_DEPTH <= MARGIN_HEIGHT);
}

void river::draw() {
    glColor3ub(0x8b, 0x45, 0x13);

    // Left margin
    glPushMatrix();
        glTranslatef(0.0, 0.0, -MARGIN_DELTA);
        glScalef(RIVER_LENGTH, MARGIN_HEIGHT, RIVER_MARGIN);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right margin
    glPushMatrix();
        glTranslatef(0.0, 0.0,  MARGIN_DELTA);
        glScalef(RIVER_LENGTH, MARGIN_HEIGHT, RIVER_MARGIN);
        glutSolidCube(1.0);
    glPopMatrix();
    
    // Bottom
    glPushMatrix();
        glTranslatef(0.0, BOTTOM_RAISE, 0.0);
        glScalef(RIVER_LENGTH, RIVER_BOTTOM, RIVER_WIDTH);
        glutSolidCube(1.0);
    glPopMatrix();
    

    // Water
    glColor3ub(0x41, 0x69, 0xe1);
    glPushMatrix();
        glTranslatef(0.0, WATER_RAISE, 0.0);
        glScalef(RIVER_LENGTH, WATER_DEPTH, WATER_WIDTH);
        glutSolidCube(1.0);
    glPopMatrix();
}

void river::update(glut_time_t dt) {
    (void)dt;
}

