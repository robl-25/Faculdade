#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int angx_I = 0, angy_I = 0, angz_I = 0, xang_I = 0, yang_I = 0, zang_I = 0;
float shoulder1_I = 45, elbow1_I = -60, shoulder2_I = -45, elbow2_I = 60;
float mao1_I = 0, mao2_I = 0;
float coxa_I = 0, baixo_I = 0, pe_I = 0, coxa2_I = 0, baixo2_I = 0, pe2_I = 0;
float xc_I = -0.15, yc_I = 0.8, zc_I = -0.18;
float x_I=0, y_I=0, z_I=0, xan_I = 0;
int sentido_I = 1, anima_I = 0, t_I = 0;

void Rotaciona_I(){
	int i;

	yang_I += ((rand()%200)/10) - 10;
	/*for(i=0; i<10; i++){
		zang_I += ((rand()%200)/10) - 10;
	}
	if(abs(zang_I) > 10){
		zang_I = 0;
	}
	/*for(i=0; i<10; i++){
		angx_I += ((rand()%200)/10) - 10;
	}*/
}

void Translada_I(){
    float ax=0,ay=0,az=0,dx=1,dy=0,dz=0;

    float radX = xang_I*M_PI/180;
    float radY = yang_I*M_PI/180;
    float radZ = zang_I*M_PI/180;

    xan_I = 0.1*sentido_I;

    ax=dx;
	//Rotacao na direcao em Z.
    dx=dx*cos(radZ)-dy*sin(radZ);
    dy=ax*sin(radZ)+dy*cos(radZ);

	az=dz;
	//Rotacao na direcao em Y.
    dz=dz*cos(radY)-dx*sin(radY);
    dx=az*sin(radY)+dx*cos(radY);

	ay=dy;
	//Rotacao na direcao em X.
    dy=dy*cos(radX)-dz*sin(radX);
    dz=ay*sin(radX)+dz*cos(radX);

    x_I+=dx*xan_I;
	z_I+=dz*xan_I;

	Rotaciona_I();
}

void Anima(int a){
        switch(t_I%3){
            case 0:
                baixo2_I = -60;
                coxa2_I = 50;
                pe2_I = 40;
                pe_I = -40;
                coxa_I = -20;
                Translada_I();
                break;
            case 1:
                baixo2_I = 0;
                coxa2_I = 0;
                pe2_I = 0;
                pe_I = 0;
                coxa_I = 0;
                break;
            case 2:
                baixo_I = -60;
                coxa_I = 50;
                pe_I = 40;
                Translada();
                pe2_I = 0.0;
                coxa2_I = -20;
		        baixo2_I = 0.0;
                break;
        }
    t_I++;
    glutPostRedisplay();
    glutTimerFunc(150,Anima,0);
}

