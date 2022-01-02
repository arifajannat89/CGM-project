#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
int width = 800;
int hight = 600;
double angle = 0 ;
void init()
{

    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, width -400, -300, hight-300);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void spin()
{
    angle = angle + 0.00001;
    if (angle >= 360)
    {
        angle = 0;
    }
    glutPostRedisplay();
}
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRotatef(angle, 0, 0, 1);
    glRecti(-50, -50, 50, 50);
    glColor3f(1, 1, 0);
    glRecti(-25, 50, 25, 300);
    glColor3f(1, 0, 0);
    glRecti(-300, -25, -50, 25);
    glColor3f(0.4, 0, 0);
    glRecti(-25, -300, 25, -50);
    glColor3f(0.4, 0.2, 0.6);
    glRecti(50, -25, 300, 25);

    glFlush();
    glutSwapBuffers();
}

int main(int agrc, char ** argv)
{

    glutInit(&agrc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);

    glutInitWindowSize(width, hight);

    glutCreateWindow("Rotating Fan");

    init();

    glutDisplayFunc(draw);
    glutIdleFunc(spin);

    glutMainLoop();
}
