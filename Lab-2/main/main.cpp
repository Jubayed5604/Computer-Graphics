#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);

    glBegin(GL_LINES);

    // A
    glVertex3f(0,0,0);
    glVertex3f(2,10,0);

    glVertex3f(2,10,0);
    glVertex3f(4,0,0);

    glVertex3f(1,5,0);
    glVertex3f(3,5,0);

    // Z
    glVertex3f(6,10,0);
    glVertex3f(10,10,0);

    glVertex3f(10,10,0);
    glVertex3f(6,0,0);

    glVertex3f(6,0,0);
    glVertex3f(10,0,0);

    // A
    glVertex3f(12,0,0);
    glVertex3f(14,10,0);

    glVertex3f(14,10,0);
    glVertex3f(16,0,0);

    glVertex3f(13,5,0);
    glVertex3f(15,5,0);

    // D
    glVertex3f(18,0,0);
    glVertex3f(18,10,0);

    glVertex3f(18,10,0);
    glVertex3f(22,8,0);

    glVertex3f(22,8,0);
    glVertex3f(22,2,0);

    glVertex3f(22,2,0);
    glVertex3f(18,0,0);

    // 6
    glVertex3f(26,10,0);
    glVertex3f(26,0,0);

    glVertex3f(26,10,0);
    glVertex3f(30,10,0);

    glVertex3f(26,5,0);
    glVertex3f(30,5,0);

    glVertex3f(30,5,0);
    glVertex3f(30,0,0);

    glVertex3f(30,0,0);
    glVertex3f(26,0,0);

    // 0
    glVertex3f(34,0,0);
    glVertex3f(34,10,0);

    glVertex3f(34,10,0);
    glVertex3f(38,10,0);

    glVertex3f(38,10,0);
    glVertex3f(38,0,0);

    glVertex3f(38,0,0);
    glVertex3f(34,0,0);

    glEnd();

    glFlush();
}

void init()
{
    glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
}
int main(int a, char **b)
{

    glutInit(&a, b);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Basic Objects....");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
