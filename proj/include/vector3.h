#pragma once

class vector3 {
    double _x, _y, _z;

public:
    vector3();
    vector3(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    void x(double newx);
    void y(double newy);
    void z(double newz);

    void set(double x, double y, double z);
    
    vector3 operator+(const vector3 &rhs);
    vector3 operator-(const vector3 &rhs);
    vector3 operator*(double scalar);
};

