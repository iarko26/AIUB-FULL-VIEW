#include <windows.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.1416

///*************************************FULL VIEW START FROM HERE****************************************************************
GLfloat position = 0.0f;
GLfloat speed = 0.006f;//c1

GLfloat position5 = 0.0f;
GLfloat speed3 = 0.0010f;//c1

GLfloat position3 = 0.0f;
GLfloat speed4 = 0.0014f;//c2

GLfloat position1 = 0.0f;
GLfloat speed1 = 0.0018f;//c3


GLfloat carPosition1 = 0.0f;
GLfloat carSpeed1 = 0.008f; // for car 1


GLfloat carPosition2 = 0.0f;
GLfloat carSpeed2 = 0.008f; //for car 2


char *p;
void update(int value) {

    if(position > 0.9){
        position = -1.4f;
    }
    position += speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);

}

void update_3(int value) {

    if(position > 1.3){
        position = -1.4f;
    }
    position += speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);

}


void update_2(int value) {

    if(position3 > 1.7){
        position = -1.4f;
    }
    position3+= speed4;
	glutPostRedisplay();
	glutTimerFunc(100, update_2, 0);
}


	void update1(int value) {
    if(position1 > 2.1){
        position1 = -1.4f;
    }
    position1 += speed1;
	glutPostRedisplay();
	glutTimerFunc(100, update1, 0);
}


void update_car1(int value) {

    if(carPosition1 < - 1.5)
    {
        carPosition1 = 1.2f;
    }
    else if(carPosition1 > 1.5){
        carPosition1 = -1.2f;
    }
    carPosition1 += carSpeed1;

    glutPostRedisplay();

    glutTimerFunc(10, update_car1, 0);
}

 void update_car2(int value) {
    if(carPosition2 < - 1.5)
    {
        carPosition2 = 1.2f;
    }
    else if(carPosition2 > 1.5){
        carPosition2 = -1.2f;
    }
    carPosition2 += carSpeed2;

    glutPostRedisplay();

    glutTimerFunc(10, update_car2, 0);
  }

void circlecar(float x, float y, float radius)
{
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}

void vehicles(){
 glPushMatrix();
    glTranslatef(carPosition1,0.68f, 0.0f);
    //body
    glColor3f(1.0,1.0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();
    //wheels
    glColor3f(0.91,0,0);
    circlecar(0.07,-0.938,0.035);
    circlecar(0.2,-0.938,0.035);
    //
    glColor3f(0,0,0);
    glLineWidth(1.1);
    glBegin(GL_LINES);
    glVertex2f(0.141f,-0.758f);
    glVertex2f(0.141f,-0.842f);
    glEnd();
    //window
    glColor3f(0.6,0.80,0.98);
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();
    glColor3f(0.6,0.80,0.98);
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();
    //door
    glColor3f(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3f(1.0,1.0,1.0);
    glEnd();
    glPopMatrix();


glPushMatrix();
    glTranslatef(-carPosition2,0.52f, 0.0f);
    //body
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();
    //wheels
    glColor3f(0.92,0,0);
    circlecar(0.07,-0.938,0.035);
    circlecar(0.2,-0.938,0.035);
    //
    glColor3f(0,0,0);
    glLineWidth(1.1);
    glBegin(GL_LINES);
    glVertex2f(0.141f,-0.758f);
    glVertex2f(0.141f,-0.842f);
    glEnd();
    //window
    glColor3f(0.6,0.8,0.98);
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();
    glColor3f(0.6,0.8,0.98);
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();
    //door
    glColor3f(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();
    glPopMatrix();


}
void sun(){

///Sun

  glColor3f(0.94, 1.0, 0);

    int k;
    GLfloat x=.8f; GLfloat y=.8f;GLfloat radius =.1f;
	 int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount))
			);
		}
	glEnd();
}


