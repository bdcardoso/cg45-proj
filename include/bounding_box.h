#pragma once
#include "opengl.h"

class vector3;

class bounding_box {
public:
    typedef GLdouble scalar_t;

    bounding_box();
    bounding_box(scalar_t x, scalar_t y, scalar_t w, scalar_t h);
    bounding_box(scalar_t x1, scalar_t y1, scalar_t z1, scalar_t x2,
                 scalar_t y2, scalar_t z2);

    scalar_t &x1();
    const scalar_t &x1() const;
    scalar_t &x2();
    const scalar_t &x2() const;
    scalar_t &y1();
    const scalar_t &y1() const;
    scalar_t &y2();
    const scalar_t &y2() const;
    scalar_t &z1();
    const scalar_t &z1() const;
    scalar_t &z2();
    const scalar_t &z2() const;

    scalar_t length() const;
    scalar_t height() const;
    scalar_t width() const;

    void x1(scalar_t newx);
    void x2(scalar_t newx);
    void y1(scalar_t newy);
    void y2(scalar_t newy);
    void z1(scalar_t newz);
    void z2(scalar_t newz);

    void draw();

    void scale(scalar_t dx, scalar_t dy, scalar_t dz);
    void scale(const vector3 &delta);

    void translate(scalar_t dx, scalar_t dy, scalar_t dz);
    void translate(const vector3 &delta);

    bool intersects(const bounding_box &bb) const;
    bounding_box intersect(const bounding_box &bb) const;

    operator bool() const;

private:
    scalar_t x1_, x2_;
    scalar_t y1_, y2_;
    scalar_t z1_, z2_;
};
