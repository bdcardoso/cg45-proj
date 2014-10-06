#include "road.h"
#include <cassert>

constexpr auto ROAD_LENGTH = 5.0,
               ROAD_WIDTH  = 2.0,
               ROAD_HEIGHT = 1.0,
               ROAD_BOTTOM = 0.1,
               ROAD_MARGIN = 0.2,
               TAR_DEPTH  = 0.8,
               // ----
               BOTTOM_RAISE = -ROAD_HEIGHT / 2,
               MARGIN_DELTA = (ROAD_WIDTH - ROAD_MARGIN) / 2,
               MARGIN_HEIGHT = ROAD_HEIGHT - ROAD_BOTTOM,
               TAR_RAISE = -(MARGIN_HEIGHT - TAR_DEPTH) / 2,
               TAR_WIDTH = ROAD_WIDTH - 2*ROAD_MARGIN;


road::road() {
    assert(ROAD_LENGTH > 0 && ROAD_WIDTH > 0 && ROAD_HEIGHT > 0 && ROAD_MARGIN > 0 && TAR_DEPTH > 0 && ROAD_BOTTOM > 0);
    assert(ROAD_WIDTH > 2*ROAD_MARGIN);
    assert(TAR_DEPTH <= MARGIN_HEIGHT);
}

void road::draw() {
    glColor3ub(120, 120, 120);

    // Left margin
    glPushMatrix();
        glTranslatef(0.0, 0.0, -MARGIN_DELTA);
        glScalef(ROAD_LENGTH, MARGIN_HEIGHT, ROAD_MARGIN);
        glutSolidCube(1.0);
    glPopMatrix();

    // Right margin
    glPushMatrix();
        glTranslatef(0.0, 0.0,  MARGIN_DELTA);
        glScalef(ROAD_LENGTH, MARGIN_HEIGHT, ROAD_MARGIN);
        glutSolidCube(1.0);
    glPopMatrix();
    
    // Bottom
    glPushMatrix();
        glTranslatef(0.0, BOTTOM_RAISE, 0.0);
        glScalef(ROAD_LENGTH, ROAD_BOTTOM, ROAD_WIDTH);
        glutSolidCube(1.0);
    glPopMatrix();
    

    // Water
    glColor3ub(30, 30, 30);
    glPushMatrix();
        glTranslatef(0.0, TAR_RAISE, 0.0);
        glScalef(ROAD_LENGTH, TAR_DEPTH, TAR_WIDTH);
        glutSolidCube(1.0);
    glPopMatrix();
}

void road::update(glut_time_t dt) {
    (void)dt;
}