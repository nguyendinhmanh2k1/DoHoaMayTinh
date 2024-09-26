#include<Windows.h>
#include<iostream>
#include<GL/GL.h>
#include<GL/GLU.h>
#include<GL/glut.h>
#include<math.h>

void cylinder(float alas, float atas, float tinggi);
void kerucut(float ngisor, float nduwur, float dowo);
void blok(float tebal, int ratiol, int ratiop);

GLfloat source_light[] = { 0.30, 0.30, 0.30, 0.50 };
double Loop, LoopAll = 0;
bool on = false;

void Mobil()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 1.5, 10.0, 1000.0);

	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, source_light);
	glEnable(GL_LIGHT7);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
}
void keboad_s(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		if (on == false)
		{
			on = true;
		}
		else
		{
			on = false;
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, -100);
	Loop = +Loop + 0.1;
	glRotatef(Loop, 1, 0, 0);

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	blok(10, 7, 3);

	glTranslatef(0, 9, 0);
	blok(10, 3, 3);


	glPopMatrix();

	glPushMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(20, -8, -7);
	cylinder(5, 5, 3);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-20, 8, 7);
	glTranslatef(-5, -8, -7);
	cylinder(5, 5, 3);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(5, 8, 7);
	glRotatef(180, 0, 180, 0);
	glTranslatef(3, -8, -27);
	cylinder(5, 5, 3);

	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-3, 8, 17);
	glTranslatef(-22, -8, -17);
	cylinder(5, 5, 3);



	glColor3f(1.0, 1.0, 1.0);

	glRotatef(90, 1, 0, 0);
	glTranslatef(8, 2, -15);
	blok(2, 3, 2);


	glRotatef(90, 0, 1, 0);
	glTranslatef(0, -0.2, 7);
	blok(2, 4, 8);

	// thùng xe
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(0, 1, 0, 0);
	glTranslatef(0, 1.2, 23);
	blok(2, 3, 10);

	glColor3f(0.0, 1.0, 0.0);
	glRotatef(0, 1, 0, 0);
	glTranslatef(0, 28, -1);
	blok(2, 3, 10);

	glColor3f(0.0, 0.0, 1.0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 19, 0);
	blok(2, 3, 15);
	// thùng xe

	//gương
	glRotatef(0, 1, 0, 0);
	glTranslatef(0, -48, -5.5);
	blok(2, 3, 5);

	glRotatef(0, 1, 0, 0);
	glTranslatef(0, 0, 35);
	blok(2, 3, 2);
	//gương
	//kính
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -31, -23);
	blok(2, 4, 8);

	glRotatef(0, 1, 0, 0);
	glTranslatef(0, 0, 21);
	blok(2, 3, 3);

	// tấm để đèn
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-7.5, 23, -23.999);
	blok(2.19, 3, 9.9);

	//kính to đầu xe
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(0, 1, 0, 0);
	glTranslatef(10.2, -20, -1);
	blok(2, 3, 11);
	//kính
	// đèn
	glColor3f(9.9, 9.9, 0.0);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-10, -3, -20);
	cylinder(2, 2, 3);

	glColor3f(9.9, 9.9, 0.0);
	glRotatef(0, 0, 0, 0);
	glTranslatef(0, 25, 0);
	cylinder(2, 2, 3);
	// đèn

	glPopMatrix();

	glFlush();
	glutSwapBuffers();


}

void Kerucut(float ngisor, float nduwur, float dowo)
{
	float i;
	glPushMatrix();
	glTranslatef(1.0, 0.0, ngisor / 24);
	glutSolidCone(ngisor, 0, 32, 4);
	for (i = 0; i <= dowo; i += ngisor / 24)
	{
		glTranslatef(0.0, 0.0, ngisor / 24);
		glutSolidTorus(ngisor / 4, ngisor - ((i * (ngisor - nduwur)) / dowo), 16, 16);
	}
	glTranslatef(0.0, 0.0, ngisor / 4);
	glutSolidCone(nduwur, 0, 20, 1);
	glColor3f(0., 1., 1.);
	glPopMatrix();
}

void cylinder(float alas, float atas, float tinggi)
{
	float i;
	glPushMatrix();
	glTranslatef(1.0, 0.0, -alas / 8);
	glutSolidCone(alas, 0, 32, 4);
	for (i = 0; i <= tinggi; i += alas / 24)
	{
		glTranslatef(0.0, 0.0, alas / 24);
		glutSolidTorus(alas / 4, alas - ((i * (alas - atas)) / tinggi), 16, 16);
	}
	glTranslatef(0.0, 0.0, alas / 4);
	glutSolidCone(atas, 0, 20, 1);
	glColor3f(1., 0., 0.);
	glPopMatrix();
}

void blok(float tebal, int ratiol, int ratiop)
{
	float i, j;
	glPushMatrix();
	for (i = 0; i < ratiop; i++)
	{
		glTranslatef(-(ratiol + 1) * tebal / 2, 0.0, 0.0);
		for (j = 0; j < ratiol; j++)
		{
			glTranslatef(tebal, 0.0, 0.0);
			glutSolidCube(tebal);
		}
		glTranslatef(-(ratiol - 1) * tebal / 2, 0.0, tebal);
	}
	glPopMatrix();
}
void tampil()
{
	display();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1000, 700);
	glutCreateWindow("");
	glClearColor(0.5, 0.5, 0.0, 0.0);
	glutDisplayFunc(display);
	gluOrtho2D(-320., 320., -240.0, 240.0);
	glutIdleFunc(tampil);
	glutSpecialFunc(keboad_s);
	Mobil();
	glutMainLoop();
	return(0);
}