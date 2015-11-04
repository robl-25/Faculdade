#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define T 400

int xin, yin;
int c = 0.3, l = 0.3;
int flag = 0;

void desenha(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    if(flag == 1)
        glRectf(xin,yin, xin+c, yin+l);
    glFlush();
}

void mouse(int botao, int estado, int x, int y){
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
}

void func(unsigned char key, int x, int y){
     switch ( key ) {
        case 's':
        case 'S':
            glShadeModel(GL_SMOOTH);
        case 'f':
        case 'F':
            glShadeModel(GL_FLAT);
            break;
        default:
            break;
     }
     glutPostRedisplay();
}

void special(int key, int x, int y){
    switch(key){
        case GLUT_KEY_LEFT:
            glShadeModel(GL_SMOOTH);
            break;
        case GLUT_KEY_RIGHT:
            glShadeModel(GL_FLAT);
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(T, T);
    glutCreateWindow("P1 CG");
    glutDisplayFunc(desenha);
    //glutKeyboardFunc(func);
    //glutSpecialFunc(special);
    glutMouseFunc(mouse);
    glFlush();
    glutMainLoop();
    return 0;
}
