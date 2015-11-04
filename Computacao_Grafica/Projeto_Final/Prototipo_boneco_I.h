#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float shoulder1 = 45, elbow1 = -60, shoulder2 = -45, elbow2 = 60;
float mao1 = 0, mao2 = 0;
float coxa = 0, baixo = 0, pe = 0, coxa2 = 0, baixo2 = 0, pe2 = 0;
float xc = -0.15, yc = 0.8, zc = -0.18;
float x=0, y=0, z=0, xan = 0;
int sentido = 1, anima = 0, t = 0;
float xin = 0, yin = 0;
int flag = 0;
int yangB = 0, xangB = 0, zangB = 0;

typedef struct{
    float x, z;
}Transacao_I;

void Translada(){
    float ax=0,ay=0,az=0,dx=1,dy=0,dz=0;

    float radX = xangB*M_PI/180;
    float radY = yangB*M_PI/180;
    float radZ = zangB*M_PI/180;

    xan = 0.01*sentido;

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
    
    if(anima != 0){
	    x+=dx*xan;
        //y+=dy*xan;
	    z+=dz*xan;
	}
}

void Anima_I(int a){
    if(anima != 0){
        switch(t%3){
            case 0:
                baixo2 = -60;
                coxa2 = 50;
                pe2 = 40;
                pe = -40;
                coxa = -20;
                Translada();
                break;
            case 1:
                baixo2 = 0;
                coxa2 = 0;
                pe2 = 0;
                pe = 0;
                coxa = 0;
                break;
            case 2:
                baixo = -60;
                coxa = 50;
                pe = 40;
                Translada();
                pe2 = 0.0;
                coxa2 = -20;
		        baixo2 = 0.0;
                break;
        }
        t++;
        glutPostRedisplay();
        glutTimerFunc(150,Anima_I,0);
    }
}

void desenha_braco(float shoulder, float elbow, float mao, int opcao){
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

      /* desenha e rotaciona a parte de baixo do braco */
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
          glScalef (1.0,0.4,0.4);
          glutSolidSphere(0.2,100,100);
      glPopMatrix();

    glPopMatrix();
}

