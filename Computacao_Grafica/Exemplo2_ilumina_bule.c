/* Iluminacao.c
 Iluminação de um bule
*/

#include <stdio.h>
#include <GL/glut.h>

GLfloat angle=45;
GLfloat fAspect;
GLint eixox=0, eixoy=0, eixoz=0;


/* Chamada para fazer o desenho*/
void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.5f, 0.5f, 0.5f);

    glShadeModel(GL_SMOOTH);
	/* Desenha o teapot com a cor corrente (solid) */
	glColor3f(1.0,0.0,0.8);
	glPushMatrix();
	  glRotatef(eixox, 1 ,0 ,0);
          glRotatef(eixoy, 0 ,1 ,0);
          glRotatef(eixoz, 0 ,0 ,1);
  	  glutSolidTeapot(50.0f);
	glPopMatrix();

	glutSwapBuffers();
}


/* Inicialização */
void SetupRC(void) {
    GLfloat luzAmbiente[4]={0.5,0.5,0.5,1.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

    GLfloat objeto_ambiente[4] = {1.0,1.0,1.0,1.0};
    GLfloat objeto_difusa[4] = {1.0,0.0,0.0,1.0};

	/* Capacidade de brilho do material */
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 30;


/* Especifica que a cor de fundo da janela será preta */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

/* Ativa o uso da luz ambiente */
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

/* Define os parâmetros da luz de número 0 */
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );


/* define as propriedades do material */
    glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, objeto_ambiente);
    glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, objeto_difusa);
/* Define a refletância do material */
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
/* Define a concentração do brilho */
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

/* Habilita a definição da cor do material a partir da cor corrente */
    glEnable(GL_COLOR_MATERIAL);
/* Habilita o uso de iluminação*/
    glEnable(GL_LIGHTING);
/* Habilita a luz de número 0 */
    glEnable(GL_LIGHT0);
/* Habilita o depth-buffering */
    glEnable(GL_DEPTH_TEST);
/*glShadeModel(GL_FLAT);*/

}


/* Função usada para especificar o volume de visualização */
void Viewing(void)	{
	/* Especifica sistema de coordenadas de projeção */
	glMatrixMode(GL_PROJECTION);
	/* Inicializa sistema de coordenadas de projeção */
	glLoadIdentity();

	/* Especifica a projeção perspectiva */
	gluPerspective(angle,fAspect,0.1,500);

	/* Especifica sistema de coordenadas do modelo */
	glMatrixMode(GL_MODELVIEW);
	/* Inicializa sistema de coordenadas de projeção */
	glLoadIdentity();

	/* Especifica posição do observador e do alvo */
	gluLookAt(0,80,200, 0,0,0, 0,1,0);
}


/* Chamada pela GLUT quando a janela é redimensionada */
void ChangeSize(GLsizei w, GLsizei h)	{
	/* Para previnir uma divisão por zero */
	if ( h == 0 )
		h = 1;

	/* Especifica o tamanho da viewport */
	glViewport(0, 0, w, h);

	/* Calcula a correção de aspecto */
	fAspect = (GLfloat)w/(GLfloat)h;

	Viewing();
}


/* Callback para gerenciar eventos do mouse */
void HandleMouse(int button, int state, int x, int y)	{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
			if (angle <= 130)
				angle += 5;
		}
	Viewing();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 'x':
    eixox = (eixox + 5) % 360;
    glutPostRedisplay();
    break;
  case 'y':
    eixoy = (eixoy + 5) % 360;
    glutPostRedisplay();
    break;
  case 'z':
    eixoz = (eixoz + 5) % 360;
    glutPostRedisplay();
    break;
  case 'X':
    eixox = (eixox - 5) % 360;
    glutPostRedisplay();
    break;
  case 'Y':
    eixoy = (eixoy - 5) % 360;
    glutPostRedisplay();
    break;
  case 'Z':
    eixoz = (eixoz - 5) % 360;
    glutPostRedisplay();
    break;
  }
}

/* Programa Principal */
int main(int argc, char **argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,350);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutMouseFunc(HandleMouse);
        glutKeyboardFunc(keyboard);
	SetupRC();
	glutMainLoop();
}
