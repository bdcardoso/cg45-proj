#include "tunnel.h"
#include <cassert>

constexpr auto SLICES = 20.0, STACKS = 20.0;

constexpr auto RADIUS_0 = 1.0, RADIUS_Z = 1.0, COORD_X = 2.0, COORD_XNEG = -3.0,
               COORD_Y = -0.2, COORD_Z = 0.0;

void tunnel::draw() {
	
    glColor3ub(50, 50, 50);

    glPushMatrix();
    glTranslatef(COORD_X, COORD_Y, COORD_Z);
    glRotatef(90, 0.0, 1.0, 0.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(COORD_XNEG, COORD_Y, COORD_Z);
    glRotatef(90, 0.0, 1.0, 0.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(COORD_X, COORD_Y, 2);
    glRotatef(90, 0.0, 1.0, 0.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(COORD_XNEG, COORD_Y, 2);
    glRotatef(90, 0.0, 1.0, 0.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
    glPopMatrix();
    

	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0,  0.0 );        
    glVertex3f(2.5, 5.0, 4.0);      
    glVertex3f(2.5, 5.0, -4.0);      
    glVertex3f(2.5, -5.0, -4.0);      
    glVertex3f(2.5, -5.0, 4.0);
	glEnd();
	
	glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0,  0.0 );        
    glVertex3f(-2.5, 5.0, 4.0);      
    glVertex3f(-2.5, 5.0, -4.0);      
    glVertex3f(-2.5, -5.0, -4.0);      
    glVertex3f(-2.5, -5.0, 4.0);
	glEnd();

}
