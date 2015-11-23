//#include <windows.h>
//#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <pthread.h>
#include "ObjLoader_Teste.h"

#define KEY_ESCAPE 27

float dx=0, dz=0, velocity=0.1;
int Ez = 0, pontoE = -1, tempo_I = 0, tempo_II = 300, tempo_III = 0, tempo_IV = 0;
int tempo_V = 0, tempo_VI = 0;
char op = 'y';
char value_I = '0';
int valor = 0, valor_I = 0, valor_II = 0;
using namespace std;

/************************************************************************
  Window
 ************************************************************************/

typedef struct {
    int width;
    int height;
    char* title;

    float field_of_view_angle;
    float z_near;
    float z_far;
} glutWindow;

/***************************************************************************
 * Program code
 ***************************************************************************/

/*Atribuir depois a g_rotation_x = -27, g_rotation_y = 153 e g_rotation_z = 177*/

Model_OBJ obj;
float g_rotation_Y = 0, g_scalef_Z = 1, g_scalef_X = 1, g_scalef_Y = 1;
float g_rotation_X = 0, g_rotation_Z = 0;
glutWindow win;

void initialize ()
{
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, win.width, win.height);
    GLfloat aspect = (GLfloat) win.width / win.height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel( GL_SMOOTH );
    glClearColor( 0.8f, 0.8f, 0.8f, 1.0f );
    glClearDepth( 1.0f );
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

    //GLfloat pos_light[] = {1,-1,1,1};
    GLfloat amb_light[] = { 0.9, 0.9, 0.9, 1.0 };
   // GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1 };
    GLfloat diffuse[] = { 1, 1, 1, 1 };
    GLfloat specular[] = { 1, 1, 1, 1 };
    GLfloat material_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat material_difusa[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat material_amb[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat pos_light[] = {6.000000, 0.000000, -10.000000,1};
  //  GLfloat pos_light[] = {1.000000, 1.000000, -1.000000,1};
    //GLfloat pos_light_spot[] = {-1.000000, 0.000000, 3.000000,1};
    GLfloat pos_light_spot[] = {-1.2, -0.2, 2.2,1};
    GLint shine = 30;

    //glLightModelfv( GL_LIGHT_MODEL_AMBIENT, amb_light );
    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
    glLightfv( GL_LIGHT0, GL_AMBIENT, amb_light);
    glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
    glLightfv( GL_LIGHT0, GL_POSITION, pos_light);
    glLightfv( GL_LIGHT0, GL_SPOT_DIRECTION, pos_light_spot);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 100.0);
    glLightf( GL_LIGHT0, GL_SPOT_EXPONENT, 10.0);

    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, material_difusa);
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, material_amb);
    glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);
    glMateriali( GL_FRONT, GL_SHININESS, shine);

    //glShadeModel( GL_SMOOTH );
    //glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
    glDepthFunc( GL_LEQUAL );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(-0,5,-18, 0,0,0, 0,1,0);
    glPushMatrix();
        /*glRotatef(-18,0,0,1);
        glRotatef(-75,1,0,0);
        glRotatef(-183,0,1,0);*/
        glTranslatef(g_scalef_X,g_scalef_Y,-g_scalef_Z);
        glPushMatrix();
            glRotatef(g_rotation_Y,0,1,0);
            glRotatef(g_rotation_X,1,0,0);
            glRotatef(g_rotation_Z,0,0,1);
            obj.Draw();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

/*** glutReshapeFunc ***/
void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  float aspectRatio = (height==0)?width:width/(float)height;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, aspectRatio, 1, 30);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-2);
}

