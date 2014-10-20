#pragma once
#include "camera.h"
#include "dynamic_object.h"
#include <memory>

class frog : public dynamic_object {
    static constexpr GLdouble SPEED_X = 1.0, SPEED_Z = 1.0;

    // The frog's legs
    class leg : public dynamic_object {
    public:
        void draw() override;
    };

private:
    leg _leftleg, _rightleg;
    std::shared_ptr<camera> _camera;


public:
    frog();

    std::shared_ptr<camera> cam();

    void draw() override;
    void keydown(unsigned char key) override;
    void keyup(unsigned char key) override;
    void update(glut_time_t dt) override;
};
