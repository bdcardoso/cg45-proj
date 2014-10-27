#include "bounding_box.h"
#include "vector3.h"
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>

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

scalar_t &bounding_box::x1() { return x1_; }
scalar_t &bounding_box::x2() { return x2_; }
scalar_t &bounding_box::y1() { return y1_; }
scalar_t &bounding_box::y2() { return y2_; }
scalar_t &bounding_box::z1() { return z1_; }
scalar_t &bounding_box::z2() { return z2_; }
const scalar_t &bounding_box::x1() const { return x1_; }
const scalar_t &bounding_box::x2() const { return x2_; }
const scalar_t &bounding_box::y1() const { return y1_; }
const scalar_t &bounding_box::y2() const { return y2_; }
const scalar_t &bounding_box::z1() const { return z1_; }
const scalar_t &bounding_box::z2() const { return z2_; }

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
    glBegin(GL_LINE_LOOP);
    glVertex3d(x1(), y1(), z1());
    glVertex3d(x2(), y1(), z1());
    glVertex3d(x2(), y2(), z1());
    glVertex3d(x1(), y2(), z1());
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(x1(), y1(), z2());
    glVertex3d(x2(), y1(), z2());
    glVertex3d(x2(), y2(), z2());
    glVertex3d(x1(), y2(), z2());
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(x1(), y1(), z1());
    glVertex3d(x1(), y1(), z2());
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(x1(), y2(), z1());
    glVertex3d(x1(), y2(), z2());
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(x2(), y1(), z1());
    glVertex3d(x2(), y1(), z2());
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(x2(), y2(), z1());
    glVertex3d(x2(), y2(), z2());
    glEnd();
    glPopMatrix();
}

void bounding_box::scale(scalar_t sx, scalar_t sy, scalar_t sz) {
    auto w = (fabs(width() * sx) - width()) / 2,
         h = (fabs(height() * sy) - height()) / 2,
         l = (fabs(length() * sz) - length()) / 2;

    x1_ -= w;
    x2_ += w;
    y1_ -= h;
    y2_ += h;
    z1_ -= l;
    z2_ += l;
}

void bounding_box::scale(const vector3 &delta) {
    scale(delta.x(), delta.y(), delta.z());
}

void bounding_box::translate(scalar_t dx, scalar_t dy, scalar_t dz) {
    x1_ += dx;
    x2_ += dx;
    y1_ += dy;
    y2_ += dy;
    z1_ += dz;
    z2_ += dz;
}

void bounding_box::translate(const vector3 &delta) {
    translate(delta.x(), delta.y(), delta.z());
}

void print_box(const char *name, const bounding_box &b) {
    printf("%s - x:%.2f y:%.2f z:%.2f w:%.2f h:%.2f l:%.2f\n", name, b.x1(),
           b.y1(), b.z1(), b.width(), b.height(), b.length());
}

bounding_box::operator bool() const {
    return width() >= DBL_EPSILON && height() >= DBL_EPSILON &&
           length() >= DBL_EPSILON;
}

bounding_box bounding_box::intersect(const bounding_box &bb) const {
    bounding_box ret;
    scalar_t l, r, aux;

    if (x2() < bb.x1() || x1() > bb.x2())
        goto yy;

    ret.x1() = std::fmax(x1(), bb.x1());
    ret.x2() = std::fmin(x2(), bb.x2());

yy:
    if (y2() < bb.y1() || y1() > bb.y2())
        goto zz;

    ret.y1() = std::fmax(y1(), bb.y1());
    ret.y2() = std::fmin(y2(), bb.y2());

zz:
    if (z2() < bb.z1() || z1() > bb.z2())
        goto ee;

    ret.z1() = std::fmax(z1(), bb.z1());
    ret.z2() = std::fmin(z2(), bb.z2());

ee:
    if (ret) {
        print_box("Box 1", *this);
        print_box("Box 2", bb);
        print_box("Isct", ret);
    }

    return ret;
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