void desenha_braco_I(float shoulder, float elbow, float mao, int opcao){
      glPushMatrix();

      //operacoes para controlar a rotacao em torno do ombro
      if(opcao == 1){
          glTranslatef(0.3,0.0,0.0);
          glRotatef(shoulder,0.0,0.0,1.0);
          glTranslatef(-0.3,0.0,0.0);
      }

      else{
          glTranslatef(-0.06,0.0,0.0);
          glRotatef(shoulder,0.0,0.0,1.0);
          glTranslatef(0.06,0.0,0.0);
      }

      glPushMatrix();
           glRotatef(90,0.0,1.0,0.0);
           glScalef (0.5, 0.5, 1.5);
           glutSolidCylinder(0.2,0.16,100,100);
      glPopMatrix();

      /* desenha e rotaciona a parte de baixo_I do braco */
      /* origem posicionada no cotovelo */
      if(opcao == 1){
        glTranslatef(-0.3,0.0,0.0);

        //Desenha o cotovelo
        glPushMatrix();
          glTranslatef(0.3,0.0,0.0);
          glutSolidSphere(0.11,100,100);
        glPopMatrix();

        glTranslatef(0.3,0.0,0.0);
        glRotatef(elbow,0.0,1.0,0.0);
        glTranslatef(-0.3,0.0,0.0);
      }

      else{
        glTranslatef(0.35,0.0,0.0);

        //Desenha o cotovelo
        glPushMatrix();
          glTranslatef(-0.05,0.0,0.0);
          glutSolidSphere(0.11,100,100);
        glPopMatrix();

        glTranslatef(-0.03,0.0,0.0);
        glRotatef(elbow,0.0,1.0,0.0);
        glTranslatef(0.03,0.0,0.0);
      }

      glPushMatrix();
           glRotatef(90,0.0,1.0,0.0);
           glScalef (0.5, 0.5, 1.5);
           glutSolidCylinder(0.2,0.16,100,100);
      glPopMatrix();

      /* desenha a mao */
      if(opcao == 1){
        glTranslatef(-0.15,0.0,0.0);

        //Desenha o pulso
        glPushMatrix();
          glTranslatef(0.15,0.0,0.0);
          glutSolidSphere(0.11,100,100);
        glPopMatrix();

        glTranslatef(0.1,0.0,0.0);
        glRotatef(mao,0.0,0.0,1.0);
        glTranslatef(-0.1,0.0,0.0);
      }

      else{
        glTranslatef(0.462,0.0,0.0);

        //Desenha o pulso
        glPushMatrix();
          glTranslatef(-0.162,0.0,0.0);
          glutSolidSphere(0.11,100,100);
        glPopMatrix();

        glTranslatef(-0.1,0.0,0.0);
        glRotatef(mao,0.0,0.0,1.0);
        glTranslatef(0.1,0.0,0.0);
      }

      glPushMatrix();
          glScalef (1.0,0.4,1.0);
          glutSolidSphere(0.2,100,100);
      glPopMatrix();

    glPopMatrix();
}

