#include "frog.h"
#include "perspective_camera.h"

frog::frog() {
    camera_ = std::make_shared<perspective_camera>(90, 1, 0.01, 10);
    bounding_box() = ::bounding_box(-1.0, -1.0, -1.0,
                                     1.0,  1.0,  1.0);
}

std::shared_ptr<camera> frog::cam() { return camera_; }

void frog::draw() {
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);

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
    glScalef(1.0, 1.0, 1.0); // For symmetry
    leftleg_.draw();
    glPopMatrix();

    // Right leg
    glTranslatef(-0.3, 0.0, 1.0);
    glScalef(1.0, 1.0, -1.0);
    rightleg_.draw();
    glPopMatrix();
}

void frog::update(glut_time_t dt) {
    dynamic_object::update(dt);



    if (position().x() < -1.85) {
        auto newPos = position();
        newPos.x(-1.85);
        position(newPos);
    }

    if (position().x() > 1.85) {
        auto newPos = position();
        newPos.x(1.85);
        position(newPos);
    }

    if (position().z() < -1.9) {
        auto newPos = position();
        newPos.z(-1.9);
        position(newPos);
    }

    if (position().z() > 1.9) {
        auto newPos = position();
        newPos.z(1.9);
        position(newPos);
    }

    camera_->eye() = position() + vector3(0, 1.5, 0.5);
    camera_->at() = position();
    camera_->up() = vector3(0.0, 1.0, 0.0);
}

void frog::keydown(unsigned char key) {
    switch (key) {
    case 'o':
        speed(speed() - vector3(SPEED_X, 0, 0));
        break;
    case 'p':
        speed(speed() + vector3(SPEED_X, 0, 0));
        break;
    case 'q':
        speed(speed() - vector3(0, 0, SPEED_Z));
        break;
    case 'a':
        speed(speed() + vector3(0, 0, SPEED_Z));
        break;
    default:
        break;
    }
}

void frog::keyup(unsigned char key) {
    switch (key) {
    case 'o':
        speed(speed() + vector3(SPEED_X, 0, 0));
        break;
    case 'p':
        speed(speed() - vector3(SPEED_X, 0, 0));
        break;
    case 'q':
        speed(speed() + vector3(0, 0, SPEED_Z));
        break;
    case 'a':
        speed(speed() - vector3(0, 0, SPEED_Z));
        break;
    default:
        break;
    }
}