void cloud_1(){
glPushMatrix();
glTranslatef(position,0.0f, 0.0f);

 glColor3f(1.0, 1.0, 1.0);

    int f;
GLfloat x=.6f; GLfloat y=.7f;GLfloat radius =.03f;
	 int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(f = 0; f <= triangleAmount;f++) {
			glVertex2f(
		            x + (radius * cos(f *  twicePi / triangleAmount)),
			    y + (radius * sin(f * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int g;
     x=.64f; y=.7f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(g = 0; g <= triangleAmount;g++) {
			glVertex2f(
		            x + (radius * cos(g *  twicePi / triangleAmount)),
			    y + (radius * sin(g * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int h;
     x=.67f; y=.675f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(h = 0; h <= triangleAmount;h++) {
			glVertex2f(
		            x + (radius * cos(h *  twicePi / triangleAmount)),
			    y + (radius * sin(h * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int l;
     x=.625f; y=.665f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(l = 0; l <= triangleAmount;l++) {
			glVertex2f(
		            x + (radius * cos(l *  twicePi / triangleAmount)),
			    y + (radius * sin(l * twicePi / triangleAmount))
			);
		}
	glEnd();

	///cloud 2
glColor3f(1.0, 1.0, 1.0);

    int F;
     x=0.09f; y=.70f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(F = 0; F <= triangleAmount;F++) {
			glVertex2f(
		            x + (radius * cos(F *  twicePi / triangleAmount)),
			    y + (radius * sin(F * twicePi / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);


    int G;
     x=.13f; y=.70f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(G = 0; G <= triangleAmount;G++) {
			glVertex2f(
		            x + (radius * cos(G *  twicePi / triangleAmount)),
			    y + (radius * sin(G * twicePi / triangleAmount))
			);
		}
	glEnd();

int H;
     x=.17f; y=.675f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(H = 0; H <= triangleAmount;H++) {
			glVertex2f(
		            x + (radius * cos(H *  twicePi / triangleAmount)),
			    y + (radius * sin(H * twicePi / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);

    int L;
     x=.12f; y=.665f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(L = 0; L <= triangleAmount;L++) {
			glVertex2f(
		            x + (radius * cos(L *  twicePi / triangleAmount)),
			    y + (radius * sin(L * twicePi / triangleAmount))
			);
		}
	glEnd();

//c3
///cloud3

glColor3f(1.0, 1.0, 1.0);
glTranslatef(position3,0.0f, 0.0f);
    int Q;
     x=-.2f; y=.8f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(Q = 0; Q <= triangleAmount;Q++) {
			glVertex2f(
		            x + (radius * cos(Q *  twicePi / triangleAmount)),
			    y + (radius * sin(Q * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int W;
     x=-.16f; y=.8f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(W = 0; W <= triangleAmount;W++) {
			glVertex2f(
		            x + (radius * cos(W *  twicePi / triangleAmount)),
			    y + (radius * sin(W * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int E;
     x=-.13f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(E = 0; E <= triangleAmount;E++) {
			glVertex2f(
		            x + (radius * cos(E *  twicePi / triangleAmount)),
			    y + (radius * sin(E * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int R;
     x=-.175f; y=.765f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(R = 0; R <= triangleAmount;R++) {
			glVertex2f(
		            x + (radius * cos(R *  twicePi / triangleAmount)),
			    y + (radius * sin(R * twicePi / triangleAmount))
			);
		}
	glEnd();

//c4

///cloud 4
glTranslatef(position1,0.0f, 0.0f);
glColor3f(1.0, 1.0, 1.0);

    int T;
     x=-.7f; y=.7f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(T = 0; T <= triangleAmount;T++) {
			glVertex2f(
		            x + (radius * cos(T *  twicePi / triangleAmount)),
			    y + (radius * sin(T * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int U;
     x=-.66f; y=.7f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(U = 0; U <= triangleAmount;U++) {
			glVertex2f(
		            x + (radius * cos(U *  twicePi / triangleAmount)),
			    y + (radius * sin(U * twicePi / triangleAmount))
			);
		}
	glEnd();

	int I;
     x=-.63f; y=.675f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(I = 0; I <= triangleAmount;I++) {
			glVertex2f(
		            x + (radius * cos(I *  twicePi / triangleAmount)),
			    y + (radius * sin(I * twicePi / triangleAmount))
			);
		}
	glEnd();

int O;
     x=-.675f; y=.665f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(O = 0; O <= triangleAmount;O++) {
			glVertex2f(
		            x + (radius * cos(O *  twicePi / triangleAmount)),
			    y + (radius * sin(O * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();
}


void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(.5);

///Sky
    glBegin(GL_QUADS);
    glColor3f(0.501, 0.874, 1.0);
    glVertex2f(-1, -5);
    glVertex2f(1, -5);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

//*********************************FIELD START************************
    glBegin(GL_QUADS);    //Field
    glColor3f(0.1333,0.545,0.1333);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.5);
    glVertex2f(-1,-0.5);
    glEnd();

//*********************************ROAD START*************************
    glBegin(GL_QUADS);    //Road
    glColor3f(0.4078,0.3882,0.3843);
    glVertex2f(-1,-0.5);
    glVertex2f(1,-0.5);
    glVertex2f(1,-0.15);
    glVertex2f(-1,-0.15);
    glEnd();

    glLineWidth(3);          //Road  middle line yellow
    glBegin(GL_LINES);
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-0.9,-0.325);
    glVertex2f(-0.7,-0.325);
    glVertex2f(-0.5,-0.325);
    glVertex2f(-0.3,-0.325);
    glVertex2f(-0.1,-0.325);
    glVertex2f(0.1,-0.325);
    glVertex2f(0.3,-0.325);
    glVertex2f(0.5,-0.325);
    glVertex2f(0.7,-0.325);
    glVertex2f(0.9,-0.325);
    glEnd();

    glBegin(GL_LINES);          //Road Side line yellow
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-1,-0.5);
    glVertex2f(1,-0.5);
    glVertex2f(1,-0.15);
    glVertex2f(-1,-0.15);
    glEnd();
//*********************************ROAD START**************************************************


//*********************************D BUILDING START********************************************
    glBegin(GL_QUADS);    //D_Body
    glColor3ub(86, 194, 245);
    glVertex2f(0.076,-0.14);
    glVertex2f(0.90,-0.14);
    glVertex2f(0.90,0.59);
    glVertex2f(0.076,0.59);
    glEnd();

    glBegin(GL_QUADS);  //1side building
    glColor3ub(86, 194, 245);
    glVertex2f(0.90,-0.14);
    glVertex2f(0.99,-0.14);
    glVertex2f(0.99,0.53);
    glVertex2f(0.90,0.59);
    glEnd();

    glBegin(GL_QUADS);  //2side building
    glColor3ub(164, 164, 164);
    glVertex2f(0.90,0.57);
    glVertex2f(0.99,0.53);
    glVertex2f(0.99,0.55);
    glVertex2f(0.90,0.59);
    glEnd();

    glBegin(GL_QUADS);  //3side building
    glColor3ub(164, 164, 164);
    glVertex2f(0.99,-0.14);
    glVertex2f(1,-0.14);
    glVertex2f(1,0.544);
    glVertex2f(0.99,0.55);
    glEnd();

    glBegin(GL_QUADS);  //4side building
    glColor3ub(164, 164, 164);
    glVertex2f(0.90,0.42);
    glVertex2f(0.95,0.39);
    glVertex2f(0.95,0.55);
    glVertex2f(0.90,0.59);
    glEnd();

    glBegin(GL_QUADS);    //D_line 1
    glColor3ub(57, 60, 61);
    glVertex2f(0.076,-0.14);
    glVertex2f(0.85,-0.14);
    glVertex2f(0.85,-0.13);
    glVertex2f(0.076,-0.13);
    glEnd();

    glBegin(GL_QUADS);    //D_line 2
    glColor3f(0.6862,0.9333,0.9333);
    glVertex2f(0.076,-0.13);
    glVertex2f(0.90,-0.13);
    glVertex2f(0.90,-0.07);
    glVertex2f(0.076,-0.07);
    glEnd();

    glBegin(GL_QUADS);    //D_line 3
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,-0.07);
    glVertex2f(0.90,-0.07);
    glVertex2f(0.90,-0.05);
    glVertex2f(0.076,-0.05);
    glEnd();

    glBegin(GL_QUADS);    //D_line 4
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,0);
    glVertex2f(0.90,0);
    glVertex2f(0.90,0.02);
    glVertex2f(0.076,0.02);
    glEnd();

    glBegin(GL_QUADS);    //D_line 5
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,0.07);
    glVertex2f(0.90,0.07);
    glVertex2f(0.90,0.09);
    glVertex2f(0.076,0.09);
    glEnd();

    glBegin(GL_QUADS);    //D_line 6
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,0.14);
    glVertex2f(0.90,0.14);
    glVertex2f(0.90,0.16);
    glVertex2f(0.076,0.16);
    glEnd();

    glBegin(GL_QUADS);    //D_line 7
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,0.21);
    glVertex2f(0.90,0.21);
    glVertex2f(0.90,0.23);
    glVertex2f(0.076,0.23);
    glEnd();

    glBegin(GL_QUADS);    //D_line 8
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,0.28);
    glVertex2f(0.90,0.28);
    glVertex2f(0.90,0.30);
    glVertex2f(0.076,0.30);
    glEnd();

    glBegin(GL_QUADS);    //D_line 9
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,0.35);
    glVertex2f(0.90,0.35);
    glVertex2f(0.90,0.37);
    glVertex2f(0.076,0.37);
    glEnd();

    glBegin(GL_QUADS);    //D_line 10
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,0.42);
    glVertex2f(0.90,0.42);
    glVertex2f(0.90,0.59);
    glVertex2f(0.076,0.59);
    glEnd();

    glBegin(GL_QUADS);    //D_line 11
    glColor3ub(57, 60, 61);
    glVertex2f(0.076,0.44);
    glVertex2f(0.81,0.44);
    glVertex2f(0.81,0.47);
    glVertex2f(0.076,0.47);
    glEnd();

    glBegin(GL_QUADS);    //D_line 12
    glColor3ub(57, 60, 61);
    glVertex2f(0.076,0.49);
    glVertex2f(0.81,0.49);
    glVertex2f(0.81,0.52);
    glVertex2f(0.076,0.52);
    glEnd();

    glBegin(GL_QUADS);    //D_line 13
    glColor3ub(57, 60, 61);
    glVertex2f(0.076,0.54);
    glVertex2f(0.81,0.54);
    glVertex2f(0.81,0.57);
    glVertex2f(0.076,0.57);
    glEnd();


    glBegin(GL_QUADS);    //D Left side
    glColor3ub(164, 164, 164);
    glVertex2f(0.076,-0.14);
    glVertex2f(0.056,-0.14);
    glVertex2f(0.056,0.59);
    glVertex2f(0.076,0.59);
    glEnd();
//*********************************D BUILDING END


//*********************************C BUILDING START
GLfloat x=-0.3f;
	GLfloat y=0.245f;
	GLfloat radius =0.34f;
	int triangleAmount = 100; //Decide the number of triangles used to draw a circle
	//float angel1=8.0f;

	GLfloat twicePi = 2.0f * PI; // constant value for the angle 2*pi in radians

	glBegin(GL_TRIANGLE_FAN); // blue circle on the center

	glColor3ub(174, 181, 182);
    glVertex2f(x,y);
    for(int i = 0; i<= triangleAmount;i++) {
    glVertex2f
			(
                x + (radius * cos(i * twicePi/ triangleAmount)),
			    y + (radius * sin(i * twicePi/ triangleAmount))
			);
		}
	glEnd();


    //Antina

 glBegin(GL_QUADS);
  glColor3f(0.129,0.184,0.239);
 glVertex2f(-0.4,0.569);
 glVertex2f(-0.403,0.569);
 glVertex2f(-0.403,0.65);
 glVertex2f(-0.4,0.65);
 glEnd();


  //BuildingBase
 glBegin(GL_QUADS);
 glColor3ub(86, 194, 245);
 glVertex2f(-0.5,-0.145);
 glVertex2f(-0.5,-0.09);
 glVertex2f(-0.08,-0.09);
 glVertex2f(-0.08,-0.145);
 glEnd();
                                //FloorBase on cubicle

 glBegin(GL_POLYGON); //2nd

 glColor3ub(86, 194, 245);
 glVertex2f(-0.601,0.4);
 glVertex2f(-0.625,0.347);
 glVertex2f(0.026,0.347);
 glVertex2f(0.0035,0.4);
 glEnd();

 glBegin(GL_POLYGON); //4TH

 glColor3ub(86, 194, 245);
 glVertex2f(-0.602,0.08);
 glVertex2f(-0.570,0.04);
 glVertex2f(-0.03,0.04);
 glVertex2f(-0.0012,0.08);
 glEnd();

 glBegin(GL_POLYGON); //3RD

 glColor3ub(86, 194, 245);
 glVertex2f(-0.639,0.245);
 glVertex2f(-0.634,0.193);
 glVertex2f(0.035,0.193);
 glVertex2f(0.04,0.245);
 glEnd();


 glBegin(GL_POLYGON); //1ST

 glColor3ub(86, 194, 245);
 glVertex2f(-0.545,0.483);
 glVertex2f(-0.484,0.532);
 glVertex2f(-0.11,0.531);
 glVertex2f(-0.05,0.483);
 glEnd();

//*********************************C BUILDING END**********************


//*********************************ANNEX START*************************
    glBegin(GL_QUADS);
    glColor3f(0.7803,0.9176,0.9843);
    glVertex2f(-1,-0.14);
    glVertex2f(-0.64,-0.14);
    glVertex2f(-0.64,0.15);
    glVertex2f(-1,0.15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.92,0.15);
    glVertex2f(-0.72,0.15);
    glVertex2f(-0.72,0.22);
    glVertex2f(-0.82,0.27);
    glVertex2f(-0.92,0.22);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-1,-0.001);
    glVertex2f(-0.64,-0.001);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-1,0.15);
    glVertex2f(-0.64,0.15);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.997,-0.14);
    glVertex2f(-0.997,0.15);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-1,-0.14);
    glVertex2f(-0.64,-0.14);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.64,-0.14);
    glVertex2f(-0.64,0.15);
    glEnd();

    glLineWidth(1);     //middle divider line
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.82,-0.14);
    glVertex2f(-0.82,0.15);
    glEnd();

    glLineWidth(1);     //1st middle divider line left
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.91,-0.14);
    glVertex2f(-0.91,0.15);
    glEnd();

    glLineWidth(1);     //2nd middle divider line left
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.955,-0.14);
    glVertex2f(-0.955,0.15);
    glEnd();

    glLineWidth(1);     //3rd middle divider line left
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.865,-0.14);
    glVertex2f(-0.865,0.15);
    glEnd();

    glLineWidth(1);     //2nd middle divider line left
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.9775,-0.14);
    glVertex2f(-0.9775,0.15);
    glEnd();

    glLineWidth(1);     //2nd middle divider line left
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.9325,-0.14);
    glVertex2f(-0.9325,0.15);
    glEnd();

    glLineWidth(1);     //2nd middle divider line left
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.8875,-0.14);
    glVertex2f(-0.8875,0.15);
    glEnd();

    glLineWidth(1);     //2nd middle divider line left
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.8425,-0.14);
    glVertex2f(-0.8425,0.15);
    glEnd();
///////////////

    glLineWidth(1);     //1st middle divider line right
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.73,-0.14);
    glVertex2f(-0.73,0.15);
    glEnd();

    glLineWidth(1);     //2nd middle divider line right
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.685,-0.14);
    glVertex2f(-0.685,0.15);
    glEnd();

    glLineWidth(1);     //3rd middle divider line right
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.775,-0.14);
    glVertex2f(-0.775,0.15);
    glEnd();

    glLineWidth(1);     //3rd middle divider line right
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.6625,-0.14);
    glVertex2f(-0.6625,0.15);
    glEnd();

    glLineWidth(1);     //3rd middle divider line right
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.7075,-0.14);
    glVertex2f(-0.7075,0.15);
    glEnd();

    glLineWidth(1);     //3rd middle divider line right
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.7525,-0.14);
    glVertex2f(-0.7525,0.15);
    glEnd();

    glLineWidth(1);     //3rd middle divider line right
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.7975,-0.14);
    glVertex2f(-0.7975,0.15);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    p="AIUB";
    glRasterPos2f(-0.85 , 0.19);
    for(int i = 0; p[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, p[i]);

    sun();
    cloud_1();
    vehicles();
    glFlush();
}
//*********************************ANNEX END*************************
///***********************************************FULL VIEW END****************************************************************



///***********************************************D BUILDING START*************************************************************
GLfloat Position1 = 0.0f;
GLfloat Speed1 = 0.02f;

GLfloat Position2 = 0.0f;
GLfloat Speed2 = 0.02f;

GLfloat Position3 = 0.0f;
GLfloat Speed3 = 0.02f;

void nazmusRain(int value)
{
   if(Position1 <-1.0)
        Position1 = 0.2f;
        Position1 -= Speed1;
        glutPostRedisplay();

    if(Position2 >1.0)
        Position2 = -0.1f;
        Position2 += Speed2;
        glutPostRedisplay();

    if(Position3 <1.0)
        Position3 = -0.1f;
        Position1 -= Speed3;
        glutPostRedisplay();

    glutTimerFunc(100, nazmusRain, 0);
}

void rainCase(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        break;

    case GLUT_KEY_DOWN:
        break;

        case GLUT_KEY_LEFT:
            Speed2=0.01;
            break;

        case GLUT_KEY_RIGHT:
            Speed2=0.04;
            break;
    }
    glutPostRedisplay();
}

//*************************************CAR START********************************
GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.007f;
void nazmusCar(int value)
{
    if(carPosition < - 1.5)
    {
        carPosition = 1.2f;
    }
    else if(carPosition > 1.5){
        carPosition = -1.2f;
    }
    carPosition += carSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, nazmusCar, 0);
}

void circlecarnazmus(float x, float y, float radius)
{
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}

//***************************************CAR*********************************
void nazmus_vehicle1()
{
   glPushMatrix();
    glTranslatef(-carPosition,0.05f, 0.0f);

    glColor3ub(255,255,0);      //body
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();

    glColor3ub(233,0,0);           //wheels
    circlecarnazmus(0.07,-0.938,0.035);
    circlecarnazmus(0.2,-0.938,0.035);

    glColor3ub(153,206,250);    //window-1
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();

    glColor3ub(153,206,250);     //window-2
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();

    glColor3ub(0,0,0);  //door
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();
    glPopMatrix();
}


void nazmus_display (void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);        //BG Color
    glClear(GL_COLOR_BUFFER_BIT);

//*****************************************SKY*******************************
    glBegin(GL_QUADS);
    glColor3ub(63, 161, 186);
    glVertex2f(-1, -0.5);
    glVertex2f(1, -0.5);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

//*****************************************D BUILDING START*******************
   glBegin(GL_QUADS);      //MAIN BUILDING
    glColor3ub(164, 164, 164);
    glVertex2f(-0.32, -0.5);
    glVertex2f(0.6, -0.5);
    glVertex2f(0.6, 0.5);
    glVertex2f(-0.32, 0.5);
    glEnd();

    glBegin(GL_QUADS);      //LEFT MAIN BUILDING
    glColor3ub(164, 164, 164);
    glVertex2f(-0.545, -0.5);
    glVertex2f(-0.32, -0.5);
    glVertex2f(-0.32, 0.5);
    glVertex2f(-0.545, 0.47);
    glEnd();

    glBegin(GL_POLYGON);      //LEFT SIDE
    glColor3ub(86, 194, 245);
    glVertex2f(-0.53, -0.48);
    glVertex2f(-0.32, -0.48);
    glVertex2f(-0.32, 0.18);
    glVertex2f(-0.4, 0.17);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.53, 0.45);
    glEnd();

    glBegin(GL_QUADS);      //MIDDLE SIDE-1 (BLACK)
    glColor3ub(57, 60, 61);
    glVertex2f(-0.15, 0.42);
    glVertex2f(0.54, 0.42);
    glVertex2f(0.54, 0.48);
    glVertex2f(-0.15, 0.48);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);      //MIDDLE SIDE-2 (BLACK)
    glColor3ub(57, 60, 61);
    glVertex2f(-0.15, 0.42);
    glVertex2f(0.54, 0.42);
    glVertex2f(0.54, 0.48);
    glVertex2f(-0.15, 0.48);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);      //MIDDLE SIDE-3 (BLACK)
    glColor3ub(57, 60, 61);
    glVertex2f(-0.15, 0.42);
    glVertex2f(0.54, 0.42);
    glVertex2f(0.54, 0.48);
    glVertex2f(-0.15, 0.48);
    glEnd();
    glLoadIdentity();

    glBegin(GL_QUADS);      //MIDDLE SIDE-4
    glColor3ub(86, 194, 245);
    glVertex2f(-0.28, 0.12);
    glVertex2f(0.54, 0.12);
    glVertex2f(0.54, 0.18);
    glVertex2f(-0.28, 0.18);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);      //MIDDLE SIDE-5
    glColor3ub(86, 194, 245);
    glVertex2f(-0.28, 0.12);
    glVertex2f(0.54, 0.12);
    glVertex2f(0.54, 0.18);
    glVertex2f(-0.28, 0.18);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);      //MIDDLE SIDE-6
    glColor3ub(86, 194, 245);
    glVertex2f(-0.28, 0.12);
    glVertex2f(0.54, 0.12);
    glVertex2f(0.54, 0.18);
    glVertex2f(-0.28, 0.18);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);      //MIDDLE SIDE-7
    glColor3ub(86, 194, 245);
    glVertex2f(-0.28, 0.12);
    glVertex2f(0.54, 0.12);
    glVertex2f(0.54, 0.18);
    glVertex2f(-0.28, 0.18);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);      //MIDDLE SIDE-8
    glColor3ub(86, 194, 245);
    glVertex2f(-0.28, 0.12);
    glVertex2f(0.54, 0.12);
    glVertex2f(0.54, 0.18);
    glVertex2f(-0.28, 0.18);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);      //MIDDLE SIDE-9
    glColor3ub(86, 194, 245);
    glVertex2f(-0.28, 0.12);
    glVertex2f(0.54, 0.12);
    glVertex2f(0.54, 0.18);
    glVertex2f(-0.28, 0.18);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);      //MIDDLE SIDE-10
    glColor3ub(86, 194, 245);
    glVertex2f(-0.28, 0.12);
    glVertex2f(0.54, 0.12);
    glVertex2f(0.54, 0.18);
    glVertex2f(-0.28, 0.18);
    glEnd();
    glLoadIdentity();

    glBegin(GL_QUADS);      //RIGHT SIDE
    glColor3ub(174, 181, 182);
    glVertex2f(0.6, -0.47);
    glVertex2f(0.68, -0.47);
    glVertex2f(0.68, 0.45);
    glVertex2f(0.6, 0.45);
    glEnd();

    glBegin(GL_QUADS);  //RIGHT QUADS-1
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);  //RIGHT QUADS-2
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);  //RIGHT QUADS-3
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);  //RIGHT QUADS-4
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);  //RIGHT QUADS-5
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);  //RIGHT QUADS-6
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);  //RIGHT QUADS-7
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);  //RIGHT QUADS-8
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glTranslatef(0,-.1,0);

    glBegin(GL_QUADS);  //RIGHT QUADS-9
    glColor3ub(57, 60, 61);
    glVertex2f(0.61, 0.35);
    glVertex2f(0.67, 0.35);
    glVertex2f(0.67, 0.43);
    glVertex2f(0.61, 0.43);
    glEnd();
    glLoadIdentity();