void desenha_perna(float coxa, float baixo, float pe, int opcao){

    //Coxa
        //Coxa
    if(opcao == 1){
        glTranslatef(0.0,0.05,0.0);
        glRotatef(coxa,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }

    else{
        glTranslatef(0.0,0.05,0.0);
        glRotatef(coxa2,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }

    glPushMatrix();
       glRotatef(90,1.0,0.0,0.0);
       glScalef (0.5, 0.5, 1.5);
       glutSolidCylinder(0.2,0.16,100,100);
    glPopMatrix();

    //Parte de baixo da perna
    glTranslatef(0.0,-0.35,0.0);

    if(opcao == 1){
        //Desenha o joelho
        glPushMatrix();
            glTranslatef(0.0,0.05,0.0);
            glutSolidSphere(0.105,100,100);
        glPopMatrix();


        glTranslatef(0.0,0.05,0.0);
        glRotatef(baixo,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }
    else{
        //Desenha o joelho
        glPushMatrix();
            glTranslatef(0.0,0.05,0.0);
            glutSolidSphere(0.105,100,100);
        glPopMatrix();

        glTranslatef(0.0,0.04,0.0);
        glRotatef(baixo2,1.0,0.0,0.0);
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
        glRotatef(pe,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }
    else{
        //Desenha o tornozelo
        glPushMatrix();
            glTranslatef(0.0,0.05,0.0);
            glutSolidSphere(0.105,100,100);
        glPopMatrix();

        glTranslatef(0.0,0.05,0.0);
        glRotatef(pe2,1.0,0.0,0.0);
        glTranslatef(0.0,-0.05,0.0);
    }

    glPushMatrix();
        glTranslatef(0.0,0.0,-0.1);
        glScalef (0.5, 0.4, 0.8);
        glutSolidSphere(0.2,100,100);
    glPopMatrix();

}

void desenha_boneco(float xin, float yin,
                     int xang, int yang, int zang, int andar, 
                     Transacao_I trans_I[]){
  //anima = andar;
    int i;
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    yangB = yang;
    xangB = xang;
    zangB = zang;
    
    if(fabs(x+xin)>=1.9 || fabs(z+yin)>=1.8){
        anima = 0;
        baixo = 0;
        coxa = 0;
        pe = 0;
        pe2 = 0.0;
        coxa2 = 0;
		baixo2 = 0.0;
    }
    if(((x+xin)>=-0.6 && (x+xin)<=-0.4) && ((z+yin)<=-0.2 && (z+yin)>=-0.4)){
        anima = 0;
        baixo = 0;
        coxa = 0;
        pe = 0;
        pe2 = 0.0;
        coxa2 = 0;
		baixo2 = 0.0;
    }
    
    for(i=0; i<5; i++){
        if(trans_I[i].x <=0 && trans_I[i].z <=0){
            if(((x+xin)<=(trans_I[i].x + 0.2) && 
                (x+xin)>=(trans_I[i].x - 0.2)) &&
                ((z+yin)<=(trans_I[i].z + 0.2) && 
                (z+yin)>=(trans_I[i].z - 0.2))){
                anima = 0;
                baixo = 0;
                coxa = 0;
                pe = 0;
                pe2 = 0.0;
                coxa2 = 0;
		        baixo2 = 0.0;
            }
        }
        else{
            if(((x+xin)>=(trans_I[i].x + 0.2) && 
                (x+xin)<=(trans_I[i].x - 0.2)) &&
                ((z+yin)>=(trans_I[i].z + 0.2) && 
                (z+yin)<=(trans_I[i].z - 0.2))){
                anima = 0;
                baixo = 0;
                coxa = 0;
                pe = 0;
                pe2 = 0.0;
                coxa2 = 0;
		        baixo2 = 0.0;
            }
        }
    }
    
    glPushMatrix();
	    glTranslatef(xin,-0.1,yin);
	    glTranslatef(x,0,z);

	    //Rotaciona somente o personagem
	    glRotatef(xangB,1.0,0.0,0.0);
        glRotatef(yangB,0.0,1.0,0.0);
        glRotatef(zangB,0.0,0.0,1.0);

        glScalef(0.1,0.1,0.1);
	    if(sentido == 1){
	        glRotatef(-90,0.0,1.0,0.0);
	    }
	    else{
		    glRotatef(90,0.0,1.0,0.0);
	    }

        glColor3f(0.0,0.0,0.0);
         //Desenha os olhos
         glPushMatrix();
             glTranslatef(-0.07,0.36,-0.17);
             glutSolidSphere(0.03,100,100);
         glPopMatrix();

         glPushMatrix();
             glTranslatef(0.07,0.36,-0.17);
             glutSolidSphere(0.03,100,100);
         glPopMatrix();
         
         glColor3f(1.0,1.0,1.0);
	    //Desenha a cabeca
         glPushMatrix();
             glScalef(0.4,0.4,0.5);
             glTranslatef(0.0,0.8,0.0);
             glutSolidSphere(0.4,100,100);
         glPopMatrix();
         
         // desenha o corpo
         glPushMatrix();
             glScalef(0.7,0.7,0.7);
             glutSolidSphere(0.4,100,100);
         glPopMatrix();
         //Parte de baixo do corpo
         glPushMatrix();
             glTranslatef(0.0,-0.4,0.0);
             glScalef(0.7,1.0,0.7);
             glutSolidSphere(0.4,100,100);
         glPopMatrix();

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
           desenha_braco(shoulder1,elbow1,mao1,1);
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
           desenha_braco(shoulder2,elbow2,mao2,2);
         glPopMatrix();

        //Desenha a ligacao da coxa com o tronco
         glPushMatrix();
            glTranslatef(-0.15,-0.58,0.0);
            glutSolidSphere(0.11,100,100);
         glPopMatrix();

        //Desenha a perna
        glPushMatrix();
        	glTranslatef(-0.15,-0.63,0.0);
           	desenha_perna(coxa,baixo,pe,1);
        glPopMatrix();

        //Desenha a outra ligacao da coxa com o tronco
         glPushMatrix();
            glTranslatef(0.15,-0.58,0.0);
            glutSolidSphere(0.11,100,100);
         glPopMatrix();

        //Desenha a outra perna
        glPushMatrix();
            glTranslatef(0.15,-0.63,0.0);
           desenha_perna(coxa2,baixo2,pe2,2);
        glPopMatrix();
    glPopMatrix();
}
