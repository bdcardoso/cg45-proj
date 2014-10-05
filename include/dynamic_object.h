#pragma once
#include "game_object.h"

class dynamic_object : public game_object {
protected:
    vector3 _speed;

public:
    dynamic_object();

    void update(double delta_t);

    vector3 speed() const;
    void speed(const vector3 &speed);
    void speed(GLdouble x, GLdouble y, GLdouble z);

};
