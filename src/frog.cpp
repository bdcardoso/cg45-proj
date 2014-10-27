#include "frog.h"
#include "collision_manager.h"
#include "perspective_camera.h"
#include "river.h"
#include "timberlog.h"
#include "turtle.h"
#include <cstdio>

frog::frog() {
    camera_ = std::make_shared<perspective_camera>(90, 1, 0.01, 10);
    bounding_box() = ::bounding_box(-1.3, -1.3, -1.3, 1.3, 1.3, 1.3);
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

    auto collisions = collision_manager::instance().collisions(this);
    if (collisions.size() != 0) {
		GLdouble collisionSpeed = 0;
		
        puts("Frog collision!");
        // position() = vector3(0.0, 0.05, 1.95);
        
        bool touchesRiver  = false,
             touchesLog    = false,
             touchesTurtle = false,
             touchesOther  = false;

        for (auto col : collisions) {
            std::shared_ptr<game_object> obj;
            class bounding_box bb;
            std::tie(bb, obj) = col;

            if (dynamic_cast<river *>(obj.get()) != nullptr) {
                puts("Frog touching river!");
                touchesRiver = true;
                continue;
            }
            else if (dynamic_cast<timberlog *>(obj.get()) != nullptr) {
                puts("Frog touching timberlog!");
                touchesLog = true;
                collisionSpeed = std::max(collisionSpeed, ((timberlog *)obj.get())->speed().x());
                continue;             
		    }   
            else if (dynamic_cast<turtle *>(obj.get()) != nullptr) {
                puts("Frog touching turtle!");
                touchesTurtle = true;
                collisionSpeed = std::max(collisionSpeed, ((turtle *)obj.get())->speed().x());
                continue;                
            }
            else {
                puts("Frog touching other!");
                touchesOther = true;
                break;
            }
        }
        
        position().x() += collisionSpeed * dt;
        
        if (touchesOther || (touchesRiver && !(touchesLog || touchesTurtle))) {
            position() = vector3(0.0, 0.05, 1.95);            
        }
    }

    position().x() = position().x() < -1.85 ? -1.85 : position().x();
    position().x() = position().x() > 1.85 ? 1.85 : position().x();
    position().z() = position().z() < -1.90 ? -1.90 : position().z();
    position().z() = position().z() > 1.90 ? 1.90 : position().z();

    camera_->eye() = position() + vector3(0, 1.5, 0.5);
    camera_->at() = position();
    camera_->up() = vector3(0.0, 1.0, 0.0);
}

void frog::keydown(unsigned char key) {
    switch (key) {
    case 'o':
        speed().x() -= SPEED_X;
        break;
    case 'p':
        speed().x() += SPEED_X;
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
        break;
    case 'p':
        speed().x() -= SPEED_X;
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