//***************************************ROAD START******************************
    glBegin(GL_QUADS);  //ROAD
    glColor3ub(119, 123, 124);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.5);
    glVertex2f(-1, -0.5);
    glEnd();

    glBegin(GL_QUADS); //SIDE ROAD  UP
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-1, -0.55);
    glVertex2f(1, -0.55);
    glVertex2f(1, -0.5);
    glVertex2f(-1, -0.5);
    glEnd();

    glBegin(GL_QUADS);  //SIDE ROAD DOWN
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.95);
    glVertex2f(-1, -0.95);
    glEnd();

    glBegin(GL_QUADS);  //ZEBRA CROSSING-1
    glColor3ub(222, 222, 222);
    glVertex2f(-0.28, -0.59);
    glVertex2f(0, -0.59);
    glVertex2f(0, -0.57);
    glVertex2f(-0.28, -0.57);
    glEnd();
    glTranslatef(0,-.08,0);

    glBegin(GL_QUADS);  //ZEBRA CROSSING-2
    glColor3ub(222, 222, 222);
    glVertex2f(-0.28, -0.59);
    glVertex2f(0, -0.59);
    glVertex2f(0, -0.57);
    glVertex2f(-0.28, -0.57);
    glEnd();
    glTranslatef(0,-.08,0);

    glBegin(GL_QUADS);  //ZEBRA CROSSING-3
    glColor3ub(222, 222, 222);
    glVertex2f(-0.28, -0.59);
    glVertex2f(0, -0.59);
    glVertex2f(0, -0.57);
    glVertex2f(-0.28, -0.57);
    glEnd();
    glTranslatef(0,-.08,0);

    glBegin(GL_QUADS);  //ZEBRA CROSSING-4
    glColor3ub(222, 222, 222);
    glVertex2f(-0.28, -0.59);
    glVertex2f(0, -0.59);
    glVertex2f(0, -0.57);
    glVertex2f(-0.28, -0.57);
    glEnd();
    glTranslatef(0,-.08,0);

    glBegin(GL_QUADS);  //ZEBRA CROSSING-5
    glColor3ub(222, 222, 222);
    glVertex2f(-0.28, -0.59);
    glVertex2f(0, -0.59);
    glVertex2f(0, -0.57);
    glVertex2f(-0.28, -0.57);
    glEnd();
    glLoadIdentity();

//*****************************************ROAD DEVIDER*******************************
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-0.78, -0.75);
    glVertex2f(-0.50, -0.75);
    glVertex2f(-0.50, -0.73);
    glVertex2f(-0.78, -0.73);
    glEnd();
    glTranslatef(0.9,0,0);

    glBegin(GL_QUADS);
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-0.78, -0.75);
    glVertex2f(-0.50, -0.75);
    glVertex2f(-0.50, -0.73);
    glVertex2f(-0.78, -0.73);
    glEnd();
    glTranslatef(0.9,0,0);

    glBegin(GL_QUADS);
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-0.78, -0.75);
    glVertex2f(-0.50, -0.75);
    glVertex2f(-0.50, -0.73);
    glVertex2f(-0.78, -0.73);
    glEnd();
    glLoadIdentity();

