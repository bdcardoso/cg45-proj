#include "tunnel.h"
#include "materials.h"
#include <cassert>

constexpr auto SLICES = 20.0, STACKS = 20.0,
               TUNNEL_RED=139.0, TUNNEL_GREEN=69.0, TUNNEL_BLUE=19.0,
               INVISIBLE_RED=120.0 , INVISIBLE_GREEN=120.0 , INVISIBLE_BLUE=120.0;

constexpr auto RADIUS_0 = 1.0, RADIUS_Z = 1.0, COORD_X = 2.0, COORD_XNEG = -3.0,
               COORD_Y = -0.2, COORD_Z = 0.0;

void tunnel::draw() {


    glColor3ub(TUNNEL_RED, TUNNEL_GREEN, TUNNEL_BLUE);
    materials::pearl.use();
    
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

    // INVISIBLE TUNNELS

    glColor3ub(INVISIBLE_RED, INVISIBLE_GREEN, INVISIBLE_BLUE);
    materials::road_black.use();

    glPushMatrix();
    glTranslatef(COORD_X + 0.5, COORD_Y + 0.01, COORD_Z);
    glRotatef(90, 0.0, 1.0, 0.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(COORD_XNEG - 0.5, COORD_Y + 0.01, COORD_Z);
    glRotatef(90, 0.0, 1.0, 0.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(COORD_X + 0.5, COORD_Y + 0.01, 2);
    glRotatef(90, 0.0, 1.0, 0.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(COORD_XNEG - 0.5, COORD_Y + 0.01, 2);
    glRotatef(90, 0.0, 1.0, 0.0);
    gluCylinder(gluNewQuadric(), RADIUS_0, RADIUS_Z, 1, SLICES, STACKS);
    glPopMatrix();

    // Reusable for the car destroyer
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2.5, 5.0, 4.0);
    glVertex3f(2.5, 5.0, -4.0);
    glVertex3f(2.5, -5.0, -4.0);
    glVertex3f(2.5, -5.0, 4.0);
    glEnd();

    // Reusable for the car destroyer
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.5, 5.0, 4.0);
    glVertex3f(-2.5, 5.0, -4.0);
    glVertex3f(-2.5, -5.0, -4.0);
    glVertex3f(-2.5, -5.0, 4.0);
    glEnd();

    // Covering bottom wall
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, -10.0, 3.01);
    glVertex3f(10.0, -10.0, 3.01);
    glVertex3f(10.0, 0.0, 3.01);
    glVertex3f(-10, 0.0, 3.01);
    glEnd();

    // COVERING-LEFT-WALL
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);

    glVertex3f(-10.0, 10.0, 3.1);
    glVertex3f(-2.5, 10.0, 3.1);
    glVertex3f(-2.5, 0.0, 3.1);
    glVertex3f(-10, 0.0, 3.1);
    glEnd();

    // COVERING-RIGHT-WALL
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);

    glVertex3f(10.0, 10.0, 3.1);
    glVertex3f(2.5, 10.0, 3.1);
    glVertex3f(2.5, 0.0, 3.1);
    glVertex3f(10, 0.0, 3.1);
    glEnd();
}
