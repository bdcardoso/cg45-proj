#include "entity.h"

entity::entity() {

}

vector3 entity::position() {
    return _position;
}

void entity::position(GLdouble x, GLdouble y, GLdouble z) {
    position(vector3(x, y, z));

}

void entity::position(const vector3 &v) {
    _position = v;
}
