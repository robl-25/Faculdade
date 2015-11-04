#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <pthread.h>
#include <sys/signal.h>
#include <time.h>
#define T 600
#define PI 3.141592654
#define tMAX 25

float xt=0, yt=0;
int t=0, a, q=0;
float x[tMAX];
float y[tMAX];

void Rotacao(){
    float x2, y2, aux;
    int i;
    float j = 0, k = 0;

    x2 = x[0];
    y2 = y[0];

    for(i=0; i<tMAX; i++){
        aux = x[i];
        x[i] = x2 + (aux - x2)*cos(M_PI) - (y[i] - y2)*sin(M_PI);
        y[i] = y2 + (aux - x2)*sin(M_PI) + (y[i] - y2)*cos(M_PI);
    }
    xt = 0;
    yt = 0;
    if(x[14] > 0.7){
        j = x[14] - 0.7;
    }
    if(x[14] < -0.7){
        j = x[14] + 0.7;
    }
    if(j != 0){
        for(i=0; i<tMAX; i++){
            x[i] -= j;
        }
    }

    if(y[14] > 0.8){
        k = y[14] - 0.8;
    }
    if(y[14] < -0.8){
        k = y[14] + 0.8;
    }
    if(k != 0){
        for(i=0; i<tMAX; i++){
            y[i] -= k;
        }
    }

}

void Escala(){
    int i;
    float auxX, auxY;

    auxX = x[0];
    auxY = y[0];

    for(i=0; i<tMAX; i++){
        x[i] = auxX + (x[i] - auxX)*2;
        y[i] = auxY + (y[i] - auxY)*2;
    }
}

void Escala_I(){
    int i;
    float auxX, auxY;

    auxX = x[0];
    auxY = y[0];

    for(i=0; i<tMAX; i++){
        x[i] = auxX + (x[i] - auxX)*(0.5);
        y[i] = auxY + (y[i] - auxY)*(0.5);
    }
}

//Faz a asa bater
void asa(int op){
    int i, trans = 0;

    if(a != 1){
        if(x[0] < x[12]){
            float x2, y2, aux;
            float j = 0, k = 0;

            x2 = x[0];
            y2 = y[0];

            for(i=0; i<tMAX; i++){
                aux = x[i];
                x[i] = x2 + (aux - x2)*cos(M_PI) - (y[i] - y2)*sin(M_PI);
                y[i] = y2 + (aux - x2)*sin(M_PI) + (y[i] - y2)*cos(M_PI);
            }
            xt = 0;
            yt = 0;
            trans = 1;
        }
            switch(q%2){
                case 1:
                    y[5] += (-y[5] + y[4]);
                    for(i=6; i<10; i++){
                       y[i] += 0.04;
                   }

                    for(i=17; i<20; i++){
                       y[i] += 0.04;
                   }
                    break;
                case 0:
                  y[5] -= 0.02;
                    for(i=6; i<10; i++){
                        y[i] -= 0.04;
                    }
                    for(i=17; i<20; i++){
                        y[i] -= 0.04;
                    }
                    break;
            }
            q++;
        if(trans == 1){
            float x2, y2, aux;
            float j = 0, k = 0;

            x2 = x[0];
            y2 = y[0];

            for(i=0; i<tMAX; i++){
                aux = x[i];
                x[i] = x2 + (aux - x2)*cos(M_PI) - (y[i] - y2)*sin(M_PI);
                y[i] = y2 + (aux - x2)*sin(M_PI) + (y[i] - y2)*cos(M_PI);
            }
            xt = 0;
            yt = 0;
            trans = 1;
        }
        glutPostRedisplay();
        glutTimerFunc(120, asa , 0);
    }
}

