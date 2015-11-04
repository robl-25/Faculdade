/**
Trabalho de Computação Gráfica, 09/abril/2015
Prof. Regina
Catarina F. Proglhof, 63619, BMC

Algoritmo do Ponto Médio (Bresenham) para traçado de parábola (a!=0)

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void desenha()
{
    int a, b, c, n, xk, xm, ymax, ymin, dini, yk, dn, concavidade, B4, a8;
    n = 500;

    a = -1;
    b = 2;
    c = 1;

//    if (a == 0){
//        printf("Não é uma parbola! Pois o coeficiente de x² é igual a zero.");
//    }

    //Variaveis auxiliares para tirar multiplicações do laço
    B4 = 4*b + 4 + 8*a;
    a8 = 8*a;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,0);
    glPointSize(0.5);

    if (a<0) //Parabola para baixo
    {
        a = -a;
        b = -b;
        c = -c;
        concavidade = -1;
    }

    else{ //Parabola para cima
        concavidade = 1;
    }

    glBegin(GL_POINTS);

    xk = -n;
    xm = -b/2*a; //ponto de minimo da parabola

    //Ajustando na tela
    ymax = a*(n*n) - b*n + c;
    ymin = a*xm*xm + b*xm + c; //vamos de y no ponto de minimo

    dini = 4*a*xk + a +2*b + 4;
    dn = dini;
    yk = a*(xk*xk) + b*xk + c;
    
    float ponto_medio  = (ymax + ymin)/2;

    while (xk <=  xm && yk>=ymin){

        float x_pos = - abs(xk - xm)/(float)abs(-n-xm);
        float y_pos = 2*(yk - ponto_medio) / abs(ymax - ymin);

                /*glColor3f(1,1,1);
                glVertex2f(x_pos,0);
                glVertex2f(-x_pos,0); //Espelhando
                glVertex2f(0,concavidade*y_pos);
                glVertex2f(0,concavidade*y_pos); //Espelhando*/
                glColor3f(1,1,1);
                glVertex2f(x_pos,concavidade*y_pos);
                glVertex2f(-x_pos,concavidade*y_pos); //Espelhando

        if (dn <= 0) {
            dn = dn + 4;
        }

        else {
            dn = dn + a8*xk + B4; //dn = dn + 8*a*(xk+1) + 4*b + 4 = dn + 8*a*xk + 8*a + 8*b + 4
            xk = xk+1;
        }
        yk = yk-1; //Andando em y

    }

    glEnd();
    glFinish();
}

int main(int argc,char* argv[])
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OPEN GL");
    glutDisplayFunc(desenha);
    glutMainLoop();

    return 0;
}
