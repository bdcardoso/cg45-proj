#include "bus.h"

constexpr auto BODY_COLOR_RED = 255, BODY_COLOR_GREEN = 50,
               BODY_COLOR_BLUE = 50,
               // ----
    WHEEL_COLOR_RED = 10, WHEEL_COLOR_GREEN = 10, WHEEL_COLOR_BLUE = 10,
               WHEEL_SIZE_N_SIDES = 15, WHEEL_SIZE_RINGS = 15;

constexpr auto BODY_SIZE_X = 11.0f, BODY_SIZE_Y = 3.0f, BODY_SIZE_Z = 3.0f,
               BODY_COORD_X = 0.0f, BODY_COORD_Y = 2.0f, BODY_COORD_Z = 0.0f,
               // ----
    WHEEL_SIZE_INNER_RADIUS = 0.3f, WHEEL_SIZE_OUTER_RADIUS = 0.5f,
               WHEEL_COORD_FRONT_LEFT_X = 3.5f, WHEEL_COORD_FRONT_LEFT_Y = 0.5f,
               WHEEL_COORD_FRONT_LEFT_Z = -1.5f,
               WHEEL_COORD_FRONT_RIGHT_X = 3.5f,
               WHEEL_COORD_FRONT_RIGHT_Y = 0.5f,
               WHEEL_COORD_FRONT_RIGHT_Z = 1.5f,
               WHEEL_COORD_BACK_LEFT_X = -3.5f, WHEEL_COORD_BACK_LEFT_Y = 0.5f,
               WHEEL_COORD_BACK_LEFT_Z = -1.5f,
               WHEEL_COORD_BACK_RIGHT_X = -3.5f,
               WHEEL_COORD_BACK_RIGHT_Y = 0.5f, WHEEL_COORD_BACK_RIGHT_Z = 1.5f;

void bus::draw() {
    glColor3ub(BODY_COLOR_RED, BODY_COLOR_GREEN, BODY_COLOR_BLUE);

    // Body
    glPushMatrix();
    glTranslatef(BODY_COORD_X, BODY_COORD_Y, BODY_COORD_Z);
    glScalef(BODY_SIZE_X, BODY_SIZE_Y, BODY_SIZE_Z);
    glutSolidCube(1);
    glPopMatrix();

    glColor3ub(WHEEL_COLOR_RED, WHEEL_COLOR_GREEN, WHEEL_COLOR_BLUE);

    // Front-Left Wheel
    glPushMatrix();
    glTranslatef(WHEEL_COORD_FRONT_LEFT_X, WHEEL_COORD_FRONT_LEFT_Y,
                 WHEEL_COORD_FRONT_LEFT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Front-Right Wheel
    glPushMatrix();
    glTranslatef(WHEEL_COORD_FRONT_RIGHT_X, WHEEL_COORD_FRONT_RIGHT_Y,
                 WHEEL_COORD_FRONT_RIGHT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Back-Left Wheel
    glPushMatrix();
    glTranslatef(WHEEL_COORD_BACK_LEFT_X, WHEEL_COORD_BACK_LEFT_Y,
                 WHEEL_COORD_BACK_LEFT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Back-Right Wheel
    glPushMatrix();
    glTranslatef(WHEEL_COORD_BACK_RIGHT_X, WHEEL_COORD_BACK_RIGHT_Y,
                 WHEEL_COORD_BACK_RIGHT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();
}

void bus::update(glut_time_t dt) {
    dynamic_object::update(dt);

    if (position().x() > 2.75) {
        auto newPos = position();
        newPos.x(-2.90);
        position(newPos);
    }
}
