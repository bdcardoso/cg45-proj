#pragma once
#include "camera.h"
#include "dynamic_object.h"
#include "light_source.h"
#include <memory>

class frog : public dynamic_object {
    static constexpr GLdouble SPEED_X = 1.0, SPEED_Z = 1.0;

    // The frog's legs
    class leg : public dynamic_object {
    public:
        void draw() override;
    };

private:
    std::shared_ptr<camera> camera_;
    std::shared_ptr<light_source> headlight_;
    GLfloat orientation_;

    leg leftleg_, rightleg_;

public:
    frog();

    std::shared_ptr<camera> cam();
    std::shared_ptr<light_source> headlight();

    void draw() override;
    void keydown(unsigned char key) override;
    void keyup(unsigned char key) override;
    void update(glut_time_t dt) override;
};
