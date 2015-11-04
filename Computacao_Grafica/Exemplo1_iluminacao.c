#include <GL/glu.h>
#include <GL/glut.h>

# define  WIRE   1
# define  SOLID  2
#define win_size_V 300
#define win_size_H 600

/* /////////////////////////////////////////////////////////////////////////////////////// */
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0) ;
    glShadeModel(GL_FLAT) ;
    glEnable(GL_LIGHT0) ;
}



/* /////////////////////////////////////////////////////////////////////////////////////// */
void Draw_Cube_Transl_Rot(int model)
{
     glColor3f(0.0,0.0,0.0) ;
     if (model == WIRE)
   	      glutWireCube(1.0) ;
      else
          glutSolidCube(1.0) ;
}

/* /////////////////////////////////////////////////////////////////////////////////////// */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ) ;
    glPushMatrix();
        glRotatef(30,1,1,0);
        glViewport(0,win_size_V / 2, win_size_H / 4 ,win_size_V / 2) ;
        glDisable(GL_LIGHTING) ;
        glDisable(GL_DEPTH_TEST) ;
        Draw_Cube_Transl_Rot(WIRE) ;

        glViewport(win_size_H / 4,win_size_V / 2, win_size_H / 4 ,win_size_V / 2) ;
        glEnable(GL_DEPTH_TEST) ;
        Draw_Cube_Transl_Rot(WIRE) ;

        glViewport(2 * (win_size_H / 4),win_size_V / 2, win_size_H / 4 ,win_size_V / 2) ;
        glEnable(GL_LIGHTING) ;
        glDisable(GL_DEPTH_TEST) ;
        Draw_Cube_Transl_Rot(WIRE) ;

        glViewport(3 * (win_size_H / 4),win_size_V / 2, win_size_H / 4 ,win_size_V / 2) ;
        glEnable(GL_DEPTH_TEST) ;
        Draw_Cube_Transl_Rot(WIRE) ;

        glViewport(0,0, win_size_H / 4 ,win_size_V / 2) ;
        glDisable(GL_LIGHTING) ;
        glDisable(GL_DEPTH) ;
        Draw_Cube_Transl_Rot(SOLID) ;

        glViewport(win_size_H / 4,0, win_size_H / 4 ,win_size_V / 2) ;
        glEnable(GL_DEPTH_TEST) ;
        Draw_Cube_Transl_Rot(SOLID) ;

        glViewport(2*(win_size_H / 4),0, win_size_H / 4 ,win_size_V / 2) ;
        glDisable(GL_DEPTH_TEST) ;
        glEnable(GL_LIGHTING) ;
        Draw_Cube_Transl_Rot(SOLID) ;

        glViewport(3*(win_size_H / 4),0, win_size_H / 4 ,win_size_V / 2) ;
        glEnable(GL_DEPTH_TEST) ;
        Draw_Cube_Transl_Rot(SOLID) ;
    glPopMatrix();
    glutSwapBuffers() ;
}

void Reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
            1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
            1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv) ;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH) ;
    glutInitWindowSize(win_size_H, win_size_V) ;
    glutInitWindowPosition(100, 100) ;
    glutCreateWindow("Iluminação") ;
    init() ;
    glutDisplayFunc(display) ;
    glutReshapeFunc(Reshape);
    glutMainLoop() ;
}

