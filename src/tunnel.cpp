#include "tunnel.h"
#include <cassert>

constexpr auto SLICES =      20.0,
               STACKS =      20.0;
               
constexpr auto RADIUS_0 =    1.0,
               RADIUS_Z =    1.0, 
               COORD_X =     2.5,
               COORD_Y =     1.0,
               COORD_Z =     0.0;    
          
               
void tunnel::draw() {

    glColor3ub(50, 50, 50);
    
    _scale.y(0.1);
    glPushMatrix();  
		glTranslatef(COORD_X, COORD_Y, COORD_Z);
        glRotatef(90, 0.0, 1.0, 0.0);
        //glScalef(RIVER_LENGTH, WATER_DEPTH, WATER_WIDTH);
        gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
     
     glPopMatrix();  
}
