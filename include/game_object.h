#pragma once
#include "bounding_box.h"
#include "vector3.h"

class game_object {
protected:
    class bounding_box bb_;
    vector3 position_;
    vector3 scale_;

public:
    typedef vector3::scalar_t scalar_t;

    game_object();

    vector3 &scale();
    const vector3 &scale() const;
    void scale(vector3::scalar_t s);

    vector3 &position();
    const vector3 &position() const;

    class bounding_box &bounding_box();
    const class bounding_box &bounding_box() const;

    virtual void draw();
    virtual void keydown(unsigned char key);
    virtual void keyup(unsigned char key);
    virtual void specialdown(int key);
    virtual void specialup(int key);
    virtual void update(glut_time_t dt);
};
