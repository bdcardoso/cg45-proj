#include "truck.h"

constexpr auto BODY_COLOR_RED = 196, BODY_COLOR_GREEN = 8, BODY_COLOR_BLUE = 49,
               BACK_COLOR_RED = 130, BACK_COLOR_GREEN = 108,
               BACK_COLOR_BLUE = 113, CONTAINER_COLOR_RED = 148,
               CONTAINER_COLOR_GREEN = 87, CONTAINER_COLOR_BLUE = 100,

               // ----
    WHEEL_COLOR_RED = 10, WHEEL_COLOR_GREEN = 10, WHEEL_COLOR_BLUE = 10,
               WHEEL_SIZE_N_SIDES = 15, WHEEL_SIZE_RINGS = 10;

constexpr auto BODY_SIZE_X = 2.0f, BODY_SIZE_Y = 2.0f, BODY_SIZE_Z = 3.0f,
               BODY_COORD_X = 3.0f, BODY_COORD_Y = 2.7f, // 0.01 margin
    BODY_COORD_Z = 0.0f, BACK_SIZE_X = 8.0f, BACK_SIZE_Y = 1.5f,
               BACK_SIZE_Z = 3.0f, BACK_COORD_X = 0.0f, BACK_COORD_Y = 1.0f,
               BACK_COORD_Z = 0.0f, CONTAINER_SIZE_X = 5.0f,
               CONTAINER_SIZE_Y = 2.5f, CONTAINER_SIZE_Z = 3.0f,
               CONTAINER_COORD_X = -1.5f, CONTAINER_COORD_Y = 3.0f,
               CONTAINER_COORD_Z = 0.0f,

               // ----
    WHEEL_SIZE_INNER_RADIUS = 0.3f, WHEEL_SIZE_OUTER_RADIUS = 0.5f,
               WHEEL_COORD_FRONT_LEFT_X = 2.75f,
               WHEEL_COORD_FRONT_LEFT_Y = 0.5f,
               WHEEL_COORD_FRONT_LEFT_Z = -1.5f,
               WHEEL_COORD_FRONT_RIGHT_X = 2.75f,
               WHEEL_COORD_FRONT_RIGHT_Y = 0.5f,
               WHEEL_COORD_FRONT_RIGHT_Z = 1.5f,
               WHEEL_COORD_BACK_LEFT_X = -1.0f, WHEEL_COORD_BACK_LEFT_Y = 0.5f,
               WHEEL_COORD_BACK_LEFT_Z = -1.5f,
               WHEEL_COORD_BACK_RIGHT_X = -2.75f,
               WHEEL_COORD_BACK_RIGHT_Y = 0.5f, WHEEL_COORD_BACK_RIGHT_Z = 1.5f,
               WHEEL_COORD_BACK_LEFT2_X = -2.75f,
               WHEEL_COORD_BACK_LEFT2_Y = 0.5f,
               WHEEL_COORD_BACK_LEFT2_Z = -1.5f,
               WHEEL_COORD_BACK_RIGHT2_X = -1.0f,
               WHEEL_COORD_BACK_RIGHT2_Y = 0.5f,
               WHEEL_COORD_BACK_RIGHT2_Z = 1.5f;

void truck::draw() {
    glColor3ub(BACK_COLOR_RED, BACK_COLOR_GREEN, BACK_COLOR_BLUE);

    // Back
    glPushMatrix();
    glTranslatef(BACK_COORD_X, BACK_COORD_Y, BACK_COORD_Z);
    glScalef(BACK_SIZE_X, BACK_SIZE_Y, BACK_SIZE_Z);
    glutSolidCube(1);
    glPopMatrix();

    // body
    glColor3ub(BODY_COLOR_RED, BODY_COLOR_GREEN, BODY_COLOR_BLUE);

    glPushMatrix();
    glTranslatef(BODY_COORD_X, BODY_COORD_Y, BODY_COORD_Z);
    glScalef(BODY_SIZE_X, BODY_SIZE_Y, BODY_SIZE_Z);
    glutSolidCube(1);
    glPopMatrix();

    glColor3ub(CONTAINER_COLOR_RED, CONTAINER_COLOR_GREEN,
               CONTAINER_COLOR_BLUE);

    // Container
    glPushMatrix();
    glTranslatef(CONTAINER_COORD_X, CONTAINER_COORD_Y, CONTAINER_COORD_Z);
    glScalef(CONTAINER_SIZE_X, CONTAINER_SIZE_Y, CONTAINER_SIZE_Z);
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

    // Back-Left Wheel1
    glPushMatrix();
    glTranslatef(WHEEL_COORD_BACK_LEFT_X, WHEEL_COORD_BACK_LEFT_Y,
                 WHEEL_COORD_BACK_LEFT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Back-Right Wheel1
    glPushMatrix();
    glTranslatef(WHEEL_COORD_BACK_RIGHT_X, WHEEL_COORD_BACK_RIGHT_Y,
                 WHEEL_COORD_BACK_RIGHT_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Back-Left Wheel2
    glPushMatrix();
    glTranslatef(WHEEL_COORD_BACK_LEFT2_X, WHEEL_COORD_BACK_LEFT2_Y,
                 WHEEL_COORD_BACK_LEFT2_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();

    // Back-Right Wheel2
    glPushMatrix();
    glTranslatef(WHEEL_COORD_BACK_RIGHT2_X, WHEEL_COORD_BACK_RIGHT2_Y,
                 WHEEL_COORD_BACK_RIGHT2_Z);
    glutSolidTorus(WHEEL_SIZE_INNER_RADIUS, WHEEL_SIZE_OUTER_RADIUS,
                   WHEEL_SIZE_N_SIDES, WHEEL_SIZE_RINGS);
    glPopMatrix();
}

void truck::update(glut_time_t dt) {
    dynamic_object::update(dt);

    if (position().x() > 2.75) {
        position().x() = -2.90;
    }
}