// Atualiza value de acordo com a opcao selecionada no Menu
void ProcessMenu(int value){
    // Plano de Projecao
    GLfloat Plano[] = { 1.0f, 0.0f, 0.0f, 0.0f};
    valor_I = 0;
    valor_II = 0;
    valor = value;
    switch(value){
        case 1:
            switch(value_I){
                case 'x':
                    obj.aumentaPontox();
                    break;
                case 'X':
                    obj.diminuiPontox();
                    break;
                case 'y':
                    obj.aumentaPontoy();
                    break;
                case 'Y':
                    obj.diminuiPontoy();
                    break;
                case 'z':
                    obj.aumentaPontoz();
                    break;
                case 'Z':
                    obj.diminuiPontoz();
                    break;
			}
			break;
		case 2:
		    switch(value_I){
                case '+':
                    obj.aumentaFv();
                    break;
                case '-':
                    obj.diminuiFv();
                    break;
			}
			break;
		case 3:
		    switch(value_I){
                case '+':
                    obj.aumentaFv2();
                    break;
                case '-':
                    obj.diminuiFv2();
                    break;
			}
			break;
		case 4:
		    switch(value_I){
                case '+':
                    obj.aumentaDistancia();
                    break;
                case '-':
                    obj.diminuiDistancia();
                    break;
			}
			break;
      case 5:
  		    switch(value_I){
                  case '+':
                      obj.aumentaDistancia2();
                      break;
                  case '-':
                      obj.diminuiDistancia2();
                      break;
  			}
  			break;
      case 6:
          if(value_I != '+' && value_I != '-'){
            obj.ExcluiPonto();
          }
    			break;
		}
    value_I = '0';
    glutPostRedisplay();//Redisplay
}

void ProcessaSeleciona(int value){
  // Plano de Projecao
  GLfloat Plano[] = { 1.0f, 0.0f, 0.0f, 0.0f};
  valor_II = 0;
  valor = 0;
  valor_I = value;
  switch(value){
    case 1:
      switch(value_I){
        case 'x':
            g_scalef_X +=1;
            break;
        case 'X':
            g_scalef_X -=1;
            break;
        case 'y':
            g_scalef_Y +=1;
            break;
        case 'Y':
            g_scalef_Y -=1;
            break;
        case 'z':
            g_scalef_Z +=1;
            break;
        case 'Z':
            g_scalef_Z -=1;
            break;
        }
        break;
    case 2:
      switch(value_I){
        case 'x':
            g_rotation_X +=5;
            break;
        case 'X':
            g_rotation_X -=5;
            break;
        case 'y':
            g_rotation_Y +=5;
            break;
        case 'Y':
            g_rotation_Y -=5;
            break;
        case 'z':
            g_rotation_Z +=5;
            break;
        case 'Z':
            g_rotation_Z -=5;
            break;
        }
        break;
    break;
  }
  value_I = '0';
  glutPostRedisplay();//Redisplay
}

void Ponto(int value){
  // Plano de Projecao
  GLfloat Plano[] = { 1.0f, 0.0f, 0.0f, 0.0f};
  valor = 0;
  valor_I = 0;
  valor_II = value;
  switch(value){
    case 1:
      switch(value_I){
        case '+':
            pontoE++;
            obj.pontoEscolhido(pontoE);
            break;
        case '-':
            if(pontoE > 0){
              pontoE--;
            }
            obj.pontoEscolhido(pontoE);
            break;
        }
        break;
    case 2:
      if(value_I == '+' || value_I == '-');
      else{
        obj.NovoPonto();
        pontoE = obj.ponto;
      }
      break;
  }
  value_I = '0';
  glutPostRedisplay();//Redisplay
}

void keyboard( unsigned char key, int x, int y ){
  switch ( key ) {
    case KEY_ESCAPE:
      printf("Voce deseja salvar as alteracoes?(s/n) ");
      scanf("%c", &op);
      while(op != 'n' && op != 's'){
        scanf("%c", &op);
      }

      if(op == 's'){
        obj.Guarda_Forca();
        printf("\nAlteracoes salvas com sucesso :D\n");
      }
      obj.Release();
      exit ( 0 );
      break;
    case 'x':
    case 'X':
    case 'y':
    case 'Y':
    case 'z':
    case 'Z':
        value_I = key;
        if(valor != 0 && valor_I == 0){
          ProcessMenu(valor);
        }
        else if(valor_I != 0 && valor == 0){
            ProcessaSeleciona(valor_I);
        }
        break;
    case '+':
    case '-':
        value_I = key;
        if(valor != 0 && valor_II == 0){
          ProcessMenu(valor);
        }
        else if(valor_II != 0 && valor == 0){
          Ponto(valor_II);
        }
        break;
    case 't':
        tempo_II+= 50;
        break;
    case 'T':
        tempo_II-= 50;
        break;
    default:
        break;
  }
    glutPostRedisplay();
}

