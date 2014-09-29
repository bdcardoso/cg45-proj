#pragma once
#include "static_object.h"
#include "opengl.h"

class river : public static_object {
public:
    river();

    void draw();
    void update(GLdouble dt);
};

