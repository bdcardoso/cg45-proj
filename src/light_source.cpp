#include "light_source.h"

light_source::light_source(GLenum number) {
    num_ = number;
    state_ = true;

    ambient_.set(0.2, 0.2, 0.2, 1.0);
    diffuse_.set(1.0, 1.0, 1.0, 1.0);
    specular_.set(0.0, 0.0, 0.0, 1.0);
    position_.set(0.0, 50000.0, 0.0, 0.0);
    direction_.set(0.0, 0.0, -1.0);

    glEnable(num_);
}

vector4 light_source::position() { return position_; }

void light_source::draw() {
    glLightfv(num_, GL_AMBIENT, ambient_.get());
    glLightfv(num_, GL_DIFFUSE, diffuse_.get());
    glLightfv(num_, GL_SPECULAR, specular_.get());
    glLightfv(num_, GL_POSITION, position_.get());
    glLightfv(num_, GL_SPOT_DIRECTION, direction_.get());
}

void light_source::keydown(unsigned char key) {}
void light_source::keyup(unsigned char key) {
    switch (key) {
    case 'n':
        if (state_)
            glDisable(num_);
        else
            glEnable(num_);
        state_ = !state_;
        break;
    default:
        break;
    }
}

void light_source::specialdown(int key) {}
void light_source::specialup(int key) {}
void light_source::update(glut_time_t dt) {}
