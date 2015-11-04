#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define T 800

float grauX = 0.0, grauY = 0.0, grauZ = 0.0;
float grauXT = 0.0, grauYT = 0.0, grauZT = 0.0;
float xc = 0, yc = 0, zc = 0;
float xa = -1.11, ya = 0.31, za = 0.18;
float xan = 0.0;
float x = 0, y = 0, z = 0;
int andar = 1, sentido = 1;
int rotaX = 0, rotaY = 0, rotaZ = 0;


void Rotaciona(int a){
    if(andar == 1){
        grauZT += 1;
        glutPostRedisplay();
        glutTimerFunc(90,Rotaciona,0);
    }
}

void Translada(int a){
    if(andar == 1){
        float ax=0,ay=0,az=0,dx=1,dy=0,dz=0;
        
        float radX = grauX*M_PI/180;
        float radY = grauY*M_PI/180;
        float radZ = grauZ*M_PI/180;
        
        xan = 0.01*sentido;
        
        ax=dx;
	    //Rotação da direção em Z.
        dx=dx*cos(radZ)-dy*sin(radZ);
        dy=ax*sin(radZ)+dy*cos(radZ);

	    az=dz;
	    //Rotação da direção em Y.
        dz=dz*cos(radY)-dx*sin(radY);
        dx=az*sin(radY)+dx*cos(radY);

	    ay=dy;
	    //Rotação da direção em X.
        dy=dy*cos(radX)-dz*sin(radX);
        dz=ay*sin(radX)+dz*cos(radX);

	    if(andar==1){
		    x+=dx*xan;
            y+=dy*xan;
	       	z+=dz*xan;
	    }
	    glutPostRedisplay();
        glutTimerFunc(90,Translada,0);
	}
}

void desenha(){
    
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Translada para andar
    glTranslated(x,y,z);
    
    //Rotacao do carro como um todo
    glRotatef(grauX,1.0,0.0,0.0);
    glRotatef(grauY,0.0,1.0,0.0);
    glRotatef(grauZ,0.0,0.0,1.0);
    
    glScalef(0.5,0.5,0.5);
    
    glColor3f(0.8,0,0.5);
    //Parte de cima
    glPushMatrix();
        glTranslatef(0.0,0.1,0.0);
        glTranslatef(-0.01,0.0,0.0);
        glutSolidCube(0.2);
    glPopMatrix();
    //Parte de baixo
    glPushMatrix();
        glScalef(2.37,-0.5,-1.2);
        glutSolidCube(0.2);
    glPopMatrix();
    
    glColor3f(0,0,0);
    //Janelas laterais da frente
    glPushMatrix();
        glScalef(0.4,0.31,0.18);
        glTranslatef(0.06,0.42,-0.46);
        glutSolidCube(0.2);
    glPopMatrix();

    glPushMatrix();
        glScalef(0.4,0.31,0.18);
        glTranslatef(0.06,0.42,0.46);
        glutSolidCube(0.2);
    glPopMatrix();
    
    //Janelas laterais de tras
    glPushMatrix();
        glScalef(0.3,0.31,0.18);
        glTranslatef(-0.2,0.42,-0.46);
        glutSolidCube(0.2);
    glPopMatrix();
    
    glPushMatrix();
        glScalef(0.3,0.31,0.18);
        glTranslatef(-0.2,0.42,0.46);
        glutSolidCube(0.2);
    glPopMatrix();
    
    //Janela da frente/tras
    glPushMatrix();
        glScalef(-1.06,0.3,0.73);
        glTranslatef(0.01,0.42,0.0);
        glutSolidCube(0.2);
    glPopMatrix();
    
    glColor3f(1,1,0);
    //Farol direito
    glPushMatrix();
            glTranslatef(0.23,0.0,0.0);
            glTranslatef(0.0,-0.01,0.0);
            glTranslatef(0.0,0.0,-0.09);
		    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    //Farol esquerdo
    glPushMatrix();
            glTranslatef(0.23,0.0,0.0);
            glTranslatef(0.0,-0.01,0.0);
            glTranslatef(0.0,0.0,0.09);
		    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    
    glColor3f(1,0,0);
    //Farol de tras direito
    glPushMatrix();
            glTranslatef(-0.23,0.0,0.0);
            glTranslatef(0.0,-0.01,0.0);
            glTranslatef(0.0,0.0,-0.09);
		    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    //Farol de tras esquerdo
    glPushMatrix();
            glTranslatef(-0.23,0.0,0.0);
            glTranslatef(0.0,-0.01,0.0);
            glTranslatef(0.0,0.0,0.09);
		    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    
    glColor3f(0,0,0);
    //Roda de tras direita
    glPushMatrix();
            glTranslatef(-0.14,0.0,0.0);
            glTranslatef(0.0,-0.06,0.0);
            glTranslatef(0.0,0.0,-0.11);
            glRotatef(grauZT,0.0,0.0,1.0);
		    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    //Roda da frente 
    glPushMatrix();
            glTranslatef(0.12,0.0,0.0);
            glTranslatef(0.0,-0.06,0.0);
            glTranslatef(0.0,0.0,-0.11);
            glRotatef(grauZT,0.0,0.0,1.0);
		    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    //Roda da frente 
    glPushMatrix();
            glTranslatef(0.12,0.0,0.0);
            glTranslatef(0.0,-0.06,0.0);
            glTranslatef(0.0,0.0,0.11);
            glRotatef(grauZT,0.0,0.0,1.0);
		    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    //Roda de tras esquerda
    glPushMatrix();
            glTranslatef(-0.14,0.0,0.0);
            glTranslatef(0.0,-0.06,0.0);
            glTranslatef(0.0,0.0,0.11);
            glRotatef(grauZT,0.0,0.0,1.0);
		    glutSolidSphere(0.03,10,10);
    glPopMatrix();
    
    if(fabs(x)>=1-0.15 || fabs(y)>=1-0.15 || z>=1-0.05 || -z>=1-0.25){
        andar=0;
    }
      
    glutSwapBuffers();
}

void func(unsigned char key, int x, int y){
     switch ( key ) {
        case 'y':
            grauY += (1);
            break;
        case 'x':
            grauX += (1);
            break;
        case 'Y':
            grauY -= (1);
            break;
        case 'X':
            grauX -= (1);
            break;
        case 'r':
            sentido = 1;
            andar = 1;
            Translada(0);
            Rotaciona(0);
            break;
        case 'R':
            andar = 0;
            break;
        case 'p':
            sentido = -1;
            andar = 1;
            Translada(0);
            Rotaciona(0);
            break;
        case 27:
            exit(0);
        default:
            break;
     }
     glutPostRedisplay();
}

void special(int key, int x, int y){
    switch(key){
        case GLUT_KEY_LEFT:
            grauZ += (1);
            break;
        case GLUT_KEY_RIGHT:
            grauZ -= (1);
            break;
        case GLUT_KEY_UP:
            grauY += (1);
            break;
        case GLUT_KEY_DOWN:
            grauY -= (1);
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
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(T, T);
    glutCreateWindow("Quadro");
    glutDisplayFunc(desenha);
    glutKeyboardFunc(func);
    glutSpecialFunc(special);
    //glutMouseFunc(mouse);
    glFlush();
    glutMainLoop();
}
