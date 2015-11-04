#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#define T 700

typedef struct BMPImagem_I
{
    int   width_I;
    int   height_I;
    char *data_I;
}BMPImage_I;

GLuint texture_id_I[2]; /* identificador da textura */

//-----------------------------------------------------------------------------
// Name: getBitmapImageData()
// Desc: Simply image loader for 24 bit BMP files.
//-----------------------------------------------------------------------------
void getBitmapImageData_I( char *pFileName, BMPImage_I *pImage )
{
    FILE *pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
	int i;

    if( (pFile = fopen(pFileName, "rb") ) == NULL )
		printf("ERROR: getBitmapImageData - %s not found.\n", pFileName);

    // Seek forward to width and height info
    fseek( pFile, 18, SEEK_CUR );

    if( (i = fread(&pImage->width_I, 4, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read width from %s.\n ", pFileName);

    if( (i = fread(&pImage->height_I, 4, 1, pFile) ) != 1 )
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
    int nTotalImagesize = (pImage->width_I * pImage->height_I) * 3;

    pImage->data_I = (char*) malloc( nTotalImagesize );

    if( (i = fread(pImage->data_I, nTotalImagesize, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read image data from %s.\n ", pFileName);

    //
	// Finally, rearrange BGR to RGB
	//

	char charTemp;
    for( i = 0; i < nTotalImagesize; i += 3 )
	{
		charTemp = pImage->data_I[i];
		pImage->data_I[i] = pImage->data_I[i+2];
		pImage->data_I[i+2] = charTemp;
    }
}


/*Função para Carregar uma imagem .BMP */
void CarregaTextura_I(char* Filename, int i)
{

    BMPImage_I textura;

    getBitmapImageData_I( Filename, &textura);

	/* Define que tipo de textura será usada
	 GL_TEXTURE_2D ==> define que será usada uma textura 2D (bitmaps)
	 texture_id  ==> define o número da textura  */
   glBindTexture ( GL_TEXTURE_2D, texture_id_I[i]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
   glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

    // Give the image to OpenGL
    // Define uma textura bidimensional
    glTexImage2D(GL_TEXTURE_2D, 0, 3, textura.width_I, textura.height_I, 0, GL_RGB, 		 GL_UNSIGNED_BYTE, textura.data_I);

}

void initTexture_I(void)
{

	/* Habilita o uso de textura bidimensional  */
	glEnable(GL_TEXTURE_2D);
	


	/*Carrega os arquivos de textura */
    //CarregaTextura("Neve.bmp",0);
    CarregaTextura_I("surface2.bmp",1);

}

void init_I(){
    /* Define quantas texturas serao usadas no programa  */
    glGenTextures(2, texture_id_I);
}

void Desenha_Final(void){
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glDisable(GL_COLOR_MATERIAL);
	glPushMatrix();
	    glBindTexture(GL_TEXTURE_2D, texture_id_I[1]);
	    glScalef(0.4,0.4,0.4);
	    glTranslatef(-1.2,0.8,0);
	    glPushMatrix();
          	glutSolidCube(0.2);
	    glPopMatrix();
	
	    glPushMatrix();
	        glTranslatef(0.2,0.2,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	
	    glPushMatrix();
	        glTranslatef(-0.2,0.2,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	
	    glPushMatrix();
	        glTranslatef(-0.4,0.4,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	
	    glPushMatrix();
	        glTranslatef(0.4,0.4,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(0,-0.2,0);
          	glutSolidCube(0.2);
	    glPopMatrix();

	    glPushMatrix();
	        glTranslatef(0.6,0.1,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	
	    glPushMatrix();
	        glTranslatef(0.8,0.3,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	
	    glPushMatrix();
	        glTranslatef(1,0.1,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	
	    glPushMatrix();
	        glTranslatef(0.8,-0.1,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	
	    glPushMatrix();
	        glTranslatef(1.4,0,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.4,0.2,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.6,-0.2,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.8,-0.2,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(2,0,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(2,0.2,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(-0.4,-1.1,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(-0.2,-1.3,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(0,-1.5,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(0.2,-1.3,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(0.4,-1.5,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(0.6,-1.3,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(0.8,-1.1,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.2,-1.1,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.2,-1.3,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.2,-1.5,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.6,-1.1,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.6,-1.3,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(1.6,-1.5,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glScalef(0.8,1.0,0.8);
	        glPushMatrix();
	            glTranslatef(2.2,-1.1,0);
              	glutSolidCube(0.2);
	        glPopMatrix();
	        
	        glPushMatrix();
	            glTranslatef(2.4,-1.3,0);
              	glutSolidCube(0.2);
	        glPopMatrix();
	        
	        glPushMatrix();
	            glTranslatef(2.6,-1.5,0);
              	glutSolidCube(0.2);
	        glPopMatrix();
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(2.2,-1.5,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(2.2,-1.3,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	    glPushMatrix();
	        glTranslatef(2.2,-1.1,0);
          	glutSolidCube(0.2);
	    glPopMatrix();
	    
	glPopMatrix();
 }
