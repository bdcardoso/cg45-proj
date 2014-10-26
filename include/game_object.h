#pragma once
#include "bounding_box.h"
#include "entity.h"

class game_object : public entity {
protected:
    class bounding_box bb_;
    vector3 scale_;

public:
    game_object();

    vector3 &scale();
    void scale(const vector3 &s);
    void scale(GLdouble factor);

    const class bounding_box &bounding_box() const;
    class bounding_box &bounding_box();

    virtual void draw(){};
    virtual void keydown(unsigned char key) { (void)key; };
    virtual void keyup(unsigned char key) { (void)key; };
    virtual void specialdown(int key) { (void)key; };
    virtual void specialup(int key) { (void)key; };
    virtual void update(glut_time_t dt) { (void)dt; };
};
