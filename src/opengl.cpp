#include "opengl.h"
#include <cassert>
#include <cstdlib>
#include <ctime>

void gluxSlicedCube(int sx, int sy, int sz) {
    // srand(time(NULL));
    assert(sx > 0 && sx > 0 && sz > 0);

    GLdouble dx = 1.0 / sx, dy = 1.0 / sy, dz = 1.0 / sz;

    // cross(y, z) = x
    for (int y = 0; y < sy; ++y) {
        GLdouble ny1 = y == 0 ? -1.0 : 0.0, ny2 = y == (sy - 1) ? 1.0 : 0.0;

        for (int z = 0; z < sz; ++z) {
            GLdouble nz1 = z == 0 ? -1.0 : 0.0, nz2 = z == (sz - 1) ? 1.0 : 0.0;

            glBegin(GL_POLYGON);

            glNormal3f(1.0, ny1, nz1);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(0.5, -0.5 + (y + 0) * dy, -0.5 + (z + 0) * dz);

            glNormal3f(1.0, ny2, nz1);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(0.5, -0.5 + (y + 1) * dy, -0.5 + (z + 0) * dz);

            glNormal3f(1.0, ny2, nz2);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(0.5, -0.5 + (y + 1) * dy, -0.5 + (z + 1) * dz);

            glNormal3f(1.0, ny1, nz2);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(0.5, -0.5 + (y + 0) * dy, -0.5 + (z + 1) * dz);

            glEnd();
        }
    }

    // cross(z, y) = -x
    for (int y = 0; y < sy; ++y) {
        GLdouble ny1 = y == 0 ? -1.0 : 0.0, ny2 = y == (sy - 1) ? 1.0 : 0.0;

        for (int z = 0; z < sz; ++z) {
            GLdouble nz1 = z == 0 ? -1.0 : 0.0, nz2 = z == (sz - 1) ? 1.0 : 0.0;

            glBegin(GL_POLYGON);

            glNormal3f(-1.0, ny1, nz1);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5, -0.5 + (y + 0) * dy, -0.5 + (z + 0) * dz);

            glNormal3f(-1.0, ny1, nz2);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5, -0.5 + (y + 0) * dy, -0.5 + (z + 1) * dz);

            glNormal3f(-1.0, ny2, nz2);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5, -0.5 + (y + 1) * dy, -0.5 + (z + 1) * dz);

            glNormal3f(-1.0, ny2, nz1);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5, -0.5 + (y + 1) * dy, -0.5 + (z + 0) * dz);

            glEnd();
        }
    }

    // cross(z, x) = y
    for (int x = 0; x < sx; ++x) {
        GLdouble nx1 = x == 0 ? -1.0 : 0.0, nx2 = x == (sx - 1) ? 1.0 : 0.0;
        for (int z = 0; z < sz; ++z) {
            GLdouble nz1 = z == 0 ? -1.0 : 0.0, nz2 = z == (sz - 1) ? 1.0 : 0.0;

            glBegin(GL_POLYGON);

            glNormal3f(nx1, 1.0, nz1);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 0) * dx, 0.5, -0.5 + (z + 0) * dz);

            glNormal3f(nx1, 1.0, nz2);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 0) * dx, 0.5, -0.5 + (z + 1) * dz);

            glNormal3f(nx2, 1.0, nz2);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 1) * dx, 0.5, -0.5 + (z + 1) * dz);

            glNormal3f(nx2, 1.0, nz1);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 1) * dx, 0.5, -0.5 + (z + 0) * dz);

            glEnd();
        }
    }

    // cross(x, z) = -y
    for (int x = 0; x < sx; ++x) {
        GLdouble nx1 = x == 0 ? -1.0 : 0.0, nx2 = x == (sx - 1) ? 1.0 : 0.0;
        for (int z = 0; z < sz; ++z) {
            GLdouble nz1 = z == 0 ? -1.0 : 0.0, nz2 = z == (sz - 1) ? 1.0 : 0.0;

            glBegin(GL_POLYGON);

            glNormal3f(nx1, -1.0, nz1);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 0) * dx, -0.5, -0.5 + (z + 0) * dz);

            glNormal3f(nx2, -1.0, nz1);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 1) * dx, -0.5, -0.5 + (z + 0) * dz);

            glNormal3f(nx2, -1.0, nz2);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 1) * dx, -0.5, -0.5 + (z + 1) * dz);

            glNormal3f(nx1, -1.0, nz2);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 0) * dx, -0.5, -0.5 + (z + 1) * dz);

            glEnd();
        }
    }

    // cross(x, y) = z
    for (int x = 0; x < sx; ++x) {
        GLdouble nx1 = x == 0 ? -1.0 : 0.0, nx2 = x == (sx - 1) ? 1.0 : 0.0;

        for (int y = 0; y < sy; ++y) {
            GLdouble ny1 = y == 0 ? -1.0 : 0.0, ny2 = y == (sy - 1) ? 1.0 : 0.0;

            glBegin(GL_POLYGON);

            glNormal3f(nx1, ny1, 1.0);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 0) * dx, -0.5 + (y + 0) * dy, 0.5);

            glNormal3f(nx2, ny1, 1.0);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 1) * dx, -0.5 + (y + 0) * dy, 0.5);

            glNormal3f(nx2, ny2, 1.0);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 1) * dx, -0.5 + (y + 1) * dy, 0.5);

            glNormal3f(nx1, ny2, 1.0);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 0) * dx, -0.5 + (y + 1) * dy, 0.5);

            glEnd();
        }
    }

    // cross(y, x) = -z
    for (int x = 0; x < sx; ++x) {
        GLdouble nx1 = x == 0 ? -1.0 : 0.0, nx2 = x == (sx - 1) ? 1.0 : 0.0;

        for (int y = 0; y < sy; ++y) {
            GLdouble ny1 = y == 0 ? -1.0 : 0.0, ny2 = y == (sy - 1) ? 1.0 : 0.0;

            glBegin(GL_POLYGON);

            glNormal3f(nx1, ny1, -1.0);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 0) * dx, -0.5 + (y + 0) * dy, -0.5);

            glNormal3f(nx1, ny2, -1.0);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 0) * dx, -0.5 + (y + 1) * dy, -0.5);

            glNormal3f(nx2, ny2, -1.0);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 1) * dx, -0.5 + (y + 1) * dy, -0.5);

            glNormal3f(nx2, ny1, -1.0);
            // glColor3ub(rand() % 256, rand() % 256, rand() % 256);
            glVertex3f(-0.5 + (x + 1) * dx, -0.5 + (y + 0) * dy, -0.5);

            glEnd();
        }
    }
}
