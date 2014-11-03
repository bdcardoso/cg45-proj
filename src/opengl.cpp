#include "opengl.h"

/*                          x  y  z  n */
static GLdouble cubeNormals[2][2][2][3];

void gluxInit() {

}

void gluxSlicedCube(int sx, int sy, int sz) {
    GLdouble dx = 1.0  / sx,
             dy = 1.0  / sy,
             dz = 1.0  / sz;
    
    for (int x = 0; x <= sx; ++sx) {
        for (int y = 0; y <= sy; ++sy) {
            glBegin(GL_POLYGON);

            glEnd();
        }
    }
        
    glutSolidCube(1);
}
