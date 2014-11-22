#include "light_source.h"

light_source::light_source(GLenum number) {
    num_ = number;
    state_ = false;
    glDisable(num_);
    cutoff_ = 180;
    exponent_ = 0.0;
}

void light_source::draw() {
    if (on()) {
        glLightfv(num_, GL_AMBIENT, ambient().get());
        glLightfv(num_, GL_DIFFUSE, diffuse().get());
        glLightfv(num_, GL_SPECULAR, specular().get());
        glLightfv(num_, GL_POSITION, position().get());
        glLightfv(num_, GL_SPOT_DIRECTION, direction().get());
        glLightf(num_, GL_SPOT_CUTOFF, cutoff());
        glLightf(num_, GL_SPOT_EXPONENT, exponent());
    }
}

void light_source::keydown(unsigned char key) { (void)key; }
void light_source::keyup(unsigned char key) {
    if (key == toggle_key()) {
        if (state_)
            glDisable(num_);
        else
            glEnable(num_);
        state_ = !state_;
    }
}

void light_source::turn_on() {
    state_ = true;
    glEnable(num_);
}

void light_source::turn_off() {
    state_ = false;
    glDisable(num_);
}

void light_source::specialdown(int key) { (void)key; }
void light_source::specialup(int key) { (void)key; }
void light_source::update(glut_time_t dt) { (void)dt; }

vector4 &light_source::ambient() { return ambient_; }
const vector4 &light_source::ambient() const { return ambient_; }
vector4 &light_source::diffuse() { return diffuse_; }
const vector4 &light_source::diffuse() const { return diffuse_; }
vector3 &light_source::direction() { return direction_; }
const vector3 &light_source::direction() const { return direction_; }
vector4 &light_source::position() { return position_; }
const vector4 &light_source::position() const { return position_; }
vector4 &light_source::specular() { return specular_; }
const vector4 &light_source::specular() const { return specular_; }

GLdouble &light_source::cutoff() { return cutoff_; }
GLdouble light_source::cutoff() const { return cutoff_; }
GLdouble &light_source::exponent() { return exponent_; }
GLdouble light_source::exponent() const { return exponent_; }
GLenum &light_source::num() { return num_; }
GLenum light_source::num() const { return num_; }
bool light_source::on() const { return state_; }
unsigned char &light_source::toggle_key() { return toggle_key_; }
unsigned char light_source::toggle_key() const { return toggle_key_; }
