#pragma once
#include "vector3.h"

class vector4 {
    double _x, _y, _z, _w;

public:
    vector4();
    vector4(const vector3 &in);
    vector4(double x, double y, double z, double w);

    double x();
    double y();
    double z();
    double w();

    void x(double newx);
    void y(double newy);
    void z(double newz);
    void w(double neww);

    void set(double x, double y, double z, double w);
    
    vector4 &operator+(const vector4 &rhs);
    vector4 &operator+(const vector3 &rhs);
    vector4 &operator-(const vector4 &rhs);
    vector4 &operator-(const vector3 &rhs);
    vector4 &operator*(double scalar);
};

