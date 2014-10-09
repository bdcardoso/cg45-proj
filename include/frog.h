#pragma once
#include "dynamic_object.h"

class frog : public dynamic_object {
    static constexpr GLdouble SPEED_X = 3.0, SPEED_Y = 3.0;

    // The frog's legs
    class leg : public dynamic_object {
    public:
        void draw() override;
    };

private:
    leg _leftleg, _rightleg;

public:

    void draw() override;
    void keydown(unsigned char key) override;
    void keyup(unsigned char key) override;
    void update(glut_time_t dt) override;
};