//******************************************MUKTA MANCHA******************************
    glBegin(GL_QUADS);      //Main quad
    glColor3ub(93, 183, 13);
    glVertex2f(-0.98, -0.2);
    glVertex2f(-0.95, -0.2);
    glVertex2f(-0.95, -0.5);
    glVertex2f(-0.98, -0.5);
    glEnd();

    glBegin(GL_QUADS);          //lest small quad
    glColor3ub(84, 83, 61);
    glVertex2f(-0.99, -0.36);
    glVertex2f(-0.95, -0.36);
    glVertex2f(-0.95, -0.34);
    glVertex2f(-0.99, -0.34);
    glEnd();

    glBegin(GL_QUADS);      //Stage
    glColor3ub(254, 252, 212);
    glVertex2f(-0.95, -0.42);
    glVertex2f(-0.85, -0.5);
    glVertex2f(-0.85, -0.2);
    glVertex2f(-0.95, -0.28);
    glEnd();

    glLineWidth(2.5);   //down
    glBegin(GL_LINES);
    glColor3ub(84, 83, 61);
    glVertex2f(-0.99, -0.356);
    glVertex2f(-0.9, -0.5);
    glEnd();

    glLineWidth(2.5);   //up
    glBegin(GL_LINES);
    glColor3ub(84, 83, 61);
    glVertex2f(-0.99, -0.34);
    glVertex2f(-0.9, -0.2);
    glEnd();

    glLineWidth(2.5);    //second down
    glBegin(GL_LINES);
    glColor3ub(84, 83, 61);
    glVertex2f(-0.99, -0.356);
    glVertex2f(-0.9, -0.4);
    glEnd();

    glLineWidth(2.5);  //second up
    glBegin(GL_LINES);
    glColor3ub(84, 83, 61);
    glVertex2f(-0.99, -0.342);
    glVertex2f(-0.9, -0.3);
    glEnd();

    glLineWidth(2.5);  //down joining
    glBegin(GL_LINES);
    glColor3ub(84, 83, 61);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.92, -0.45);
    glVertex2f(-0.92, -0.45);
    glVertex2f(-0.92, -0.42);
    glVertex2f(-0.92, -0.42);
    glVertex2f(-0.9, -0.4);
    glEnd();

    glLineWidth(2.5);  //UP joining
    glBegin(GL_LINES);
    glColor3ub(84, 83, 61);
    glVertex2f(-0.9, -0.2);
    glVertex2f(-0.92, -0.25);
    glVertex2f(-0.92, -0.25);
    glVertex2f(-0.92, -0.28);
    glVertex2f(-0.92, -0.28);
    glVertex2f(-0.9, -0.3);
    glEnd();

    glLineWidth(2.5);  //Middle joining
    glBegin(GL_LINES);
    glColor3ub(84, 83, 61);
    glVertex2f(-0.9, -0.3);
    glVertex2f(-0.92, -0.33);
    glVertex2f(-0.92, -0.33);
    glVertex2f(-0.92, -0.37);
    glVertex2f(-0.92, -0.37);
    glVertex2f(-0.9, -0.4);
    glEnd();


//*****************************************TREE 1, 2 & 3*******************************
    glBegin(GL_QUADS);  //Right tree 1
    glColor3ub(156, 139, 102);
    glVertex2f(0.76, -0.5);
    glVertex2f(0.8, -0.5);
    glVertex2f(0.8, -0.25);
    glVertex2f(0.76, -0.25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(35, 174, 43);
    glVertex2f(0.7, -0.25);
    glVertex2f(0.85, -0.25);
    glVertex2f(0.775, -0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.7, -0.2);
    glVertex2f(0.85, -0.2);
    glVertex2f(0.775, 0.0);
    glEnd();
    glTranslatef(0.15,0,0);

    glBegin(GL_QUADS);     //Right tree 2
    glColor3ub(156, 139, 102);
    glVertex2f(0.76, -0.5);
    glVertex2f(0.8, -0.5);
    glVertex2f(0.8, -0.25);
    glVertex2f(0.76, -0.25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(35, 174, 43);
    glVertex2f(0.7, -0.25);
    glVertex2f(0.85, -0.25);
    glVertex2f(0.775, -0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.7, -0.2);
    glVertex2f(0.85, -0.2);
    glVertex2f(0.775, 0.0);
    glEnd();
    glTranslatef(-1.6,0,0);

    glBegin(GL_QUADS);  //Left tree 1
    glColor3ub(156, 139, 102);
    glVertex2f(0.76, -0.5);
    glVertex2f(0.8, -0.5);
    glVertex2f(0.8, -0.25);
    glVertex2f(0.76, -0.25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(35, 174, 43);
    glVertex2f(0.7, -0.25);
    glVertex2f(0.85, -0.25);
    glVertex2f(0.775, -0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.7, -0.2);
    glVertex2f(0.85, -0.2);
    glVertex2f(0.775, 0.0);
    glEnd();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(Position2,0.0f, 0.0f);


//**************************************CLOUD-1*******************************
 int j;
    GLfloat x=-0.6f;
    GLfloat y=0.66f;
    GLfloat radius =0.05f;
    int triangleAmount = 20;  //Triangle used to draw circle

    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(185, 191, 192);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.55f;
    y=0.71f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(185, 191, 192);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.54f;
    y=0.65f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(185, 191, 192);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//**************************************CLOUD-2*******************************
    x=-0.2f;
    y=0.81f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 242, 243);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.15f;
    y=0.86f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 242, 243);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.14f;
    y=0.80f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 242, 243);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//**************************************CLOUD-3*******************************
    x=0.3f;
    y=0.81f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(236, 240, 241);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.35f;
    y=0.87f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(236, 240, 241);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.37f;
    y=0.77f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(236, 240, 241);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//**************************************CLOUD-4*******************************
    x=-0.3f;
    y=0.81f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.35f;
    y=0.87f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.37f;
    y=0.77f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//**************************************CLOUD-5*******************************
 x=-0.99f;
    y=0.72f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
   glColor3ub(185, 191, 192);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.95f;
    y=0.77f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(185, 191, 192);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.95f;
    y=0.68f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(185, 191, 192);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.92f;
    y=0.72f;
    radius =0.045f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(185, 191, 192);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//**************************************CLOUD-6*******************************
    x=0.8f;
    y=0.72f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(200, 201, 202);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.76f;
    y=0.77f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(200, 201, 202);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.76f;
    y=0.68f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(200, 201, 202);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.73f;
    y=0.72f;
    radius =0.045f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(200, 201, 202);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


//**************************************CLOUD-7*******************************
    x=0.5f;
    y=0.67f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.46f;
    y=0.72f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.46f;
    y=0.63f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.43f;
    y=0.68f;
    radius =0.045f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


//**************************************CLOUD-8*******************************
    x=0.1f;
    y=0.67f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 228, 229);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.06f;
    y=0.72f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 228, 229);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.06f;
    y=0.63f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 228, 229);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.03f;
    y=0.68f;
    radius =0.045f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 228, 229);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//**************************************CLOUD-9*******************************
    x=-0.75f;
    y=0.68f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 232, 233);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.7f;
    y=0.71f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 232, 233);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.7f;
    y=0.65f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 232, 233);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(Position2, Position1, 0.0f);


//******************************************RAIN LINE-1******************************
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glLoadIdentity();

    glPopMatrix();
    glTranslatef(0, 0.4, 0);
    glPushMatrix();
    glTranslatef(Position2, Position1, 0.0f);

//******************************************RAIN LINE-2******************************
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);
    glLoadIdentity();

    glPopMatrix();
    glTranslatef(0, -0.4, 0);
    glPushMatrix();
    glTranslatef(Position2, Position1, 0.0f);

//******************************************RAIN LINE-3******************************
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);
    glLoadIdentity();

    glPopMatrix();
    glTranslatef(0, -0.8, 0);
    glPushMatrix();
    glTranslatef(Position2, Position1, 0.0f);

//******************************************RAIN LINE-4******************************
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);


    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();

    glLoadIdentity();
    glPopMatrix();
    glLoadIdentity();

    nazmus_vehicle1();
    glFlush();

}

///******************************************************D BUILDING END*********************************************************


///******************************************************C BUILDING START*******************************************************
GLfloat position7 = 0.0f;
GLfloat speed7 = 0.006f;//c1

GLfloat position8 = 0.0f;
GLfloat speed8 = 0.0010f;//c1

GLfloat position10 = 0.0f;
GLfloat speed10 = 0.0014f;//c2

GLfloat position9 = 0.0f;
GLfloat speed9 = 0.0018f;//c3

GLfloat carPosition6 = 0.0f;
GLfloat carSpeed6 = 0.008f;
void arnobupdate(int value) {

    if(position7 > 0.9){
        position7 = -1.4f;
    }
    position7 += speed7;

	glutPostRedisplay();


	glutTimerFunc(100, arnobupdate, 0);

}

void arnobupdate_3(int value) {

    if(position8 > 1.3){
        position8 = -1.4f;
    }
    position8 += speed8;

	glutPostRedisplay();


	glutTimerFunc(100, arnobupdate, 0);

}


void arnobupdate_2(int value) {

    if(position10> 1.7){
        position7 = -1.4f;
    }
    position10+= speed10;

	glutPostRedisplay();


	glutTimerFunc(100, arnobupdate_2, 0);

}


	void arnobupdate1(int value) {

    if(position5 > 2.1){
        position5 = -1.4f;
    }
    position9 += speed9;

	glutPostRedisplay();


	glutTimerFunc(100, arnobupdate1, 0);
}

void arnobupdateCar(int value)
{
    if(carPosition6 < - 1.5)
    {
        carPosition6 = 1.2f;
    }
    else if(carPosition6 > 1.5){
        carPosition6 = -1.2f;
    }
    carPosition6 += carSpeed6;

    glutPostRedisplay();

    glutTimerFunc(10, arnobupdateCar, 0);
}

