#include "turtle.h"

constexpr auto BODY_COLOR_RED =           20,
               BODY_COLOR_GREEN =         50,
               BODY_COLOR_BLUE =          20,
               SKIN_COLOR_RED =           30,
               SKIN_COLOR_GREEN =         80,
               SKIN_COLOR_BLUE =          30;

constexpr auto BODY_SIZE_X =              3.0f,
               BODY_SIZE_Y =              1.0f,
               BODY_SIZE_Z =              3.0f,
               HEAD_SIZE_X =             -1.0f,
               HEAD_SIZE_Y =             -0.5f,
               HEAD_SIZE_Z =              1.0f,
               TAIL_SIZE_X =             -0.5f,
               TAIL_SIZE_Y =             -0.5f,
               TAIL_SIZE_Z =             -0.5f,
               LEG_SIZE_X =               1.0f,
               LEG_SIZE_Y =               0.5f,
               LEG_SIZE_Z =               1.0f,
               BODY_COORD_X =             0.0f,
               BODY_COORD_Y =             0.0f,
               BODY_COORD_Z =             0.0f,
               HEAD_COORD_X =             2.0f,
               HEAD_COORD_Y =            -0.25f,
               HEAD_COORD_Z =             0.0f,
               TAIL_COORD_X =            -1.75f,
               TAIL_COORD_Y =            -0.25f,
               TAIL_COORD_Z =             0.0f,
               // ----
               LEG_COORD_FRONT_LEFT_X =   1.0f,
               LEG_COORD_FRONT_LEFT_Y =  -0.75f,
               LEG_COORD_FRONT_LEFT_Z =  -1.5f,
               LEG_COORD_FRONT_RIGHT_X =  1.0f,
               LEG_COORD_FRONT_RIGHT_Y = -0.75f,
               LEG_COORD_FRONT_RIGHT_Z =  1.5f,
               LEG_COORD_BACK_LEFT_X =   -1.0f,
               LEG_COORD_BACK_LEFT_Y =   -0.75f,
               LEG_COORD_BACK_LEFT_Z =   -1.5f,
               LEG_COORD_BACK_RIGHT_X =  -1.0f,
               LEG_COORD_BACK_RIGHT_Y =  -0.75f,
               LEG_COORD_BACK_RIGHT_Z =   1.5f;


void turtle::draw() {
    glColor3ub(BODY_COLOR_RED, BODY_COLOR_GREEN, BODY_COLOR_BLUE);

    //Body
    glPushMatrix();    
        glTranslatef(BODY_COORD_X, BODY_COORD_Y, BODY_COORD_Z);
        glScalef(BODY_SIZE_X, BODY_SIZE_Y, BODY_SIZE_Z);
        glutSolidCube(1);
    glPopMatrix();

    glColor3ub(SKIN_COLOR_RED, SKIN_COLOR_GREEN, SKIN_COLOR_BLUE);

    //Head
    glPushMatrix();    
        glTranslatef(HEAD_COORD_X, HEAD_COORD_Y, HEAD_COORD_Z);
        glScalef(HEAD_SIZE_X, HEAD_SIZE_Y, HEAD_SIZE_Z);
        glutSolidCube(1);
    glPopMatrix();

    //Tail
    glPushMatrix();    
        glTranslatef(TAIL_COORD_X, TAIL_COORD_Y, TAIL_COORD_Z);
        glScalef(TAIL_SIZE_X, TAIL_SIZE_Y, TAIL_SIZE_Z);
        glutSolidCube(1);
    glPopMatrix();

    //Front-Left Leg
    glPushMatrix();    
        glTranslatef(LEG_COORD_FRONT_LEFT_X, LEG_COORD_FRONT_LEFT_Y, LEG_COORD_FRONT_LEFT_Z);
        glScalef(LEG_SIZE_X, LEG_SIZE_Y, LEG_SIZE_Z);
        glutSolidCube(1);
    glPopMatrix();

    //Front-Right Leg
    glPushMatrix();    
        glTranslatef(LEG_COORD_FRONT_RIGHT_X, LEG_COORD_FRONT_RIGHT_Y, LEG_COORD_FRONT_RIGHT_Z);
        glScalef(LEG_SIZE_X, LEG_SIZE_Y, LEG_SIZE_Z);
        glutSolidCube(1);
    glPopMatrix();

    //Back-Left Leg
    glPushMatrix();    
        glTranslatef(LEG_COORD_BACK_LEFT_X, LEG_COORD_BACK_LEFT_Y, LEG_COORD_BACK_LEFT_Z);
        glScalef(LEG_SIZE_X, LEG_SIZE_Y, LEG_SIZE_Z);
        glutSolidCube(1);
    glPopMatrix();

    //Back-Right Leg
    glPushMatrix();    
        glTranslatef(LEG_COORD_BACK_RIGHT_X, LEG_COORD_BACK_RIGHT_Y, LEG_COORD_BACK_RIGHT_Z);
        glScalef(LEG_SIZE_X, LEG_SIZE_Y, LEG_SIZE_Z);
        glutSolidCube(1);
    glPopMatrix();
}

void turtle::update(glut_time_t dt) {
    dynamic_object::update(dt);
    
    if(position().x() > 2.75){
		 position(vector3( -2.90, 0.05,  -1.5));
	 }
}
