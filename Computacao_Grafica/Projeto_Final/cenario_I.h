#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 10

float xt = 0, yt = 0, zt = 0, ze = 1.0;

typedef struct{
    float x, z;
}Transacao;

Transacao trans[N];

typedef struct BMPImagem
{
    int   width;
    int   height;
    char *data;
}BMPImage;


GLuint texture_id[2]; /* identificador da textura */

//-----------------------------------------------------------------------------
// Name: getBitmapImageData()
// Desc: Simply image loader for 24 bit BMP files.
//-----------------------------------------------------------------------------
void getBitmapImageData( char *pFileName, BMPImage *pImage )
{
    FILE *pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
	int i;

    if( (pFile = fopen(pFileName, "rb") ) == NULL )
		printf("ERROR: getBitmapImageData - %s not found.\n", pFileName);

    // Seek forward to width and height info
    fseek( pFile, 18, SEEK_CUR );

    if( (i = fread(&pImage->width, 4, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read width from %s.\n ", pFileName);

    if( (i = fread(&pImage->height, 4, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read height from %s.\n ", pFileName);

    if( (fread(&nNumPlanes, 2, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read plane count from %s.\n", pFileName);

    if( nNumPlanes != 1 )
		printf("ERROR: getBitmapImageData - Plane count from %s.\n ", pFileName);

    if( (i = fread(&nNumBPP, 2, 1, pFile)) != 1 )
		printf( "ERROR: getBitmapImageData - Couldn't read BPP from %s.\n ", pFileName);

    if( nNumBPP != 24 )
		printf("ERROR: getBitmapImageData - BPP from %s.\n ", pFileName);

    // Seek forward to image data
    fseek( pFile, 24, SEEK_CUR );

	// Calculate the image's total size in bytes. Note how we multiply the
	// result of (width * height) by 3. This is becuase a 24 bit color BMP
	// file will give you 3 bytes per pixel.
    int nTotalImagesize = (pImage->width * pImage->height) * 3;

    pImage->data = (char*) malloc( nTotalImagesize );

    if( (i = fread(pImage->data, nTotalImagesize, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read image data from %s.\n ", pFileName);

    //
	// Finally, rearrange BGR to RGB
	//

	char charTemp;
    for( i = 0; i < nTotalImagesize; i += 3 )
	{
		charTemp = pImage->data[i];
		pImage->data[i] = pImage->data[i+2];
		pImage->data[i+2] = charTemp;
    }
}


/*Função para Carregar uma imagem .BMP */
void CarregaTextura(char* Filename, int i)
{

    BMPImage textura;

    getBitmapImageData( Filename, &textura);

	/* Define que tipo de textura será usada
	 GL_TEXTURE_2D ==> define que será usada uma textura 2D (bitmaps)
	 texture_id  ==> define o número da textura  */
   glBindTexture ( GL_TEXTURE_2D, texture_id[i]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
   glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

    // Give the image to OpenGL
    // Define uma textura bidimensional
    glTexImage2D(GL_TEXTURE_2D, 0, 3, textura.width, textura.height, 0, GL_RGB, GL_UNSIGNED_BYTE, textura.data);

}

void initTexture(void)
{

	/* Habilita o uso de textura bidimensional  */
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);


	/*Carrega os arquivos de textura */
    CarregaTextura("tunnelTexture.bmp",0);
    CarregaTextura("wood.bmp",1);

}

void init(){
    /* Define quantas texturas serao usadas no programa  */
    glGenTextures(2, texture_id);
    srand(time(NULL));
    int i,j;
    float d;
    for(i=0; i<N; i++){
       d = ((rand()%100)/100.);
       if(d >= 0.3){
           trans[i].x = (-i/10.)-((rand()%100)/100.) + 0.25*d;
           trans[i].z = (i/10.)-((rand()%100)/100.) - 0.23;
       }
       else if(d >= 0.5){
           trans[i].x = (i/10.)-((rand()%100)/100.) - 0.1;
           trans[i].z = (-i/10.)+((rand()%100)/100.) - 0.2;
       }
       else{
           trans[i].x = (-i/10.)+((rand()%100)/100.) - 0.2*d;
           trans[i].z = (-i/10.)-((rand()%100)/100.) + 0.3;
       }
       if(fabs(trans[i].x)>=1.9 || fabs(trans[i].z)>=1.8){
            i--;
       }
    }
}

void desenhaArvores(){
    glTranslatef(0.0,0.5,0.0);
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture_id[1]);
        glColor3f(1.0,1.0,1.0);
	    glTranslatef(0,-0.7,-0.2);
	    glScalef(0.4,1.0,0.4);
	    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
	    glTranslatef(0,-0.65,-0.2);
	    glRotatef(-90,1.0,0.0,0.0);
	    glutSolidCone(0.1,0.2,100,100);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
	    glTranslatef(0,-0.55,-0.2);
	    glRotatef(-90,1.0,0.0,0.0);
	    glutSolidCone(0.07,0.15,100,100);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
	    glTranslatef(0,-0.475,-0.2);
	    glRotatef(-90,1.0,0.0,0.0);
	    glutSolidCone(0.05,0.1,100,100);
    glPopMatrix();
}

void desenha_cena(float zc){
    int i;
    int z;
    glEnable(GL_TEXTURE_2D);
	        glEnable(GL_TEXTURE_GEN_S);
	        glEnable(GL_TEXTURE_GEN_T);
  	glPushMatrix();

        glPushMatrix();
            glBindTexture ( GL_TEXTURE_2D, texture_id[0]);
	        glColor3f(0.8,0.8,0.8);
            glTranslatef(0,-0.3,0);
	        glScalef(20,0.5,20);
	        glutSolidCube(0.2);
        glPopMatrix();

        glPushMatrix();
		    glEnable(GL_TEXTURE_2D);
	        glEnable(GL_TEXTURE_GEN_S);
	        glEnable(GL_TEXTURE_GEN_T);
            for(i=0; i<N; i++){
                glPushMatrix();
                    glTranslatef(trans[i].x,0.0,trans[i].z);
                    desenhaArvores();
                glPopMatrix();
            }

        glPopMatrix();

    glPopMatrix();
}
