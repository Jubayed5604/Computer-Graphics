#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void display()
{

    glColor3f(0.10,0.7,0.20);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(150,0);
    glVertex2d(-150,0);
    glVertex2d(-150,-150);
    glVertex2d(150,-150);

    glEnd();
    glFlush();

    glColor3f(0.53,0.88,0.98);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(150,150);
    glVertex2d(-150,150);
    glVertex2d(-150,0);
    glVertex2d(150,0);

    glEnd();
    glFlush();

    glColor3f(1,1,1);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(30,0);
    glVertex2d(30,20);
    glVertex2d(50,35);
    glVertex2d(70,20);
    glVertex2d(70,-10);
    glEnd();
    glFlush();

    glColor3f(1,1,1);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(30,0);
    glVertex2d(30,20);
    glVertex2d(50,35);
    glVertex2d(70,20);
    glVertex2d(70,-10);
    glEnd();
    glFlush();

    glColor3f(1,0,0);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(50,35);
    glVertex2d(70,20);
    glVertex2d(120,20);
    glVertex2d(100,35);
    glEnd();
    glFlush();



    glColor3f(1,1,1);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(70,20);
    glVertex2d(120,20);
    glVertex2d(120,0);
    glVertex2d(70,-10);
    glEnd();
    glFlush();

    glColor3f(0,0,0);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(70,20);
    glVertex2d(70,-10);
    glVertex2d(72,-10);
    glVertex2d(72,20);
    glEnd();
    glFlush();

    glColor3f(0,0.5,0);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(45,10);
    glVertex2d(45,-4);
    glVertex2d(55,-6);
    glVertex2d(55,10);
    glEnd();
    glFlush();

    glColor3f(1,0.5,0);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(45,-4);
    glVertex2d(10, -20);
    glVertex2d(10,-30);
    glVertex2d(-150,-140);
    glVertex2d(-150,-150);
    glVertex2d(-140,-150);
    glVertex2d(20, -30);
    glVertex2d(20,-20);
    glVertex2d(55,-6);
    glEnd();
    glFlush();

    glColor3f(1,1,0);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    float r = 30;
    for(int i = 1; i <= 3600; i++)
    {
        float x = -120 + r * cos(0.1 * i), y = 100 + r * sin(0.1 * i);
        glVertex2f(x, y);

    }
    glEnd();
    glFlush();



    glColor3f(0,0.8,0);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    r = 40;
    for(int i = 1; i <= 36; i++)
    {
        float x = r * cos(10 * i), y = 70 + r * sin(10 * i);
        if((x >= 10 and y >= 30) or (x <= 10 and y >= 30))glVertex2f(x, y);

    }
    glEnd();
    glFlush();

    glColor3f(1,0.5,0.5);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    glVertex2d(-10, 0);
    glVertex2d(-10, 50);
    glVertex2d(-15, 60);
    glVertex2d(-13, 65);
    glVertex2d(0, 50);
    glVertex2d(13, 65);
    glVertex2d(15, 60);
    glVertex2d(10, 50);
    glVertex2d(10, 0);
    glEnd();
    glFlush();


    glColor3f(1,1,1);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    r = 10;
    for(int i = 1; i <= 3600; i++)
    {
        float x = -100 + r * cos(10 * i), y = 50 + r * sin(10 * i);
        glVertex2f(x, y);

    }
    for(int i = 1; i <= 3600; i++)
    {
        float x = -90 + r * cos(10 * i), y = 60 + r * sin(10 * i);
        glVertex2f(x, y);

    }
    for(int i = 1; i <= 3600; i++)
    {
        float x = -80 + r * cos(10 * i), y = 50 + r * sin(10 * i);
        glVertex2f(x, y);

    }
    glEnd();
    glFlush();

    glColor3f(1,1,1);
    glPointSize(2.0);
    glBegin(GL_POLYGON);

    r = 10;
    for(int i = 1; i <= 3600; i++)
    {
        float x = -60 + r * cos(10 * i), y = 50 + r * sin(10 * i);
        glVertex2f(x, y);

    }
    for(int i = 1; i <= 3600; i++)
    {
        float x = -50 + r * cos(10 * i), y = 60 + r * sin(10 * i);
        glVertex2f(x, y);

    }
    for(int i = 1; i <= 3600; i++)
    {
        float x = -40 + r * cos(10 * i), y = 50 + r * sin(10 * i);
        glVertex2f(x, y);

    }
    glEnd();
    glFlush();

    glColor3f(0,0.5,0);
    glPointSize(2.0);
    glBegin(GL_TRIANGLES);

    glVertex2d(-150,0);
    glVertex2d(-120,0);
    glVertex2d(-135,20);

    glVertex2d(-110,0);
    glVertex2d(-80,0);
    glVertex2d(-95,20);

    glVertex2d(-70,0);
    glVertex2d(-40,0);
    glVertex2d(-55,20);

    glEnd();
    glFlush();



}

void init()
{
    glOrtho(-150.0, 150.0, -150.0, 150.0, -150.0, 150.0);
}
int main(int a, char **b)
{

    glutInit(&a, b);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Basic Objects....");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
