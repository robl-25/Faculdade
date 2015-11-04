#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define T 600
#define SQ sqrt(3)/6

//Controla a dimensao do floco de neve
int dimensao;

void Calcula(int d, float x1, float y1, float x5, float y5)
{
    float deltaX, deltaY, x2, y2, x3, y3, x4, y4;
    
    //desenha o fractal
    if (d == 1){
        glColor3f(0,0,0);
        glBegin(GL_LINES);
            glVertex2f(x1,y1);
            glVertex2f(x5,y5);
        glEnd();
        glutPostRedisplay();
    }
    else
    {   
        //Calcula a divisao da reta
        deltaX = -x5 + x1;
        deltaY = -y5 + y1;

        x2 = x1 - deltaX/3;
        y2 = y1 - deltaY/3;

        x3 = (x1+x5)/2 - SQ*(y1-y5);
        y3 = (y1+y5)/2 - SQ*(x5-x1);

        x4 = x1 - deltaX*2/3;
        y4 = y1 - deltaY*2/3;

        Calcula(d-1, x1, y1, x2, y2);
        Calcula(d-1, x2, y2, x3, y3);
        Calcula(d-1, x3, y3, x4, y4);
        Calcula(d-1, x4, y4, x5, y5);
    }
}

void desenha(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    
    //Calcula em cada lado do triangulo a divisao e onde desenha realmente
    Calcula(dimensao,0.0,0.0,0.4,0.0);
    Calcula(dimensao,0.4,0.0,0.2,0.3);
    Calcula(dimensao,0.2,0.3,0.0,0.0);
    
    glFlush();
}

void main(int argc, char *argv[]){

    printf("Digite qual a dimensao do fractal: ");
    scanf("%d",&dimensao);
    while(dimensao < 1 || dimensao > 9){
        printf("\nValor incorreto para a dimensao!! Digite novamente");
        printf("(o valor deve estar entre 1(para conseguir ser visto o fractal)");
        printf(" e 9 (maior que isso nao eh observado diferenca))\n");
        scanf("%d",&dimensao);
    }
    
    //Definicoes da janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(T, T);
    glutCreateWindow("Quadro");
    
    //Desenhar o fractal
    glutDisplayFunc(desenha);
    glFlush();
    glutMainLoop();
}
