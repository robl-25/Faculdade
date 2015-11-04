#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define T 400

float grauX = 0.0, grauY = 0.0, grauZ = 0.0;

//float grauX = 0.0, grauY = 0.0, grauZ = 0.0, grauC = 0.0;

void desenha(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor3f(0,1,0);
    glPushMatrix();
        glutSolidTeapot(0.2);
    glPopMatrix();
    glColor3f(1, 0, 0);
    glPushMatrix();
        glRotatef(grauX,1.0,0.0,0.0);
        glRotatef(grauY,0.0,1.0,0.0);
        glRotatef(grauZ,0.0,0.0,1.0);
        glutSolidCube(0.5);
    glPopMatrix();
    glFlush();
}

void func(unsigned char key, int x, int y){
     switch ( key ) {
        case 'z':
            grauZ += (5);
            break;
        case 'y':
            grauY += (5);
            break;
        case 'x':
            grauX += (5);
            break;
        case 'Z':
            grauZ -= (5);
            break;
        case 'Y':
            grauY -= (5);
            break;
        case 'X':
            grauX -= (5);
            break;
        default:
            break;
     }
     glutPostRedisplay();
}

/*void mouse(int botao, int estado, int x, int y){
    switch(botao){
        case GLUT_LEFT_BUTTON:
            if(estado == GLUT_DOWN)
                flag=1; 
                xin=(2*x/(float)T)-1; 
                yin=(2*(T-y)/(float)T)-1;
            break;
        case GLUT_RIGHT_BUTTON:
            if(estado == GLUT_DOWN)
                //glutDisplayFunc(desenha);
            break;
       default:
        break;
    }
    glutPostRedisplay();
}*/

void main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(T, T);
    glutCreateWindow("Quadro");
    glutDisplayFunc(desenha);
    glutKeyboardFunc(func);
    //glutMouseFunc(mouse);
    glFlush();
    glutMainLoop();
}
