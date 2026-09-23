#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void display()
{
    glColor3f(1,1,1);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    {

        float r =5;
        for(int i = 1; i <= r; i++){
            float y = sqrt(r * r - i * i);
            glVertex2f(i, y);
            glVertex2f(-i, y);
            glVertex2f(i, -y);
            glVertex2f(-i, -y);
        }

        r =7;
        for(int i = 1; i <= r; i++){
            float y = sqrt(r * r - i * i);
            glVertex2f(i, y);
            glVertex2f(-i, y);
            glVertex2f(i, -y);
            glVertex2f(-i, -y);
        }


    }
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
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Basic Objects....");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
