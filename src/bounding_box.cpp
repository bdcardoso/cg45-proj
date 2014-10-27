#include "bounding_box.h"
#include <cassert>
#include <cfloat>

typedef bounding_box::scalar_t scalar_t;

bounding_box::bounding_box() : bounding_box(0, 0, 0, 0) {}

bounding_box::bounding_box(scalar_t x, scalar_t y, scalar_t w, scalar_t h)
        : bounding_box(x, y, 0, x + w, y + h, 0) {}

bounding_box::bounding_box(scalar_t x1, scalar_t y1, scalar_t z1, scalar_t x2,
                           scalar_t y2, scalar_t z2)
        : x1_(x1), x2_(x2), y1_(y1), y2_(y2), z1_(z1), z2_(z2) {
    assert(x2 >= x1);
    assert(y2 >= y1);
    assert(z2 >= z1);
}

scalar_t bounding_box::x1() const { return x1_; }
scalar_t bounding_box::x2() const { return x2_; }
scalar_t bounding_box::y1() const { return y1_; }
scalar_t bounding_box::y2() const { return y2_; }
scalar_t bounding_box::z1() const { return z1_; }
scalar_t bounding_box::z2() const { return z2_; }

void bounding_box::x1(scalar_t c) {
    assert(c <= x2());
    x1_ = c;
}
void bounding_box::x2(scalar_t c) {
    assert(c >= x1());
    x2_ = c;
}
void bounding_box::y1(scalar_t c) {
    assert(c <= y2());
    y1_ = c;
}
void bounding_box::y2(scalar_t c) {
    assert(c >= y1());
    y2_ = c;
}
void bounding_box::z1(scalar_t c) {
    assert(c <= z2());
    z1_ = c;
}
void bounding_box::z2(scalar_t c) {
    assert(c >= z1());
    z2_ = c;
}

scalar_t bounding_box::width() const { return x2() - x1(); }
scalar_t bounding_box::height() const { return y2() - y1(); }
scalar_t bounding_box::length() const { return z2() - z1(); }

void bounding_box::draw() {
    // Don't draw if "null" box
    if (!*this)
        return;

    glPushMatrix();
    glColor3ub(0, 255, 0);
    glTranslatef(-width() / 2.0, -height() / 2.0, -length() / 2.0);
    glScalef(width(), height(), length());
    glutWireCube(1);
    glPopMatrix();
}

bounding_box::operator bool() const {
    return width() >= DBL_EPSILON || height() >= DBL_EPSILON ||
           length() >= DBL_EPSILON;
}

bounding_box bounding_box::intersect(const bounding_box &bb) const {
    return bounding_box();
}

bool bounding_box::intersects(const bounding_box &bb) const {
    bool xOverlaps = true;
    bool yOverlaps = true;
    bool zOverlaps = true;

    xOverlaps = !(x2() < bb.x1() || x1() > bb.x2());
    yOverlaps = !(y2() < bb.y1() || y1() > bb.y2());
    zOverlaps = !(z2() < bb.z1() || z1() > bb.z2());

    return xOverlaps && yOverlaps && zOverlaps;
}
