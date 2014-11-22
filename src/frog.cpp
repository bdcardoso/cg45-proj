#include "frog.h"
#include "collision_manager.h"
#include "game_manager.h"
#include "perspective_camera.h"
#include "river.h"
#include "timberlog.h"
#include "turtle.h"
#include "materials.h"
#include <cassert>
#include <cmath>
#include <cstdio>

constexpr auto FROG_COLOR_RED = 5, FROG_COLOR_GREEN = 55, FROG_COLOR_BLUE = 55;

frog::frog() {
    camera_ = std::make_shared<perspective_camera>(90, 1, 0.01, 10);
    headlight_ = std::make_shared<light_source>(GL_LIGHT7);
    bounding_box() = ::bounding_box(-1.3, -1.3, -1.3, 1.3, 1.3, 1.3);

    headlight()->exponent() = 15;
    headlight()->cutoff() = 30;
    headlight()->toggle_key() = 'h';
}

std::shared_ptr<camera> frog::cam() { return camera_; }
std::shared_ptr<light_source> frog::headlight() { return headlight_; }



void frog::draw() {
    glPushMatrix();
    glRotatef(90+orientation_, 0.0, 1.0, 0.0);

    glColor3ub(FROG_COLOR_RED, FROG_COLOR_GREEN, FROG_COLOR_BLUE);
    materials::skin_green.use();

    // Body
    glPushMatrix();
    glTranslatef(0.0, 0.55, 0.0);
    glRotatef(10, 0.0, 0.0, 1.0);
    glScalef(2.0, 0.75, 1.5);
    gluxSlicedCube(8, 3, 6);
    glPopMatrix();

    // Head
    glPushMatrix();
    glTranslatef(1.1, 0.75, 0);
    glScalef(0.75, 0.70, 1.25);
    gluxSlicedCube(3, 3, 5);
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

    auto collisions = collision_manager::instance().collisions(this);
    if (collisions.size() != 0) {
        vector3::scalar_t collisionSpeed = 0;

        bool touchesRiver = false, touchesLog = false, touchesTurtle = false,
             touchesOther = false;

        for (auto col : collisions) {
            std::shared_ptr<game_object> obj;
            dynamic_object *dyn = nullptr;
            class bounding_box bb;

            std::tie(bb, obj) = col;

            if (dynamic_cast<river *>(obj.get()) != nullptr) {
                touchesRiver = true;
                continue;
            } else if ((dyn = dynamic_cast<timberlog *>(obj.get())) !=
                       nullptr) {
                touchesLog = true;
                collisionSpeed = std::max(collisionSpeed, dyn->speed().x());
                continue;
            } else if ((dyn = dynamic_cast<turtle *>(obj.get())) != nullptr) {
                touchesTurtle = true;
                collisionSpeed = std::max(collisionSpeed, dyn->speed().x());
                continue;
            } else if ((dyn = dynamic_cast<frog *>(obj.get())) != nullptr) {
                assert(!"Frog should not collide with himself!");
            } else {
                touchesOther = true;
                break;
            }
        }

        position().x() += collisionSpeed * dt;

        if (touchesOther || (touchesRiver && !(touchesLog || touchesTurtle))) {
            position() = vector3(0.0, 0.05, 1.95);
        }
    }

    position().x() =
        std::fmax(position().x(), game_manager::instance().frog_bounds().x1());
    position().x() =
        std::fmin(position().x(), game_manager::instance().frog_bounds().x2());
    position().z() =
        std::fmax(position().z(), game_manager::instance().frog_bounds().z1());
    position().z() =
        std::fmin(position().z(), game_manager::instance().frog_bounds().z2());

    headlight()->position() = position() + vector3(0.0, 1.1, 0.0);
    headlight()->position().w() = 1;
    headlight()->direction() = vector3(0.0, -3.0, -2.0).norm();
    headlight()->diffuse().set(0.7, 0.7, 0.7, 1.0);

    cam()->eye() = position() + vector3(0, 1.5, 0.5);
    cam()->at() = position() + vector3(0.0, 0.0, -0.5);
    cam()->up() = vector3(0.0, 1.0, 0.0);
}

void frog::keydown(unsigned char key) {
    switch (key) {
    case 'o':
        speed().x() -= SPEED_X;
        orientation_ += 45;
        break;
    case 'p':
        speed().x() += SPEED_X;
        orientation_ -= 45;
        break;
    case 'q':
        speed().z() -= SPEED_Z;
        break;
    case 'a':
        speed().z() += SPEED_Z;
        break;
    default:
        break;
    }
}

void frog::keyup(unsigned char key) {
    switch (key) {
    case 'o':
        speed().x() += SPEED_X;
        orientation_ -= 45;
        break;
    case 'p':
        speed().x() -= SPEED_X;
        orientation_ += 45;
        break;
    case 'q':
        speed().z() += SPEED_Z;
        break;
    case 'a':
        speed().z() -= SPEED_Z;
        break;
    default:
        break;
    }
}
