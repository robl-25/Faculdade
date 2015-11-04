#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Prototipo_boneco_I.h"
#include "Prototipo_coxinha_I.h"
#include "cenario_I.h"
#include "Final_Jogo.h"
#include "Game_Over.h"
#define T 700

int flagm = 0;
int angxm = 0, angym = 0, angzm = 0, xangm = 0, yangm = 0, zangm = 0;
int animam = 0;
float xinm = 0, yinm = 0, esc = 12.5;
GLfloat angle, fAspect;
float d = 100;
int final = 0, c = 1, cont = 100;
float xgo=0, ygo=0, zgo=0;

// Inicializa parametros de rendering
void Inicializa (void){
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    angle=45;
    GLfloat luzAmbiente[4]={0,0,0,1.0};
    GLfloat mat_specular[] = { 0, 0, 0, 1.0 };
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_position[] = { 0, 2.0, 0, 0.0 };

    GLfloat light1_ambient[] = { 0, 0, 0, 1.0 };
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_position[] = { 0, 2.0, 0, 1.0 };
    GLfloat spot_direction[] = { -1.0, -1.0, -1.0 };

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 80.0);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
}

// Função usada para especificar o volume de visualizacao
void EspecificaParametrosVisualizacao(void){
	// Especifica sistema de coordenadas de projecao
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projecao
	glLoadIdentity();

	// Especifica a projecao perspectiva
    gluPerspective(angle,fAspect,0.5,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
    gluLookAt(0,1,2,(x),0,(z),0,1,0);
}

// Função callback chamada quando o tamanho da janela eh alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	// Para previnir uma divisao por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

	// Calcula a correcao de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

void Contador(int a){
    if(final != 1){
        cont --;
        glutPostRedisplay();
        glutTimerFunc(800,Contador,0);
    }
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	
	if(final == 1){
	    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
        gluPerspective(angle,fAspect,0.5,500);
	    glMatrixMode(GL_MODELVIEW);
	    glLoadIdentity();
        gluLookAt(0,1,2,0,0,0,0,1,0);
	    Desenha_Final();
	}
	
	else if(cont >= 1){
	    if(c == 1){
	        EspecificaParametrosVisualizacao();
	    }
	    else{
	        glMatrixMode(GL_PROJECTION);
	        glLoadIdentity();
	        glOrtho(-1.0, 1.0, -1.0, 1.0, 0.5,500);
	        glMatrixMode(GL_MODELVIEW);
	        glLoadIdentity();
	        gluLookAt(0,1,2,(x),0,(z),0,1,0);
	    }
	    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	    char buf2[300];
        sprintf(buf2, "%d segs",cont);
        const char * p2 = buf2 ;
        char pri = cont;
	    glRasterPos3f(0.6,0.8,0);
        do glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *p2 ); while( *(++p2) );
        
	    glPushMatrix();
          	glRotatef(angxm,1.0,0.0,0.0);
          	glRotatef(angym,0.0,1.0,0.0);
          	glRotatef(angzm,0.0,0.0,1.0);
          	
          	glPushMatrix();
	            desenha_cena(esc);
	        glPopMatrix();
          	
          	glPushMatrix();
          	    glTranslatef(0,-0.1,0);
              	if(flagm == 1){
              	   desenha_coxinha(xinm+0.3,yinm-0.4,
              	                        xangm,yangm,zangm);
              	    glPopMatrix();

              	    glPushMatrix();
	                    desenha_boneco(xinm,-yinm,
	                                    xangm,yangm,zangm,animam,trans);
	                glPopMatrix();
	            }
	        glPopMatrix();

	    glPopMatrix();
    
        d = sqrt(pow((x_I+xinm+0.3) - (x+xinm),2) + pow((z_I+yinm-0.4)-(z-yinm),2));
        
	    if(d <= 0.2 && d != 0){
	        final = 1;
	    }
	}
	else{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
        gluPerspective(angle,fAspect,0.5,500);
	    glMatrixMode(GL_MODELVIEW);
	    glLoadIdentity();
        gluLookAt(0,1,2,0,0,0,0,1,0);
	    Desenha_Game_Over();
	}
	
	// Executa os comandos OpenGL
	glutSwapBuffers();
 }

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int botao, int estado, int xm, int ym){
    switch(botao){
        case GLUT_LEFT_BUTTON:
            if(estado == GLUT_DOWN)
				if(flagm == 0){
                	flagm=1;
                	xinm=(2*xm/(float)T)-1;
                	yinm=(2*(T-ym)/(float)T)-1;
			Anima(0);
			Contador(0);
				}
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

void keyboard (unsigned char key, int x, int y){
  switch (key) {
        //Controla as rotacoes da cena
        case 'x':
		    angxm+=5;
		    break;
		case 'X':
		    angxm-=5;
		    break;
		case 'y':
		    angym+=5;
		    break;
		case 'Y':
		    angym-=5;
		    break;
		case 'z':
		    angzm+=5;
		    break;
		case 'Z':
		    angzm-=5;
            break;
        case 'a':
		    xgo+=0.1;
		    break;
		case 'A':
		    xgo-=0.1;
		    break;
		case 'q':
		    ygo+=0.1;
		    break;
		case 'Q':
		    ygo-=0.1;
		    break;
		case 'w':
		    zgo+=0.1;
		    break;
		case 'W':
		    zgo-=0.1;
            break;
        /* sai do programa */
        case 27:
            exit(0);
            break;
  }
  glutPostRedisplay();
}

void special(int key, int x, int y){
    switch(key){
        case GLUT_KEY_LEFT:
            yangm += 10;
			break;
		case GLUT_KEY_RIGHT:
			yangm -= 10;
			break;
		case GLUT_KEY_UP:
		    sentido = 1;
		    if(anima != 1){
			    anima = 1;
                Anima_I(0);
            }
			break;
		case GLUT_KEY_DOWN:
			sentido = -1;
			if(anima != 1){
			    anima = 1;
                Anima_I(0);
            }
			break;
    }
}

// Atualiza value de acordo com a opcao selecionada no Menu
void ProcessMenu(int value){
    // Plano de Projecao
    GLfloat Plano[] = { 1.0f, 0.0f, 0.0f, 0.0f };

    switch(value){
        case 1:
            // Projecao ortogonal
            glMatrixMode(GL_PROJECTION);
	        glLoadIdentity();
	        glOrtho(-1.0, 1.0, -1.0, 1.0, 0.5,500);
	        glMatrixMode(GL_MODELVIEW);
	        glLoadIdentity();
	        gluLookAt(0,1,2,0,0,0,0,1,0);
	        c = 0;
            break;

		case 2:
            // Projecao perspectiva
            EspecificaParametrosVisualizacao();
            c = 1;
			break;
		}

    glutPostRedisplay();    // Redisplay
}

// Programa Principal
int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(T,T);
	glutCreateWindow("Pegue a coxinha");
	
	//Inicializa textura
	init();
	initTexture();
	init_I();
	initTexture_I();
	
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	
	//Inicializa iluminacao
	Inicializa();
	
	
	//Cria o Menu
	glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("Projecao Ortogonal",1);
	glutAddMenuEntry("Projecao Perspectiva",2);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	
	glutMainLoop();
}