void arnobsun(){

///Sun

  glColor3f(0.949, 1.0, 0);

    int k;
    GLfloat x=.8f; GLfloat y=.8f;GLfloat radius =.1f;
	 int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void arnobcirclecar(float x, float y, float radius)
{
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}


void arnobvehicle2()
{
   glPushMatrix();
    glTranslatef(-carPosition6,0.05f, 0.0f);
    //body
    glColor3f(1.0,1.0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();
    //wheels
    glColor3f(0.913,0,0);
    arnobcirclecar(0.07,-0.938,0.035);
    arnobcirclecar(0.2,-0.938,0.035);
    //
    glColor3f(0,0,0);
    glLineWidth(1.1);
    glBegin(GL_LINES);
    glVertex2f(0.141f,-0.758f);
    glVertex2f(0.141f,-0.842f);
    glEnd();
    //window
    glColor3f(0.6,0.807,0.98);
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();
    glColor3f(0.6,0.807,0.98);
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();
    //door
    glColor3f(0,0,0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();
    glPopMatrix();
}

void arnobcloud_2(){
glPushMatrix();
glTranslatef(position7,0.0f, 0.0f);

 glColor3f(1.0, 1.0, 1.0);

    int f;
GLfloat x=.7f; GLfloat y=.8f;GLfloat radius =.03f;
	 int triangleAmount = 20; //# of triangles used to draw circle

GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(f = 0; f <= triangleAmount;f++) {
			glVertex2f(
		            x + (radius * cos(f *  twicePi / triangleAmount)),
			    y + (radius * sin(f * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int g;
     x=.74f; y=.8f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(g = 0; g <= triangleAmount;g++) {
			glVertex2f(
		            x + (radius * cos(g *  twicePi / triangleAmount)),
			    y + (radius * sin(g * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int h;
     x=.77f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(h = 0; h <= triangleAmount;h++) {
			glVertex2f(
		            x + (radius * cos(h *  twicePi / triangleAmount)),
			    y + (radius * sin(h * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int l;
     x=.725f; y=.775f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(l = 0; l <= triangleAmount;l++) {
			glVertex2f(
		            x + (radius * cos(l *  twicePi / triangleAmount)),
			    y + (radius * sin(l * twicePi / triangleAmount))
			);
		}
	glEnd();

	///cloud 2
glColor3f(1.0, 1.0, 1.0);

    int F;
     x=0.07f; y=.80f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(F = 0; F <= triangleAmount;F++) {
			glVertex2f(
		            x + (radius * cos(F *  twicePi / triangleAmount)),
			    y + (radius * sin(F * twicePi / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);


    int G;
     x=.11f; y=.80f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(G = 0; G <= triangleAmount;G++) {
			glVertex2f(
		            x + (radius * cos(G *  twicePi / triangleAmount)),
			    y + (radius * sin(G * twicePi / triangleAmount))
			);
		}
	glEnd();

int H;
     x=.15f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(H = 0; H <= triangleAmount;H++) {
			glVertex2f(
		            x + (radius * cos(H *  twicePi / triangleAmount)),
			    y + (radius * sin(H * twicePi / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);

    int L;
     x=.10f; y=.765f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(L = 0; L <= triangleAmount;L++) {
			glVertex2f(
		            x + (radius * cos(L *  twicePi / triangleAmount)),
			    y + (radius * sin(L * twicePi / triangleAmount))
			);
		}
	glEnd();


///cloud3
glColor3f(1.0, 1.0, 1.0);
glTranslatef(position10,0.0f, 0.0f);
    int Q;
     x=-.2f; y=.8f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(Q = 0; Q <= triangleAmount;Q++) {
			glVertex2f(
		            x + (radius * cos(Q *  twicePi / triangleAmount)),
			    y + (radius * sin(Q * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int W;
     x=-.16f; y=.8f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(W = 0; W <= triangleAmount;W++) {
			glVertex2f(
		            x + (radius * cos(W *  twicePi / triangleAmount)),
			    y + (radius * sin(W * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int E;
     x=-.13f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(E = 0; E <= triangleAmount;E++) {
			glVertex2f(
		            x + (radius * cos(E *  twicePi / triangleAmount)),
			    y + (radius * sin(E * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int R;
     x=-.175f; y=.765f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(R = 0; R <= triangleAmount;R++) {
			glVertex2f(
		            x + (radius * cos(R *  twicePi / triangleAmount)),
			    y + (radius * sin(R * twicePi / triangleAmount))
			);
		}
	glEnd();


///cloud 4
glTranslatef(position5,0.0f, 0.0f);
glColor3f(1.0, 1.0, 1.0);

    int T;
     x=-.7f; y=.8f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(T = 0; T <= triangleAmount;T++) {
			glVertex2f(
		            x + (radius * cos(T *  twicePi / triangleAmount)),
			    y + (radius * sin(T * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int U;
     x=-.66f; y=.8f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(U = 0; U <= triangleAmount;U++) {
			glVertex2f(
		            x + (radius * cos(U *  twicePi / triangleAmount)),
			    y + (radius * sin(U * twicePi / triangleAmount))
			);
		}
	glEnd();

	int I;
     x=-.63f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(I = 0; I <= triangleAmount;I++) {
			glVertex2f(
		            x + (radius * cos(I *  twicePi / triangleAmount)),
			    y + (radius * sin(I * twicePi / triangleAmount))
			);
		}
	glEnd();

int O;
     x=-.675f; y=.765f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(O = 0; O <= triangleAmount;O++) {
			glVertex2f(
		            x + (radius * cos(O *  twicePi / triangleAmount)),
			    y + (radius * sin(O * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();
}


void arnob_display(){

glClear(GL_COLOR_BUFFER_BIT);

///sky
    glBegin(GL_QUADS);
      glColor3f(0.501, 0.874, 1.0);
    glVertex2f(-1, -5);
    glVertex2f(1, -5);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

                                  //ROAD
 glBegin(GL_QUADS);
glColor3f(0.4,0.38,0.37);
 glVertex2f(-5,-0.71);
 glVertex2f(-5,-4);
 glVertex2f(10,-3);
 glVertex2f(10,-0.71);
 glEnd();


     glLineWidth(8);
    glBegin(GL_LINES);      //1st Road line
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-2.0,-0.77);
    glVertex2f(1.0,-0.77);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);      //2nd Road line
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-2.0,-0.95);
    glVertex2f(1.0,-0.95);
    glEnd();



     glLineWidth(5);
    glBegin(GL_LINES);      //Road  middle line yellow
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-0.9,-0.86);
    glVertex2f(-0.7,-0.86);
    glVertex2f(-0.5,-0.86);
    glVertex2f(-0.3,-0.86);
    glVertex2f(-0.1,-0.86);
    glVertex2f(0.1,-0.86);
    glVertex2f(0.3,-0.86);
    glVertex2f(0.5,-0.86);
    glVertex2f(0.7,-0.86);
    glVertex2f(0.9,-0.86);

    glEnd();


GLfloat x=0.0f;
	GLfloat y=0.04f;
	GLfloat radius =0.65f;
	int triangleAmount = 30; //Decide the number of triangles used to draw a circle


	GLfloat twicePi = 2.0f * PI; // constant value for the angle 2*pi in radians

	glBegin(GL_TRIANGLE_FAN); // blue circle on the center

	glColor3ub(174, 181, 182);
    glVertex2f(x,y);
    for(int i = 0; i<= triangleAmount;i++) {
    glVertex2f
			(
                x + (radius * cos(i * twicePi/ triangleAmount)),
			    y + (radius * sin(i * twicePi/ triangleAmount))
			);
		}
	glEnd();



    //Antina
 glBegin(GL_QUADS);

  glColor3f(0.129,0.184,0.239);
 glVertex2f(0.3,0.79);
 glVertex2f(0.304,0.79);
 glVertex2f(0.304,0.615);
 glVertex2f(0.3,0.615);
 glEnd();


  //BuildingBase
 glBegin(GL_QUADS);
 glColor3ub(86, 194, 245);
 glVertex2f(-0.23,-0.71);
 glVertex2f(-0.23,-0.6);
 glVertex2f(0.23,-0.6);
 glVertex2f(0.23,-0.71);
 glEnd();

                                //FloorBase on cubicle

 glBegin(GL_POLYGON); //5TH

 glColor3ub(86, 194, 245);
 glVertex2f(-0.475,-0.4);
 glVertex2f(-0.542,-0.32);
 glVertex2f(0.542,-0.32);
 glVertex2f(0.475,-0.4);
 glEnd();

 glBegin(GL_POLYGON); //4TH

 glColor3ub(86, 194, 245);
 glVertex2f(-0.603,-0.2);
 glVertex2f(-0.637,-0.09);
 glVertex2f(0.637,-0.09);
 glVertex2f(0.603,-0.2);
 glEnd();

 glBegin(GL_POLYGON); //3RD

 glColor3ub(86, 194, 245);
 glVertex2f(-0.646,0.09);
 glVertex2f(-0.6459,0.01);
 glVertex2f(0.6459,0.01);
 glVertex2f(0.646,0.09);
 glEnd();

 glBegin(GL_POLYGON); //2ND

 glColor3ub(86, 194, 245);
 glVertex2f(-0.628,0.2);
 glVertex2f(-0.597,0.3);
 glVertex2f(0.597,0.3);
 glVertex2f(0.628,0.2);
 glEnd();

 glBegin(GL_POLYGON); //1ST
 glColor3ub(86, 194, 245);
 glVertex2f(-0.519,0.43);
 glVertex2f(-0.430,0.53);
 glVertex2f(0.430,0.53);
 glVertex2f(0.519,0.43);
 glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.054, 0.356, 0.015);
    glVertex2f(-1.0,-0.62);
    glVertex2f(-1.0,-0.715);
    glVertex2f(-0.3,-0.715);
    glVertex2f(-0.3,-0.62);
    glEnd();



///parking lot

glBegin(GL_QUADS);
    glColor3f(0.451,0.451,0.451);
    glVertex2f(1.0,-0.55);
    glVertex2f(1.0,-0.710);
    glVertex2f(0.3,-0.710);
    glVertex2f(0.3,-0.55);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -0.65);
    glVertex2f(0.93f, -0.65f);
    glVertex2f(0.93f, -0.3f);
    glEnd();

 glVertex2f(0.3,-0.86);
    glVertex2f(0.5,-0.86);
    glVertex2f(0.7,-0.86);
    glVertex2f(0.9,-0.86);


    ///right side car

    glBegin(GL_QUADS);
     glColor3f(0,0,1);
     glVertex2f(.43,-0.68);
     glVertex2f(.43,-0.65);
     glVertex2f(.52,-0.65);
     glVertex2f(.52,-0.68);
     glEnd();
glBegin(GL_QUADS);
     glColor3f(0,0,1);
     glVertex2f(.46,-0.65);
     glVertex2f(.46,-0.61);
     glVertex2f(.513,-0.61);
     glVertex2f(.513,-0.65);
     glVertex2f(.465,-0.615);
     glVertex2f(.509,-0.615);
     glVertex2f(.509,-0.65);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(1.0, 0, 0);
     glVertex2f(.49,-0.61);
     glVertex2f(.49,-0.602);
     glVertex2f(.5,-0.602);
     glVertex2f(.5,-0.61);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0, 0, 0);
     glVertex2f(.465,-0.65);
     glVertex2f(.465,-0.615);
     glVertex2f(.509,-0.615);
     glVertex2f(.509,-0.65);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(1.0, 0, 0);
     glVertex2f(.49,-0.61);
     glVertex2f(.49,-0.602);
     glVertex2f(.5,-0.602);
     glVertex2f(.5,-0.61);
     glEnd();

     glColor3f(0.027, 0.031, 0.027);
     int a;

	 x=.45f;    y=-.690f;   radius =.013f;
	 triangleAmount = 20; //# of triangles used to draw circle

	  twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(a = 0; a <= triangleAmount;a++) {
			glVertex2f(
		            x + (radius * cos(a *  twicePi / triangleAmount)),
			    y + (radius * sin(a * twicePi / triangleAmount))
			);
		}
	glEnd();


    glColor3f(0.027, 0.031, 0.027);
    int s;

	 x=.50f;  y=-.690f;  radius =.013f;
	 triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(s = 0; s <= triangleAmount;s++) {
			glVertex2f(
		            x + (radius * cos(s *  twicePi / triangleAmount)),
			    y + (radius * sin(s * twicePi / triangleAmount))
			);
		}
	glEnd();

///right side car end

///Left side car
	  glBegin(GL_QUADS);
     glColor3f(0.721, 0, 0.901);
     glVertex2f(-.53,-0.69);
     glVertex2f(-.53,-0.66);
     glVertex2f(-.42,-0.66);
     glVertex2f(-.42,-0.69);
     glEnd();

glBegin(GL_QUADS);
     glColor3f(0.721, 0, 0.901);
     glVertex2f(-.46,-0.66);
     glVertex2f(-.46,-0.61);
     glVertex2f(-.513,-0.61);
     glVertex2f(-.513,-0.66);
     glEnd();


glBegin(GL_QUADS);
     glColor3f(0, 0, 0);
     glVertex2f(-.465,-0.66);
     glVertex2f(-.465,-0.615);
     glVertex2f(-.509,-0.615);
     glVertex2f(-.509,-0.66);
     glEnd();

    glColor3f(0.027, 0.031, 0.027);
    int m;

	 x=-.45f;  y=-.698f;  radius =.013f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(m = 0; m <= triangleAmount;m++) {
			glVertex2f(
		            x + (radius * cos(m *  twicePi / triangleAmount)),
			    y + (radius * sin(m * twicePi / triangleAmount))
			);
		}
	glEnd();


    glColor3f(0.027, 0.031, 0.027);
    int M;

	 x=-.50f;  y=-.698f;  radius =.013f;
	 triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(M = 0; M <= triangleAmount;M++) {
			glVertex2f(
		            x + (radius * cos(M *  twicePi / triangleAmount)),
			    y + (radius * sin(M * twicePi / triangleAmount))
			);
		}
	glEnd();
	///Left side car end

	///Right side car 2

	 glBegin(GL_QUADS);
     glColor3f(0.698,0.13,0.13);
     glVertex2f(.63,-0.68);
     glVertex2f(.63,-0.65);
     glVertex2f(.72,-0.65);
     glVertex2f(.72,-0.68);
     glEnd();

    glBegin(GL_QUADS);
     glColor3f(0.698,0.13,0.13);
     glVertex2f(.66,-0.65);
     glVertex2f(.66,-0.61);
     glVertex2f(.713,-0.61);
     glVertex2f(.713,-0.65);
     glVertex2f(.665,-0.615);
     glVertex2f(.709,-0.615);
     glVertex2f(.709,-0.65);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(1.0, 0, 0);
     glVertex2f(.69,-0.61);
     glVertex2f(.69,-0.602);
     glVertex2f(.7,-0.602);
     glVertex2f(.7,-0.61);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(0, 0, 0);
     glVertex2f(.665,-0.65);
     glVertex2f(.665,-0.615);
     glVertex2f(.709,-0.615);
     glVertex2f(.709,-0.65);
     glEnd();

     glBegin(GL_QUADS);
     glColor3f(1.0, 0, 0);
     glVertex2f(.69,-0.61);
     glVertex2f(.69,-0.602);
     glVertex2f(.7,-0.602);
     glVertex2f(.7,-0.61);
     glEnd();
     glColor3f(0.027, 0.031, 0.027);

     a;
	 x=.65f;    y=-.690f;   radius =.013f;
	 triangleAmount = 20; //# of triangles used to draw circle

	  twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(a = 0; a <= triangleAmount;a++) {
			glVertex2f(
		            x + (radius * cos(a *  twicePi / triangleAmount)),
			    y + (radius * sin(a * twicePi / triangleAmount))
			);
		}
	glEnd();


    glColor3f(0.027, 0.031, 0.027);
     s;

	 x=.70f;  y=-.690f;  radius =.013f;
	 triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(s = 0; s <= triangleAmount;s++) {
			glVertex2f(
		            x + (radius * cos(s *  twicePi / triangleAmount)),
			    y + (radius * sin(s * twicePi / triangleAmount))
			);
		}
	glEnd();
	///parking Lot End

	///Tree

	//Right Tee
       glBegin(GL_QUADS);
 glColor3f(0.611, 0.54, 0.4);
    glVertex2f(0.76, -0.71);
    glVertex2f(0.8, -0.71);
    glVertex2f(0.8, -0.45);
    glVertex2f(0.76, -0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.137, 0.682, 0.168);
    glVertex2f(0.7, -0.45);
    glVertex2f(0.85, -0.45);
    glVertex2f(0.775, -0.3);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.141, 0.82, 0.18);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.85, -0.4);
    glVertex2f(0.775, -0.2);
    glEnd();

//Left tree

 glBegin(GL_QUADS);  //Left tree 1
    glColor3f(0.611, 0.54, 0.4);
    glVertex2f(-0.76, -0.71);
    glVertex2f(-0.8, -0.71);
    glVertex2f(-0.8, -0.45);
    glVertex2f(-0.76, -0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.137, 0.682, 0.168);
    glVertex2f(-0.7, -0.45);
    glVertex2f(-0.85, -0.45);
    glVertex2f(-0.775, -0.3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.141, 0.82, 0.18);
    glVertex2f(-0.7, -0.4);
    glVertex2f(-0.85, -0.4);
    glVertex2f(-0.775, -0.2);
    glEnd();



///Tree end


    arnobsun();
    arnobvehicle2();
    arnobcloud_2();
    glFlush();
}
///******************************************************C BUILDING END*********************************************************


///******************************************************ANNEX BUILDING START*****************************************************
GLfloat Position20 = 0.0f;
GLfloat Speed20 = 0.02f;

GLfloat Position21 = 0.0f;
GLfloat Speed21 = 0.01f;

GLfloat Position31 = 0.0f;
GLfloat Speed31 = 0.04f;

char *c;
void annexRain(int value)
{
   if(Position20 <-1.0)
        Position20 = 0.2f;
        Position20 -= Speed20;
        glutPostRedisplay();

    if(Position21 >1.0)
        Position21 = -0.1f;
        Position21 += Speed21;
        glutPostRedisplay();

    if(Position31 <1.0)
        Position31 = -0.1f;
        Position20 -= Speed31;
        glutPostRedisplay();

    glutTimerFunc(100, annexRain, 0);
}
/*
void annex_rainCase(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_LEFT_BUTTON:
            Speed21=0.02;
            break;

        case GLUT_RIGHT_BUTTON:
            Speed21=0.05;
            break;
    }
    glutPostRedisplay();
}
*/

//******************************************CAR START******************************
GLfloat carPosition22 = 0.0f;
GLfloat carSpeed22 = 0.008f;
void annexCar(int value)
{
    if(carPosition < - 1.5)
    {
        carPosition = 1.2f;
    }
    else if(carPosition > 1.5){
        carPosition = -1.2f;
    }
    carPosition += carSpeed;

    glutPostRedisplay();

    glutTimerFunc(10, annexCar, 0);
}

void circlecarannex(float x, float y, float radius)
{
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}

//****************************************CAR********************************
void annex_vehicle1()
{
   glPushMatrix();
    glTranslatef(-carPosition,0.05f, 0.0f);

    glColor3ub(255,255,0);      //body
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,-0.94f);
    glVertex2f(0.275f, -0.94f);
    glVertex2f(0.275f,-0.859f);
    glVertex2f(0.22f,-0.842f);
    glVertex2f(0.18f,-0.758f);
    glVertex2f(0.1f, -0.758f);
    glVertex2f(0.08f,-0.842f);
    glVertex2f(0.0f,-0.856f);
    glEnd();

    glColor3ub(233,0,0);           //wheels
    circlecarannex(0.07,-0.938,0.035);
    circlecarannex(0.2,-0.938,0.035);

    glColor3ub(153,206,250);    //window-1
    glBegin(GL_POLYGON);
    glVertex2f(0.071,-0.842);
    glVertex2f(0.132,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.132,-0.77);
    glVertex2f(0.106,-0.77);
    glEnd();

    glColor3ub(153,206,250);     //window-2
    glBegin(GL_POLYGON);
    glVertex2f(0.148,-0.842);
    glVertex2f(0.206,-0.842);
    glColor3ub(100,149,237);
    glVertex2f(0.173,-0.77);
    glVertex2f(0.148,-0.77);
    glEnd();

    glColor3ub(0,0,0);  //door
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(0.11,-0.863);
    glVertex2f(0.13,-0.863);
    glVertex2f(0.186,-0.863);
    glVertex2f(0.206,-0.863);
    glColor3ub(255,255,255);
    glEnd();
    glPopMatrix();
}


void annex_display1 (void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);        //BG Color
    glClear(GL_COLOR_BUFFER_BIT);

//**************************************SKY**********************************
    glBegin(GL_QUADS);
    glColor3ub(63, 161, 186);
    glVertex2f(-1, -0.5);
    glVertex2f(1, -0.5);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

//**************************************ANNEX START******************************

    glBegin(GL_QUADS);
    glColor3f(0.7803,0.9176,0.9843);
    glVertex2f(-0.5,-0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.2);
    glVertex2f(-0.5,0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.3,0.2);
    glVertex2f(0.3,0.2);
    glVertex2f(0.3,0.35);
    glVertex2f(0,0.45);
    glVertex2f(-0.3,0.35);
    glEnd();

    glLineWidth(12);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.5,-0.15);
    glVertex2f(0.5,-0.15);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.5,0.21);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0.5,-0.5);
    glVertex2f(0.5,0.21);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.505,0.2);
    glVertex2f(0.504,0.2);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(-0.505,-0.49);
    glVertex2f(0.504,-0.49);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.05,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.05,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.1,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.1,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.15,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.15,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.2,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.2,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.25,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.25,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.3,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.3,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.35,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.35,0,0);


    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.4,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.4,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.45,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.45,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.05,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(0.05,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.1,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(0.1,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.15,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.15,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.2,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.2,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.25,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.25,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.3,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.3,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.35,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.35,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.4,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.4,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(-.45,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glTranslatef(.45,0,0);

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(86, 194, 245);
    glVertex2f(0,-0.5);
    glVertex2f(0,0.2);
    glEnd();
    glLoadIdentity();

//****************************************ROAD START********************************
    glBegin(GL_QUADS);  //ROAD
    glColor3ub(119, 123, 124);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.5);
    glVertex2f(-1, -0.5);
    glEnd();

    glBegin(GL_QUADS); //SIDE ROAD  UP
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-1, -0.55);
    glVertex2f(1, -0.55);
    glVertex2f(1, -0.5);
    glVertex2f(-1, -0.5);
    glEnd();

    glBegin(GL_QUADS);  //SIDE ROAD DOWN
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.95);
    glVertex2f(-1, -0.95);
    glEnd();

//*********************************ROAD DEVIDER*********************************
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-0.78, -0.75);
    glVertex2f(-0.50, -0.75);
    glVertex2f(-0.50, -0.73);
    glVertex2f(-0.78, -0.73);
    glEnd();
    glTranslatef(0.9,0,0);

    glBegin(GL_QUADS);
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-0.78, -0.75);
    glVertex2f(-0.50, -0.75);
    glVertex2f(-0.50, -0.73);
    glVertex2f(-0.78, -0.73);
    glEnd();
    glTranslatef(0.9,0,0);

    glBegin(GL_QUADS);
    glColor3f(0.98, 0.89, 0);
    glVertex2f(-0.78, -0.75);
    glVertex2f(-0.50, -0.75);
    glVertex2f(-0.50, -0.73);
    glVertex2f(-0.78, -0.73);
    glEnd();
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);
    c="AIUB";
    glRasterPos2f(-0.03 , 0.27);
    for(int i = 0; c[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);


//************************************TREE 1 & 2 **********************************
    glBegin(GL_QUADS);     //Right tree
    glColor3ub(156, 139, 102);
    glVertex2f(0.76, -0.5);
    glVertex2f(0.8, -0.5);
    glVertex2f(0.8, -0.25);
    glVertex2f(0.76, -0.25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(35, 174, 43);
    glVertex2f(0.7, -0.25);
    glVertex2f(0.85, -0.25);
    glVertex2f(0.775, -0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.7, -0.2);
    glVertex2f(0.85, -0.2);
    glVertex2f(0.775, 0.0);
    glEnd();
    glTranslatef(-1.6,0,0);

    glBegin(GL_QUADS);  //Left tree
    glColor3ub(156, 139, 102);
    glVertex2f(0.76, -0.5);
    glVertex2f(0.8, -0.5);
    glVertex2f(0.8, -0.25);
    glVertex2f(0.76, -0.25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(35, 174, 43);
    glVertex2f(0.7, -0.25);
    glVertex2f(0.85, -0.25);
    glVertex2f(0.775, -0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.7, -0.2);
    glVertex2f(0.85, -0.2);
    glVertex2f(0.775, 0.0);
    glEnd();
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(Position21,0.0f, 0.0f);



//****************************************CLOUD-1********************************
 int j;
    GLfloat x=-0.6f;
    GLfloat y=0.66f;
    GLfloat radius =0.05f;
    int triangleAmount = 20;  //Triangle used to draw circle

    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.55f;
    y=0.71f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.54f;
    y=0.65f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//****************************************CLOUD-2********************************
    x=-0.2f;
    y=0.81f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 242, 243);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.15f;
    y=0.86f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 242, 243);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.14f;
    y=0.80f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(238, 242, 243);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//****************************************CLOUD-3********************************
    x=0.3f;
    y=0.81f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.35f;
    y=0.87f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.37f;
    y=0.77f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//****************************************CLOUD-4********************************
    x=-0.3f;
    y=0.81f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.35f;
    y=0.87f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.37f;
    y=0.77f;
    radius =0.06f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//****************************************CLOUD-5********************************
 x=-0.99f;
    y=0.72f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
   glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.95f;
    y=0.77f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.95f;
    y=0.68f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=-0.92f;
    y=0.72f;
    radius =0.045f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(215, 215, 216);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

//****************************************CLOUD-6********************************
    x=0.8f;
    y=0.72f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.76f;
    y=0.77f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.76f;
    y=0.68f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.73f;
    y=0.72f;
    radius =0.045f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


//****************************************CLOUD-7********************************
    x=0.5f;
    y=0.67f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.46f;
    y=0.72f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.46f;
    y=0.63f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.43f;
    y=0.68f;
    radius =0.045f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(245, 249, 250);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


//**************************************CLOUD-8********************************
    x=0.1f;
    y=0.67f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(197, 202, 209);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.06f;
    y=0.72f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(197, 202, 209);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=0.06f;
    y=0.63f;
    radius =0.04f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(197, 202, 209);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    x=0.03f;
    y=0.68f;
    radius =0.045f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(197, 202, 209);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


//**************************************CLOUD-9********************************
    x=-0.75f;
    y=0.68f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 232, 233);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.7f;
    y=0.71f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 232, 233);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();


    x=-0.7f;
    y=0.65f;
    radius =0.05f;
    triangleAmount = 20;

    twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 232, 233);
    glVertex2f(x, y);   //CENTER OF CIRCLE
    for(j=0; j<= triangleAmount; j++)
    {
        glVertex2f(
            x + (radius * cos(j * twicePi/triangleAmount)),
            y + (radius * sin(j * twicePi/triangleAmount))
            );
    }
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(Position21, Position20, 0.0f);



//*****************************************RAIN LINE1*******************************
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glLoadIdentity();

    glPopMatrix();
    glTranslatef(0, 0.4, 0);
    glPushMatrix();
    glTranslatef(Position21, Position20, 0.0f);

// *****************************************RAIN LINE 2*******************************
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);
    glLoadIdentity();

    glPopMatrix();
    glTranslatef(0, -0.4, 0);
    glPushMatrix();
    glTranslatef(Position21, Position20, 0.0f);

//****************************************RAIN LINE 3********************************
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);
    glLoadIdentity();

    glPopMatrix();
    glTranslatef(0, -0.8, 0);
    glPushMatrix();
    glTranslatef(Position21, Position20, 0.0f);

//******************************************RAIN LINE 4******************************
    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(-0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);


    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();
    glTranslatef(0.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f(-0.4, 0.47);
    glVertex2f(-0.35, 0.28);
    glEnd();

    glLoadIdentity();
    glPopMatrix();
    glLoadIdentity();

    annex_vehicle1();
    glFlush();
}
///**************************************************ANNEX BUILDING END*********************************************************



///*****************************************************FIELD START*************************************************************
void Field_sun(){

 glColor3f(0.949, 1.0, 0);

    int z;
    GLfloat x=.8f; GLfloat y=.8f;GLfloat radius =.1f;
	 int triangleAmount = 20; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(z = 0; z <= triangleAmount;z++) {
			glVertex2f(
		            x + (radius * cos(z *  twicePi / triangleAmount)),
			    y + (radius * sin(z * twicePi / triangleAmount))
			);
		}
	glEnd();
}


GLfloat position11 = 0.0f;
GLfloat speed11 = 0.006f;//c1

GLfloat position14 = 0.0f;
GLfloat speed12 = 0.0010f;//c1

GLfloat position12 = 0.0f;
GLfloat speed13 = 0.0014f;//c2

GLfloat position13 = 0.0f;
GLfloat speed14 = 0.0018f;//c3

void fieldupdate(int value) {

    if(position11 > 0.9){
        position11 = -1.4f;
    }
    position11 += speed11;

	glutPostRedisplay();


	glutTimerFunc(100, fieldupdate, 0);

}

void fieldupdate_3(int value) {

    if(position11 > 1.3){
        position11 = -1.4f;
    }
    position11 += speed11;

	glutPostRedisplay();


	glutTimerFunc(100, arnobupdate, 0);

}


void fieldupdate_2(int value) {

    if(position12> 1.7){
        position11 = -1.4f;
    }
    position12+= speed13;

	glutPostRedisplay();


	glutTimerFunc(100, fieldupdate_2, 0);

}


	void fieldupdate1(int value) {

    if(position14 > 2.1){
        position14 = -1.4f;
    }
    position13 += speed14;

	glutPostRedisplay();


	glutTimerFunc(100, fieldupdate1, 0);
}
void field_cloud(){

glPushMatrix();
glTranslatef(position11,0.0f, 0.0f);

 glColor3f(1.0, 1.0, 1.0);

    int f;
GLfloat x=.7f; GLfloat y=.8f;GLfloat radius =.03f;
	 int triangleAmount = 20; //# of triangles used to draw circle


GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(f = 0; f <= triangleAmount;f++) {
			glVertex2f(
		            x + (radius * cos(f *  twicePi / triangleAmount)),
			    y + (radius * sin(f * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int g;
     x=.74f; y=.8f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(g = 0; g <= triangleAmount;g++) {
			glVertex2f(
		            x + (radius * cos(g *  twicePi / triangleAmount)),
			    y + (radius * sin(g * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int h;
     x=.77f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(h = 0; h <= triangleAmount;h++) {
			glVertex2f(
		            x + (radius * cos(h *  twicePi / triangleAmount)),
			    y + (radius * sin(h * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int l;
     x=.725f; y=.775f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(l = 0; l <= triangleAmount;l++) {
			glVertex2f(
		            x + (radius * cos(l *  twicePi / triangleAmount)),
			    y + (radius * sin(l * twicePi / triangleAmount))
			);
		}
	glEnd();

	///cloud 2
glColor3f(1.0, 1.0, 1.0);

    int F;
     x=0.07f; y=.80f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(F = 0; F <= triangleAmount;F++) {
			glVertex2f(
		            x + (radius * cos(F *  twicePi / triangleAmount)),
			    y + (radius * sin(F * twicePi / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);


    int G;
     x=.11f; y=.80f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(G = 0; G <= triangleAmount;G++) {
			glVertex2f(
		            x + (radius * cos(G *  twicePi / triangleAmount)),
			    y + (radius * sin(G * twicePi / triangleAmount))
			);
		}
	glEnd();

int H;
     x=.15f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(H = 0; H <= triangleAmount;H++) {
			glVertex2f(
		            x + (radius * cos(H *  twicePi / triangleAmount)),
			    y + (radius * sin(H * twicePi / triangleAmount))
			);
		}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);

    int L;
     x=.10f; y=.765f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(L = 0; L <= triangleAmount;L++) {
			glVertex2f(
		            x + (radius * cos(L *  twicePi / triangleAmount)),
			    y + (radius * sin(L * twicePi / triangleAmount))
			);
		}
	glEnd();

///cloud3

glColor3f(1.0, 1.0, 1.0);
glTranslatef(position12,0.0f, 0.0f);
    int Q;
     x=-.2f; y=.8f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(Q = 0; Q <= triangleAmount;Q++) {
			glVertex2f(
		            x + (radius * cos(Q *  twicePi / triangleAmount)),
			    y + (radius * sin(Q * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int W;
     x=-.16f; y=.8f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(W = 0; W <= triangleAmount;W++) {
			glVertex2f(
		            x + (radius * cos(W *  twicePi / triangleAmount)),
			    y + (radius * sin(W * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int E;
     x=-.13f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(E = 0; E <= triangleAmount;E++) {
			glVertex2f(
		            x + (radius * cos(E *  twicePi / triangleAmount)),
			    y + (radius * sin(E * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int R;
     x=-.175f; y=.765f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(R = 0; R <= triangleAmount;R++) {
			glVertex2f(
		            x + (radius * cos(R *  twicePi / triangleAmount)),
			    y + (radius * sin(R * twicePi / triangleAmount))
			);
		}
	glEnd();

///cloud 4
glTranslatef(position13,0.0f, 0.0f);
glColor3f(1.0, 1.0, 1.0);

    int T;
     x=-.7f; y=.8f;radius =.03f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(T = 0; T <= triangleAmount;T++) {
			glVertex2f(
		            x + (radius * cos(T *  twicePi / triangleAmount)),
			    y + (radius * sin(T * twicePi / triangleAmount))
			);
		}
	glEnd();

glColor3f(1.0, 1.0, 1.0);

    int U;
     x=-.66f; y=.8f;radius =.04f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(U = 0; U <= triangleAmount;U++) {
			glVertex2f(
		            x + (radius * cos(U *  twicePi / triangleAmount)),
			    y + (radius * sin(U * twicePi / triangleAmount))
			);
		}
	glEnd();

	int I;
     x=-.63f; y=.775f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(I = 0; I <= triangleAmount;I++) {
			glVertex2f(
		            x + (radius * cos(I *  twicePi / triangleAmount)),
			    y + (radius * sin(I * twicePi / triangleAmount))
			);
		}
	glEnd();

int O;
     x=-.675f; y=.765f;radius =.032f;
	  triangleAmount = 20; //# of triangles used to draw circle

	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(O = 0; O <= triangleAmount;O++) {
			glVertex2f(
		            x + (radius * cos(O *  twicePi / triangleAmount)),
			    y + (radius * sin(O * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();
}


void FIELD(){


    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_QUADS);
    glColor3ub(128, 223, 255);  //bright sky color
    glVertex2f(10.0,-0.8);
    glVertex2f(10.0,10.0);
    glVertex2f(-10.0,10.0);
    glVertex2f(-10.0,-0.8);
    glEnd();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(.5);

///Sky

    glBegin(GL_QUADS);
    glColor3f(0.501, 0.874, 1.0);
    glVertex2f(-1, -5);
    glVertex2f(1, -5);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();

//*********************************FIELD START*****************************************
    glBegin(GL_QUADS);    //Field
    glColor3f(0.1333,0.545,0.1333);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.5);
    glVertex2f(-1,-0.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.1333,0.545,0.1333);
    glVertex2f(-1,-0.5);
    glVertex2f(1,-0.5);
    glVertex2f(1,-0.15);
    glVertex2f(-1,-0.15);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);      //1st Road line
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.9,-0.97);
    glVertex2f(0.9,-0.97);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);      //2nd Road line
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.9,-0.19);
    glVertex2f(0.9,-0.19);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);      //2nd Road line
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.9,-.97);
    glVertex2f(-0.9,-0.188);
    glEnd();


    glLineWidth(4);
    glBegin(GL_LINES);      //2nd Road line
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.9,-.97);
    glVertex2f(-0.9,-0.188);
    glEnd();



    glLineWidth(4);
    glBegin(GL_LINES);      //2nd Road line
   glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.9,-.97);
    glVertex2f(0.9,-0.188);
    glEnd();
/*
    // Draw the penalty boxes
   glBegin(GL_QUADS);
   glColor3f(0.0f, 0.0f, 0.0f); // Black
   glVertex2f(-0.6f, -0.8f);
   glVertex2f(-0.6f, -0.4f);
   glVertex2f(-0.8f, -0.4f);
   glVertex2f(-0.8f, -0.8f);
   glEnd();
/*
   glBegin(GL_QUADS);
   glColor3f(0.0f, 0.0f, 0.0f); // Black
   glVertex2f(0.6f, -0.8f);
   glVertex2f(0.6f, -0.4f);
   glVertex2f(0.8f, -0.4f);
   glVertex2f(0.8f, -0.8f);
   glEnd();
*/
   // Draw the penalty spots
   glPointSize(6.0f);
   glBegin(GL_POINTS);
   glColor3f(1.0f, 1.0f, 1.0f); // White
   glVertex2f(-0.7f, -0.6f);
   glVertex2f(-0.7f, -0.6f);
   glEnd();


    glPointSize(6.0f);
   glBegin(GL_POINTS);
   glColor3f(1.0f, 1.0f, 1.0f); // White
   glVertex2f(0.7f, -0.6f);
   glVertex2f(0.7f, -0.6f);
   glEnd();
   // Draw the goalposts
   glBegin(GL_QUADS);
   glColor3f(1.0f, 1.0f, 1.0f); // White
   glVertex2f(-0.65f, -0.65f);
   glVertex2f(-0.65f, -0.55f);
   glVertex2f(-0.7f, -0.55f);
   glVertex2f(-0.7f, -0.65f);

    glBegin(GL_QUADS);
   glColor3f(1.0f, 1.0f, 1.0f); // White
   glVertex2f(.65f, -0.65f);
   glVertex2f(.65f, -0.55f);
   glVertex2f(0.7f, -0.55f);
   glVertex2f(0.7f, -0.65f);
   glEnd();

Field_sun();
field_cloud();
glFlush();
}
///****************************************************FIELD END******************************************************************


void full_view()
{
    display();

}

void d_view()
{
 nazmus_display();
}

void c_view()
{
 arnob_display();
}

void annex_view()
{
    annex_display1();

}

void field_view()
{

    FIELD();
}


void button(unsigned char key, int x, int y) {

    switch (key) {
        case '1':
            glutDisplayFunc(full_view);
            break;


        case '2':
            glutDisplayFunc(d_view);
            glutPostRedisplay();
            break;

        case '3':
            glutDisplayFunc(c_view);
            glutPostRedisplay();
            break;

        case '4':
            glutDisplayFunc(annex_view);
            glutPostRedisplay();
            break;

        case '5':
            glutDisplayFunc(FIELD);
            glutPostRedisplay();
            break;

        case 'a'://press a to slow  car
            carSpeed1 -= 0.012f;
            break;

        case 'd'://press d to fast car
            carSpeed1 += 0.012f;
            break;

        case 's'://press s to stop car
            carSpeed1 = 0.0f;
            break;

///
        case 'l'://press l to slow car
            carSpeed2 -= 0.012f;
            break;

        case 'j'://press j to fast car
            carSpeed2 += 0.012f;
            break;

        case 'k'://press k to stop car
            carSpeed2 = 0.0f;
            break;
///

        case 'y'://press y to slow car
            carSpeed6 -= 0.012f;
            break;

        case 'r'://press r to fast  car
            carSpeed6 += 0.012f;
            break;

        case 't'://press t to stop  car
            carSpeed6 = 0.0f;
            break;
///

         case 'm'://press m to slow car
            carSpeed -= 0.012f;
            break;

        case 'b'://press b to fast car
            carSpeed += 0.012f;
            break;

        case 'n'://press n to stop car
            carSpeed = 0.0f;
            break;
///

         case 'v'://press v to slow  car
            carSpeed -= 0.012f;
            break;

        case 'x'://press x to fast car
            carSpeed += 0.012f;
            break;

        case 'c'://press c to stop  car
            carSpeed = 0.0f;
            break;
    }

}



void init(void)
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(0.0,1000, 0.0, 650);
        glLoadIdentity();
}
    int main(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitWindowSize(1000, 650);
        glutInitWindowPosition(300, 50);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("AIUB FULL VIEW");
        glutDisplayFunc(full_view);
        glutSpecialFunc(rainCase);
        glutTimerFunc(10, update_car1, 0);
        glutTimerFunc(10, update_car2, 0);

    //D
        glutTimerFunc(100, nazmusRain, 0);
        glutTimerFunc(100, nazmusCar, 0);
        glutTimerFunc(100, update, 0);

    //C
        glutTimerFunc(100, arnobupdate, 0);
        glutTimerFunc(100, arnobupdate_3, 0);
        glutTimerFunc(100, arnobupdate_2, 0);
        glutTimerFunc(100, arnobupdate1, 0);
        glutTimerFunc(100, arnobupdateCar, 0);

    //Annex
        //glutMouseFunc(annex_rainCase);
        glutTimerFunc(100, annexRain, 0);
        glutTimerFunc(100, annexCar, 0);

    //field
        glutTimerFunc(100, fieldupdate, 0);
        glutTimerFunc(100, fieldupdate_3, 0);
        glutTimerFunc(100, fieldupdate_2, 0);
        glutTimerFunc(100, fieldupdate1, 0);

        glutKeyboardFunc(button);
        glutMainLoop();
        return 0;
}





