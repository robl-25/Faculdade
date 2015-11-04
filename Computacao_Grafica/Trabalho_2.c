#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#define T 600

int a, b, c, n;

void desenha(){
    int cons;
    int d, dNE, dN;
    int controle, x, y;
    float xp, yp, xn, yn, xsi;
    
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    //X e y iniciais
    x = round(-b/(2*a));
    y = a*x*x + b*x + c;
    
    //O deslocameno
    d = 4*(a*(x*x + x + 1/4) + b*(x + 1/2) + c - y - 1);
    dNE = 4*(a*x + 2*a + b - 1);
    dN = -4;
    cons = 8*a;
    
    xp = x/(float)T;//Para deixer entre -1 e 1
    xsi = 2*xp;//X da simetria
    
    if(a>0){
        d = 4*(a*(x*x + x + 1/4) + b*(x + 1/2) + c - y - 1);
        dN = -4;
        dNE = 4*(a*x + 2*a + b - 1);
    }
    else{
        d = 4*(a*(x*x + x + 1/4) + b*(x + 1/2) + c - y + 1);
        dN = 4;
        dNE = 4*(a*x + 2*a + b + 1);
    }
       
    glPointSize(0.5);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    while(x <= n){
    
        xp = x/(float)T; 
        yp = y /(float)T;
        xn = xsi - xp;
        yn = yp;
                
        glColor3f(1,0,0);
        glVertex2f(xp,yp);
        glVertex2f(xn,yn);
        
        if(d >= 0){
                if (a>0)
                    d += dN;
                else{
                    d += dNE;
                    dNE += cons;
                    x++;
                }
            }
            else{
                if(a > 0){
                    d += dNE;
                    dNE += cons;
                    x++;
                }
                else
                    d += dN;
            }
        y++;
    }
    glEnd();
    glFinish();
}

int main(int argc, char *argv[])
{
    printf("Para a equacao de 2 grau (a*x*x + b*x + c) digite o valor de a:");
    scanf("%d",&a);
    printf("Agora digite o valor de b: ");
    scanf("%d",&b);
    printf("Agora digite o valor da variavel c: ");
    scanf("%d",&c);
    printf("Agora digite ate onde a parabola ira variar (quanto maior o valor melhor sera avisualizacao da parabola): ");
    scanf("%d",&n);
    
    while(a == 0 || (b*b - 4*a*c) <= 0){
        printf("\nValores de a ou b ou c errados!! Lembre-se parabola precisa de 2 raizes e a diferente de zero :D\n");
        printf("Digite novamente os valores de a: ");
        scanf("%d",&a);
        printf("de b: ");
        scanf("%d",&b);
        printf("e de c: ");
        scanf("%d",&c);
    }
    if(n > T){
        n = T;
    }
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(T,T);
    glutCreateWindow("Parabola");
    glutDisplayFunc(desenha);
    glFlush();
    glutMainLoop();
    return 0;
}
