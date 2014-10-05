#include "car.h"

#define BODY_COLOR               150 ,  150 ,  150
#define BODY_COORD_LOWER         0.0f,  1.0f,  0.0f
#define BODY_SIZE_LOWER          6.0f,  1.0f,  3.0f
#define BODY_COORD_UPPER        -0.2f,  2.0f,  0.0f
#define BODY_SIZE_UPPER          3.0f,  1.0f,  3.0f

#define WHEEL_COLOR              50  ,  50  ,  50
#define WHEEL_SIZE               0.3 ,  0.5 ,  15  , 15
#define WHEEL_COORD_FRONT_LEFT   1.5f,  0.5f, -1.5f
#define WHEEL_COORD_FRONT_RIGHT  1.5f,  0.5f,  1.5f
#define WHEEL_COORD_BACK_LEFT   -1.5f,  0.5f, -1.5f
#define WHEEL_COORD_BACK_RIGHT  -1.5f,  0.5f,  1.5f


void car::draw() {
	glColor3ub(BODY_COLOR);

	//Lower Body
	glPushMatrix();	
	glTranslatef(BODY_COORD_LOWER);
	glPushMatrix();
	glScalef(BODY_SIZE_LOWER);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	//Upper Body
	glPushMatrix();	
	glTranslatef(BODY_COORD_UPPER);
	glPushMatrix();
	glScalef(BODY_SIZE_UPPER);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	glColor3ub(WHEEL_COLOR);

	//Front-Left Wheel
	glPushMatrix();	
	glTranslatef(WHEEL_COORD_FRONT_LEFT);
	glutSolidTorus(WHEEL_SIZE);
	glPopMatrix();

	//Front-Right Wheel
	glPushMatrix();	
	glTranslatef(WHEEL_COORD_FRONT_RIGHT);
	glutSolidTorus(WHEEL_SIZE);
	glPopMatrix();

	//Back-Left Wheel
	glPushMatrix();	
	glTranslatef(WHEEL_COORD_BACK_LEFT);
	glutSolidTorus(WHEEL_SIZE);
	glPopMatrix();

	//Back-Right Wheel
	glPushMatrix();	
	glTranslatef(WHEEL_COORD_BACK_RIGHT);
	glutSolidTorus(WHEEL_SIZE);
	glPopMatrix();
}

void car::update(glut_time_t dt) {
  (void)dt;
}

