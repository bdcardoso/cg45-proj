#include "vector3.h"

vector3::vector3(GLdouble x, GLdouble y, GLdouble z) {
    coords_[0] = x;
    coords_[1] = y;
    coords_[2] = z;
}

GLdouble &vector3::x() { return coords_[0]; }
const GLdouble &vector3::x() const { return coords_[0]; }
GLdouble &vector3::y() { return coords_[1]; }
const GLdouble &vector3::y() const { return coords_[1]; }
GLdouble &vector3::z() { return coords_[2]; }
const GLdouble &vector3::z() const { return coords_[2]; }

void vector3::set(GLdouble x, GLdouble y, GLdouble z) {
    coords_[0] = x;
    coords_[1] = y;
    coords_[2] = z;
}

const GLdouble *vector3::get() const { return coords_; }

vector3::scalar_t vector3::dot(const vector3 &rhs) const {
    return x() * rhs.x() + y() * rhs.y() + z() * rhs.z();
}

vector3 vector3::ext(const vector3 &rhs) const {
    return vector3(y() * rhs.z() - z() * rhs.y(), z() * rhs.x() - x() * rhs.z(),
                   x() * rhs.y() - y() * rhs.x());
}

vector3 vector3::normalized() const { return *this / this->dot(*this); }

vector3 operator+(const vector3 &lhs, const vector3 &rhs) {
    return vector3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

vector3 &operator+=(vector3 &lhs, const vector3 &rhs) {
    lhs.set(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
    return lhs;
}

vector3 operator-(const vector3 &lhs, const vector3 &rhs) {
    return vector3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

vector3 &operator-=(vector3 &lhs, const vector3 &rhs) {
    lhs.set(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
    return lhs;
}

vector3 operator*(const vector3 &lhs, const vector3::scalar_t &rhs) {
    return vector3(lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs);
}

vector3 operator*(const vector3::scalar_t &lhs, const vector3 &rhs) {
    return rhs * lhs;
}

vector3 operator/(const vector3 &lhs, const vector3::scalar_t &rhs) {
    return vector3(lhs.x() / rhs, lhs.y() / rhs, lhs.z() / rhs);
}
