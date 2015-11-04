#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

void desenho(){
    float angulo, r;
    int i;
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    r = 0.5;
    for(i=0; i<=50; i++){
        angulo = 2 * PI * i/50.0;
        glVertex2f(r*cos(angulo), r*sin(angulo));
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    r = 0.1;
    for(i=0; i<=50; i++){
        angulo = 2 * PI * i/50.0;
        glVertex2f(r*cos(angulo), r*sin(angulo));
    }
    glEnd();
    glFlush();
}

int main (int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("Desenho");
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(desenho);
    glutMainLoop();
    return 0;
}