void mouse(int botao, int estado, int x, int y){
    switch(botao) {
        case GLUT_LEFT_BUTTON:
            if(estado == GLUT_UP)
                g_scalef_X += 1;
        break;

        case GLUT_RIGHT_BUTTON:
            if(estado == GLUT_UP)
                g_scalef_X -= 1;
        break;
    }
    glutPostRedisplay();
}


/*** glutSpecialFunc ***/
void special(int key, int x, int y) {
  switch(key) {
    case GLUT_KEY_UP:
      g_rotation_X+=3;
      break;
    case GLUT_KEY_DOWN:
      g_rotation_X-=3;
      break;
    case GLUT_KEY_LEFT:
        g_rotation_Y-=3;
      break;
    case GLUT_KEY_RIGHT:
        g_rotation_Y+=3;
      break;
  }
  glutPostRedisplay();
}

void Tempo_I(int i){
    switch(obj.tv%6){
        case 0:
            tempo_I = 400;
            break;
        case 1:
            tempo_I = 400;
            break;
        case 2:
            tempo_I = 400;
            break;
        case 3:
            tempo_I = 400;
            break;
        case 4:
            tempo_I = 200;
            break;
        case 5:
            if(tempo_II > 0){
                tempo_I = tempo_II;
            }
            else{
                tempo_I = 100;
            }
            break;
    }
    obj.Tempo_Contracao();
    glutPostRedisplay();
    glutTimerFunc(tempo_I, Tempo_I , 0);
}

void* Tempo(void* v){
    Tempo_I(0);
}

int main(int argc, char **argv)
{
    // set window values
    win.width = 800;
    win.height = 600;
    win.title = (char*)"Animacao Coracao";
    win.field_of_view_angle = 45;
    win.z_near = 1.0f;
    win.z_far = 500.0f;

    // initialize and run program
    // GLUT initialization
    glutInit(&argc, argv);

    // Display Mode
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );

    // set window size
    glutInitWindowSize(win.width,win.height);

    // create Window
    glutCreateWindow(win.title);

    initialize();
    obj.Load((char*)"Heart_C.obj", 0);

    pthread_t t;
    pthread_create(&t, NULL, Tempo, NULL);

    glutReshapeFunc(reshape);

    // register Display Function
    glutDisplayFunc(display);

   // register Idle Function
    glutIdleFunc( display );

    // register Keyboard Handler
    glutKeyboardFunc( keyboard );

    // register Mouse Handler
    //glutMouseFunc( mouse );

    // run GLUT mainloop
    //glutSpecialFunc(special);

    //Parametros para intentificar cada menu e os submenus
    int ponto, mainMenu, coracao;

  //Cria os Menus

  //Submenu de pontos
  ponto = glutCreateMenu(ProcessMenu);
  glutAddMenuEntry("Altera as coordenadas do ponto selecionado",1);
  glutAddMenuEntry("Altera a forca 1 do ponto selecionado",2);
  glutAddMenuEntry("Altera a forca 2 (para pontos mais perto) do ponto selecionado",3);
  glutAddMenuEntry("Altera a distancia 1 do ponto selecionado",4);
  glutAddMenuEntry("Altera a distancia 2 (para pontos mais perto) do ponto selecionado",5);
  glutAddMenuEntry("Remove o ponto selecionado",6);

  //Submenu do coracao
  coracao = glutCreateMenu(ProcessaSeleciona);
  glutAddMenuEntry("Transladar o coracao",1);
  glutAddMenuEntry("Rotacionar o coracao",2);

  //Menu principal
  mainMenu = glutCreateMenu(Ponto);
  glutAddMenuEntry("Seleciona um ponto",1);
  glutAddMenuEntry("Adiciona um novo ponto",2);
  glutAddSubMenu("Alteracoes do ponto selecionado",ponto);
  glutAddSubMenu("Alteracoes do coracao",coracao);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
