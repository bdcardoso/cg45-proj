#include "opengl.h"
#include <cassert>

/*                          x  y  z  n */
static GLdouble cubeNormals[2][2][2][3];

void gluxInit() {

}

void gluxSlicedCube(int sx, int sy, int sz) {
    assert(sx > 0 && sy > 0 && sz > 0);
    
    GLdouble dx = 1.0  / sx,
             dy = 1.0  / sy,
             dz = 1.0  / sz;
    
    // xy
    for (int x = 0; x < sx; ++x) {
        for (int y = 0; y < sy; ++y) {
            glBegin(GL_POLYGON);
            glNormal3f(0.0, 0.0, 1.0);
            glVertex3f(-0.5 + (x+0)*dx, -0.5 + (y+0)*dy, -0.5);
            glNormal3f(0.0, 0.0, 1.0);
            glVertex3f(-0.5 + (x+1)*dx, -0.5 + (y+0)*dy, -0.5);
            glNormal3f(0.0, 0.0, 1.0);
            glVertex3f(-0.5 + (x+1)*dx, -0.5 + (y+1)*dy, -0.5);
            glNormal3f(0.0, 0.0, 1.0);
            glVertex3f(-0.5 + (x+0)*dx, -0.5 + (y+1)*dy, -0.5); 
            glEnd();
        }
    }
    
    // yx
    for (int y = 0; y < sy; ++y) {
        for (int x = 0; x < sx; ++x) {
            glBegin(GL_POLYGON);
            glNormal3f(0.0, 0.0, -1.0);
            glVertex3f(-0.5 + (x+0)*dx, -0.5 + (y+0)*dy, 0.5);
            glNormal3f(0.0, 0.0, -1.0);
            glVertex3f(-0.5 + (x+1)*dx, -0.5 + (y+0)*dy, 0.5);
            glNormal3f(0.0, 0.0, -1.0);
            glVertex3f(-0.5 + (x+1)*dx, -0.5 + (y+1)*dy, 0.5);
            glNormal3f(0.0, 0.0, -1.0);
            glVertex3f(-0.5 + (x+0)*dx, -0.5 + (y+1)*dy, 0.5); 
            glEnd();
        }
    }
    
    // xz    
    for (int x = 0; x < sx; ++x) {
        for (int z = 0; z < sz; ++z) {
            glBegin(GL_POLYGON);
            glNormal3f(0.0, 1.0, 0.0);
            glVertex3f(-0.5 + (x+0)*dx, -0.5, -0.5 + (z+0)*dz);
            glNormal3f(0.0, 1.0, 0.0);
            glVertex3f(-0.5 + (x+1)*dx, -0.5, -0.5 + (z+0)*dz);
            glNormal3f(0.0, 1.0, 0.0);
            glVertex3f(-0.5 + (x+1)*dx, -0.5, -0.5 + (z+1)*dz);
            glNormal3f(0.0, 1.0, 0.0);
            glVertex3f(-0.5 + (x+0)*dx, -0.5, -0.5 + (z+1)*dz); 
            glEnd();
        }
    }
    
    // zx    
    for (int z = 0; z < sz; ++z) {
        for (int x = 0; x < sx; ++x) {
            glBegin(GL_POLYGON);
            glNormal3f(0.0, -1.0, 0.0);
            glVertex3f(-0.5 + (x+0)*dx, 0.5, -0.5 + (z+0)*dz);
            glNormal3f(0.0, -1.0, 0.0);
            glVertex3f(-0.5 + (x+1)*dx, 0.5, -0.5 + (z+0)*dz);
            glNormal3f(0.0, -1.0, 0.0);
            glVertex3f(-0.5 + (x+1)*dx, 0.5, -0.5 + (z+1)*dz);
            glNormal3f(0.0, -1.0, 0.0);
            glVertex3f(-0.5 + (x+0)*dx, 0.5, -0.5 + (z+1)*dz);
            glEnd();
        }
    }

    // yz    
    for (int y = 0; y < sy; ++y) {
        for (int z = 0; z < sz; ++z) {
            glBegin(GL_POLYGON);
            glNormal3f(1.0, 0.0, 0.0);
            glVertex3f(-0.5, -0.5 + (y+0)*dy, -0.5 + (z+0)*dz);
            glNormal3f(1.0, 0.0, 0.0);
            glVertex3f(-0.5, -0.5 + (y+1)*dy, -0.5 + (z+0)*dz);
            glNormal3f(1.0, 0.0, 0.0);
            glVertex3f(-0.5, -0.5 + (y+1)*dy, -0.5 + (z+1)*dz);
            glNormal3f(1.0, 0.0, 0.0);
            glVertex3f(-0.5, -0.5 + (y+0)*dy, -0.5 + (z+1)*dz); 
            glEnd();
        }
    }
    
    // zy    
    for (int z = 0; z < sz; ++z) {
        for (int y = 0; y < sy; ++y) {
            glBegin(GL_POLYGON);
            glNormal3f(-1.0, 1.0, 0.0);
            glVertex3f(0.5, -0.5 + (y+0)*dy, -0.5 + (z+0)*dz);
            glNormal3f(-1.0, 1.0, 0.0);
            glVertex3f(0.5, -0.5 + (y+1)*dy, -0.5 + (z+0)*dz);
            glNormal3f(-1.0, 1.0, 0.0);
            glVertex3f(0.5, -0.5 + (y+1)*dy, -0.5 + (z+1)*dz);
            glNormal3f(-1.0, 1.0, 0.0);
            glVertex3f(0.5, -0.5 + (y+0)*dy, -0.5 + (z+1)*dz);
            glEnd();
        }
    }
    //glutSolidCube(1);
}