void Pirueta(int b){
    float x2, y2, aux;
    int i;
    if(t < 37){
    x2 = x[0];
    y2 = y[0];
    t++;
    for(i=0; i<tMAX; i++){
        aux = x[i];
        x[i] = x2 + (aux - x2)*cos(M_PI/18) - (y[i] - y2)*sin(M_PI/18);
        y[i] = y2 + (aux - x2)*sin(M_PI/18) + (y[i] - y2)*cos(M_PI/18);
    }
    xt=0;
    yt=0;
    glutPostRedisplay();
    glutTimerFunc(90, Pirueta , 1);
    }
    else
        t = 0;
}

//Funcao que desenha o passaro
void desenha(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    int i;
    float dir;
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glColor3f(1,0,0);

    a = 1;
    //Caso o passaro chegue no final da tela (esses sao os valores do final da tela)
    if(abs(x[0] + xt) >= 0.7 || abs(y[8] + yt) >= 0.8 || abs(y[19] + yt) >= 0.8){
        Rotacao();
    }
    //Translada
    for(i=0; i<tMAX; i++){
        x[i] += xt;
        y[i] += yt;
        glVertex2f(x[i],y[i]);
    }
    a = 0;
    glEnd();
    glFlush();
}

//Funcao para a pirueta
void mouse(int botao, int estado, int x, int y){
    switch(botao){
        case GLUT_LEFT_BUTTON:
            if(estado == GLUT_DOWN)
            break;
        case GLUT_RIGHT_BUTTON:
            if(estado == GLUT_DOWN)
               Pirueta(0);
            break;
       default:
        break;
    }
    glutPostRedisplay();
}

void func(unsigned char key, int x1, int y1){
     switch ( key ) {
        case 't':
            srand ((unsigned)time(NULL));
            if(x[0] > x[12]){
                xt += ((rand()%100))/1000.;
            }
            else{
                xt -= ((rand()%100))/1000.;
            }
            yt += ((rand()%200) - 100)/1000.;
            break;
        case '-':
            Escala_I();
            break;
        case '+':
            Escala();
            break;
        case 'f':
            Rotacao();
            break;
        default:
            break;
     }
     glutPostRedisplay();
}


void* Tempo(void* v){
    asa(0);
}

int main(int argc, char *argv[])
{
    //Pontos em x do passaro:
    x[0] = 2;
    x[1] = 3;
    x[2] = 4;
    x[3] = 5;
    x[4] = 9;
    x[5] = 5;
    x[6] = 4;
    x[7] = 4;
    x[8] = 11;
    x[9] = 9;
    x[10] = 13;
    x[11] = 22;
    x[12] = 26;
    x[13] = 22;
    x[14] = 38;
    x[15] = 22;
    x[16] = 16;
    x[17] = 31;
    x[18] = 39;
    x[19] = 20;
    x[20] = 14;
    x[21] = 11;
    x[22] = 7;
    x[23] = 4.5;
    x[24] = 2;

    //Pontos em y do passaro
    y[0] = -6;
    y[1] = -5;
    y[2] = -3;
    y[3] = -2;
    y[4] = -1;
    y[5] = 1;
    y[6] = 4;
    y[7] = 5;
    y[8] = 16;
    y[9] = 11;
    y[10] = 1;
    y[11] = 8;
    y[12] = 17;
    y[13] = 6;
    y[14] = 9;
    y[15] = 2;
    y[16] = -1;
    y[17] = -5;
    y[18] = -4;
    y[19] = -8;
    y[20] = -6;
    y[21] = -6;
    y[22] = -7;
    y[23] = -6;
    y[24] = -6;

    pthread_t ta;

    int i;
    for(i=0; i<tMAX; i++){
        x[i]=(x[i]/100);
        y[i]=(y[i]/100);

    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(T, T);
    glutCreateWindow("P1 CG");
    glutDisplayFunc(desenha);

    pthread_create(&ta, NULL, Tempo, NULL);
    glutKeyboardFunc(func);
    glutMouseFunc(mouse);
    glFlush();
    glutMainLoop();
    return 0;
}
