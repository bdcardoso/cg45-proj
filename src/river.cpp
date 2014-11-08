#include "river.h"
#include "materials.h"
#include <cassert>

constexpr auto RIVER_LENGTH = 5.0, RIVER_WIDTH = 2.0, RIVER_HEIGHT = 1.0,
               RIVER_BOTTOM = 0.1, RIVER_MARGIN = 0.2, WATER_DEPTH = 0.8,
               RIVER_MARGIN_RED = 165.0, RIVER_MARGIN_GREEN = 42.0,
               RIVER_MARGIN_BLUE = 42.0, RIVER_WATER_RED = 65.0,
               RIVER_WATER_GREEN = 65.0, RIVER_WATER_BLUE = 225.0;

// ----

constexpr auto MARGIN_DELTA = (RIVER_WIDTH - RIVER_MARGIN) / 2,
               MARGIN_HEIGHT = RIVER_HEIGHT - RIVER_BOTTOM,
               WATER_RAISE = -(MARGIN_HEIGHT - WATER_DEPTH) / 2,
               WATER_WIDTH = RIVER_WIDTH - 2 * RIVER_MARGIN;

river::river() {
    assert(RIVER_LENGTH > 0 && RIVER_WIDTH > 0 && RIVER_HEIGHT > 0 &&
           RIVER_MARGIN > 0 && WATER_DEPTH > 0 && RIVER_BOTTOM > 0);
    assert(RIVER_WIDTH > 2 * RIVER_MARGIN);
    assert(WATER_DEPTH <= MARGIN_HEIGHT);
    scale().y() = 0.1;

    bounding_box() =
        ::bounding_box(-RIVER_LENGTH / 2, 0, 0.8 * -WATER_WIDTH / 2,
                       RIVER_LENGTH / 2, 0, 0.8 * WATER_WIDTH / 2);
}

void river::draw() {

    glColor3ub(RIVER_MARGIN_RED, RIVER_MARGIN_GREEN, RIVER_MARGIN_BLUE);
    materials::river_margin.use();

    // Left margin
    glPushMatrix();
    glTranslatef(0.0, 0.0, -MARGIN_DELTA);
    glScalef(RIVER_LENGTH, MARGIN_HEIGHT, RIVER_MARGIN);
    gluxSlicedCube(20, 1, 2);
    glPopMatrix();

    // Right margin
    glPushMatrix();
    glTranslatef(0.0, 0.0, MARGIN_DELTA);
    glScalef(RIVER_LENGTH, MARGIN_HEIGHT, RIVER_MARGIN);
    gluxSlicedCube(20, 1, 2);
    glPopMatrix();

    // Water

    glColor3ub(RIVER_WATER_RED, RIVER_WATER_GREEN, RIVER_WATER_BLUE);
    materials::water.use();

    glPushMatrix();
    glTranslatef(0.0, WATER_RAISE, 0.0);
    glScalef(RIVER_LENGTH, WATER_DEPTH, WATER_WIDTH);
    gluxSlicedCube(20, 1, 8);
    glPopMatrix();
}

void river::update(glut_time_t dt) { (void)dt; }
