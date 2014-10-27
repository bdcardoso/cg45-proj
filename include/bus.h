#pragma once
#include "dynamic_object.h"

class bus : public dynamic_object {
public:
	bus();

    void draw() override;
    void update(glut_time_t dt) override;
};