void desenha_perna_I(float coxa_I, float baixo_I, float pe_I, int opcao){
    //Coxa
    if(opcao == 1){
        glTranslatef(0.0,0.05,0.0);
        glRotatef(coxa_I,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }

    else{
        glTranslatef(0.0,0.05,0.0);
        glRotatef(coxa2_I,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }

    glPushMatrix();
       glRotatef(90,1.0,0.0,0.0);
       glScalef (0.5, 0.5, 1.5);
       glutSolidCylinder(0.2,0.16,100,100);
    glPopMatrix();

    //Parte de baixo_I da perna
    glTranslatef(0.0,-0.35,0.0);

    if(opcao == 1){
        //Desenha o joelho
        glPushMatrix();
            glTranslatef(0.0,0.05,0.0);
            glutSolidSphere(0.105,100,100);
        glPopMatrix();


        glTranslatef(0.0,0.05,0.0);
        glRotatef(baixo_I,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }
    else{
        //Desenha o joelho
        glPushMatrix();
            glTranslatef(0.0,0.05,0.0);
            glutSolidSphere(0.105,100,100);
        glPopMatrix();

        glTranslatef(0.0,0.04,0.0);
        glRotatef(baixo2_I,1.0,0.0,0.0);
        glTranslatef(0.0,-0.04,0.0);
    }

    glPushMatrix();
       glRotatef(90,1.0,0.0,0.0);
       glScalef (0.5, 0.5, 1.5);
       glutSolidCylinder(0.2,0.16,100,100);
    glPopMatrix();

    //Pe
    glTranslatef(0.0,-0.3,0.0);

    if(opcao == 1){
        //Desenha o tornozelo
        glPushMatrix();
            glTranslatef(0.0,0.05,0.0);
            glutSolidSphere(0.105,100,100);
        glPopMatrix();

        glTranslatef(0.0,0.05,0.0);
        glRotatef(pe_I,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }
    else{
        //Desenha o tornozelo
        glPushMatrix();
            glTranslatef(0.0,0.05,0.0);
            glutSolidSphere(0.105,100,100);
        glPopMatrix();

        glTranslatef(0.0,0.05,0.0);
        glRotatef(pe2_I,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }

    glPushMatrix();
        glTranslatef(0.0,0.0,-0.1);
        glScalef (0.5, 0.4, 0.8);
        glutSolidSphere(0.2,100,100);
    glPopMatrix();

}

void desenha_coxinha(float xin, float yin, int xang_I, int yang_I, int zang_I){
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	
    if(x_I>=0.6 || z_I>=0.6){
       		sentido_I = (-1);
    }
    else if(x_I<=-0.6 || z_I<=-0.6){
       		sentido_I = (1);
    }
    
  glPushMatrix();
     glTranslatef(xin,-0.05,yin);
	 glTranslatef(x_I,0,z_I);

     glScalef(0.07,0.07,0.07);
	 if(sentido_I == 1){
	 	glRotatef(-90,0.0,1.0,0.0);
	 }
	 else{
		glRotatef(90,0.0,1.0,0.0);
	 }

     glColor3f(1.0,1.0,1.0);
     //Desenha os olhos
     glPushMatrix();
         glTranslatef(-0.07,0.3,-0.13);
         glutSolidSphere(0.03,100,100);
     glPopMatrix();

     glPushMatrix();
         glTranslatef(0.07,0.3,-0.13);
         glutSolidSphere(0.03,100,100);
     glPopMatrix();

     glColor3f(0.3,0.3,0.0);
     // desenha o corpo
     glPushMatrix();
        glTranslatef(0.0,-0.2,0.0);
        glRotatef(-90,1.0,0.0,0.0);
        glutSolidCone(0.4,0.8,100,100);
     glPopMatrix();

     //Parte de baixo_I do corpo
     glPushMatrix();
        glTranslatef(0.0,-0.275,0.0);
        glutSolidSphere(0.4,100,100);
     glPopMatrix();

     glColor3f(1.0,1.0,1.0);
     //Desenha um ombro
     glPushMatrix();
        glScalef(0.8,1.0,1.0);
        glTranslatef(-0.3,0.0,0.0);
        glutSolidSphere(0.11,100,100);
     glPopMatrix();

    /* desenha um braco */
    glPushMatrix();
       //translada para acertar o braco no corpo
       glScalef(0.8,1.0,1.0);
       glTranslatef(-0.6,0.0,0.0);
       desenha_braco_I(shoulder1_I,elbow1_I,mao1_I,1);
    glPopMatrix();

    //Desenha o outro ombro
     glPushMatrix();
        glScalef(0.8,1.0,1.0);
        glTranslatef(0.3,0.0,0.0);
        glutSolidSphere(0.11,100,100);
     glPopMatrix();


    /* desenha outro braco */
     glPushMatrix();
        glScalef(0.8,1.0,1.0);
        glTranslatef(0.36,0.0,0.0);
       	desenha_braco_I(shoulder2_I,elbow2_I,mao2_I,2);
     glPopMatrix();

    //Desenha a ligacao da coxa_I com o tronco
     glPushMatrix();
        glTranslatef(-0.2,-0.58,0.0);
        glutSolidSphere(0.11,100,100);
     glPopMatrix();

    //Desenha a perna
    glPushMatrix();
        glTranslatef(-0.2,-0.63,0.0);
       	desenha_perna_I(coxa_I,baixo_I,pe_I,1);
    glPopMatrix();

    //Desenha a outra ligacao da coxa_I com o tronco
     glPushMatrix();
        glTranslatef(0.15,-0.58,0.0);
        glutSolidSphere(0.11,100,100);
     glPopMatrix();

    //Desenha a outra perna
    glPushMatrix();
        glTranslatef(0.15,-0.63,0.0);
       	desenha_perna_I(coxa2_I,baixo2_I,pe2_I,2);
    glPopMatrix();
    glPopMatrix();
}
