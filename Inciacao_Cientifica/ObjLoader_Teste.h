#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#define POINTS_PER_VERTEX 3
#define TOTAL_FLOATS_IN_TRIANGLE 9
using namespace std;

/***************************************************************************
  OBJ Loading
 ***************************************************************************/

class Model_OBJ
{
  private:

    // Stores the normals
    float* normals;

    // Stores the triangles
    float* Faces_Triangles;
    float* Faces_Triangles_aux;

    // Stores the points which make the object
    float* vertexBuffer;
    float* vertexBuffer_aux;

    int* vertexNumber;
    int* vertexNumberBuffer_aux;

    // Stores the total number of connected verteces
    long TotalConnectedPoints;

    long TotalVertexNumber;

    // Stores the total number of connected triangles
    long TotalConnectedTriangles;

    float xpv, ypv, zpv, fv, distancia, fv2, d2;

    //Para armazenar os campos de forca
    typedef struct a{
        float x, y, z;
        float d1, d2;
        float F;
        float fv1, fv2;
        char tipo;
        a *prox;
    }Vetores;

    Vetores *v;

    public:

      //Contrala qual eh o ponto escolhido
      int ponto;

      //Tempo
      int tv;

      float ka, kv;

    Model_OBJ()
    {
        this->TotalConnectedTriangles = 0;
        this->TotalConnectedPoints = 0;
        this->TotalVertexNumber = 0;
        this->ka=0;
        this->tv=0;
        this->kv=0;
        this->ponto = -1;
        this->xpv = 0;
        this->ypv = 0;
        this->zpv = 0;
        this->fv = 0;
        this->distancia = 0;
        this->fv2 = 0;
        this->d2 = 0;

        v = new Vetores;
        Vetores *novo;
        Vetores *aux;
        int i = 0;

        char* filename = (char*) "forca.txt";
        string line;
        ifstream forcaFile (filename);

         if(forcaFile.is_open()){
            while(! forcaFile.eof()){
                getline (forcaFile,line);
                if(i == 0){
                    sscanf(line.c_str(),"%f %f %f %f %f %f %f %f %c",
                        &v->x, &v->y, &v->z, &v->d1, &v->d2, &v->F,
                        &v->fv1, &v->fv2, &v->tipo);
                    v->prox = NULL;
                    aux = v;
                }
                else{
                    novo = new Vetores;
                    sscanf(line.c_str(),"%f %f %f %f %f %f %f %f %c",
                            &novo->x, &novo->y, &novo->z, &novo->d1, &novo->d2,
                            &novo->F, &novo->fv1, &novo->fv2, &novo->tipo);
                    novo->prox = NULL;
                    aux->prox = novo;
                    aux = novo;
                }
                i++;
            }
            forcaFile.close();
        }

        else{
            //As coordenadas do ponto de dentro do ventriculo esquerdo
            v->x = 0.88030;
            v->y = -1.567663;
            v->z = -0.64010;
            v->d1 = 3;
            v->d2 = 0;
            v->F = 0;
            v->fv1 = 5;
            v->fv2 = 0;
            v->tipo = 'v';
            v->prox = NULL;
            aux = v;

            //As coordenadas do ponto de dentro e em baixo do ventriculo esquerdo
            novo = new Vetores;
            novo->x = 0.90030;
            novo->y = -2.57663;
            novo->z = -1.78010;
            novo->d1 = 3;
            novo->d2 = 1;
            novo->F = 0;
            novo->fv1 = 0.7;
            novo->fv2 = 2;
            novo->tipo = 'v';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //As coordenadas do ponto dentro da parede inferior do ventriculo esquerdo
            novo = new Vetores;
            novo->x = 0.90030;
            novo->y = -2.747663;
            novo->z = -2.04010;
            novo->d1 = 0.45;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 0.32;
            novo->fv2 = 0;
            novo->tipo = 'v';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //Ventriculo esquerdo interno esquerdo
            novo = new Vetores;
            novo->x = 1.16030;
            novo->y = -2.417663;
            novo->z = -2.21010;
            novo->d1 = 0.45;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 0.32;
            novo->fv2 = 0;
            novo->tipo = 'v';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //As coordenadas do ponto de fora do ventriculo esquerdo
            novo = new Vetores;
            novo->x = 3.28030;
            novo->y = -2.867663;
            novo->z = -2.44010;
            novo->d1 = 2;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 1;
            novo->fv2 = 0;
            novo->tipo = 'v';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //Coordenadas do ponto de fora do ventriculo direito
            novo = new Vetores;
            novo->x = -1.98030;
            novo->y = -3.267663;
            novo->z = -3.44010;
            novo->d1 = 1.5;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 1;
            novo->fv2 = 0;
            novo->tipo = 'v';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //Coordenadas do ponto de dentro do ventriculo direito
            novo = new Vetores;
            novo->x = -1.18030;
            novo->y = -2.267663;
            novo->z = -1.44010;
            novo->d1 = 1;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 1;
            novo->fv2 = 0;
            novo->tipo = 'v';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //Coordenadas do ponto de cima do ventriculo direito
            novo = new Vetores;
            novo->x = -1.18030;
            novo->y = -0.867663;
            novo->z = -3.54010;
            novo->d1 = 1;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 1;
            novo->fv2 = 0;
            novo->tipo = 'v';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //Coordenadas do ponto fora e no meio dos ventriculos
            novo = new Vetores;
            novo->x = 0.98030;
            novo->y = -3.967663;
            novo->z = -3.44010;
            novo->d1 = 2;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 0.5;
            novo->fv2 = 0;
            novo->tipo = 'v';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //Coordenadas do ponto de dentro do atrio esquerdo
            novo = new Vetores;
            novo->x = 0.08030;
            novo->y = 0.367663;
            novo->z = 1.44010;
            novo->d1 = 1;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 1;
            novo->fv2 = 0;
            novo->tipo = 'a';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //Coordenadas do ponto de fora do atrio esquerdo
            novo = new Vetores;
            novo->x = 0.08030;
            novo->y = -1.367663;
            novo->z = 2.64010;
            novo->d1 = 1;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 1;
            novo->fv2 = 0;
            novo->tipo = 'a';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;

            //Coordenadas do ponto do atrio direito
            novo = new Vetores;
            novo->x = -1.98030;
            novo->y = -0.967663;
            novo->z = 1.04010;
            novo->d1 = 2.5;
            novo->d2 = 0;
            novo->F = 0;
            novo->fv1 = 1;
            novo->fv2 = 0;
            novo->tipo = 'a';
            novo->prox = NULL;
            aux->prox = novo;
            aux = novo;
        }
        forcaFile.close();
    }

    float* calculateNormal(float *coord1, float *coord2, float *coord3)
    {
       /* calculate Vector1 and Vector2 */
       float va[3], vb[3], vr[3], val;
       va[0] = coord1[0] - coord2[0];
       va[1] = coord1[1] - coord2[1];
       va[2] = coord1[2] - coord2[2];

       vb[0] = coord1[0] - coord3[0];
       vb[1] = coord1[1] - coord3[1];
       vb[2] = coord1[2] - coord3[2];

       /* cross product */
       vr[0] = va[1] * vb[2] - vb[1] * va[2];
       vr[1] = vb[0] * va[2] - va[0] * vb[2];
       vr[2] = va[0] * vb[1] - vb[0] * va[1];

       /* normalization factor */
       val = sqrt( vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2] );

        float* norm = (float*)malloc(sizeof(float)*3);
        norm[0] = vr[0]/val;
        norm[1] = vr[1]/val;
        norm[2] = vr[2]/val;


        return norm;
    }
    //As funcoes abaixo sao para deslocamento do ponto escolhido
    void aumentaPontox(){
        xpv += 0.01;
        Modifica();
    }

    void aumentaPontoy(){
        ypv += 0.01;
        Modifica();
    }

    void aumentaPontoz(){
        zpv += 0.01;
        Modifica();
    }

    void diminuiPontox(){
        xpv -= 0.01;
        Modifica();
    }

    void diminuiPontoy(){
        ypv -= 0.01;
        Modifica();
    }

    void diminuiPontoz(){
        zpv -= 0.01;
        Modifica();
    }

    //Funcoes de aumentar ou diminuir a forca do campo de forca
    void aumentaFv(){
        fv += 0.01;
        Modifica();
    }

    void diminuiFv(){
        fv -= 0.01;
        Modifica();
    }

    void aumentaFv2(){
        fv2 += 0.01;
        Modifica();
    }

    void diminuiFv2(){
        fv2 -= 0.01;
        Modifica();
    }

    //Funcao que aumenta ou diminui o campo de influencia dos campos de forcas
    void aumentaDistancia(){
        distancia += 0.05;
        Modifica();
    }

    void diminuiDistancia(){
        distancia -= 0.05;
        Modifica();
    }

    void aumentaDistancia2(){
        d2 += 0.05;
        Modifica();
    }

    void diminuiDistancia2(){
        d2 -= 0.05;
        Modifica();
    }

    //Funcao para atribuir as variaveis modificadas acima na lista
    void Modifica(){
        int j, sair = 0;
        Vetores *aux;

        if(this->ponto <= (-1)){
            return;
        }

        for(j=0, aux = v; sair!=1; j++){
            if(j == this->ponto){
                    aux->x = xpv;
                    aux->y = ypv;
                    aux->z = zpv;
                    aux->d1 = distancia;
                    aux->d2 = d2;
                    aux->fv1 = fv;
                    aux->fv2 = fv2;
                    sair = 1;
            }
            if(aux->prox == NULL && sair != 1){
                aux = v;
            }
            else{
                aux = aux->prox;
            }
        }
    }

    void pontoEscolhido(int p){
        int j,sair = 0;
        Vetores *aux;

        this->ponto = p;

        if(this->ponto <= (-1)){
            return;
        }

        for(aux = v, j = 0; sair != 1; j++){
            if(j == this->ponto){
                this->xpv = aux->x;
                this->ypv = aux->y;
                this->zpv = aux->z;
                this->distancia = aux->d1;
                this->d2 = aux->d2;
                this->fv = aux->fv1;
                this->fv2 = aux->fv2;
                sair = 1;
            }
            if(aux->prox == NULL && sair != 1){
                aux = v;
            }
            else{
                aux = aux->prox;
            }
        }
    }


    void NovoPonto(){
        char opcao,op;
        int j = 1;

        printf("Deseja continuar?(s/n) ");
        scanf("%c",&op);
        while(op != 's' && op != 'n'){
            scanf("%c",&op);
          }

        if(op == 's'){
          printf("Esse novo campo sera para o atrio(a) ou ventriculo(v)? ");
          scanf("%c",&opcao);
          while(opcao != 'a' && opcao != 'v'){
            scanf("%c",&opcao);
          }

          Vetores *novo = new Vetores;
          Vetores *aux;

          novo->x = 0;
          novo->y = 0;
          novo->z = 0;
          novo->F = 0;
          novo->fv1 = 0;
          novo->fv2 = 0;
          novo->d1 = 0;
          novo->d2 = 0;
          novo->tipo = opcao;

          for(aux = v; aux->prox != NULL; aux = aux->prox, j++);

          novo->prox = NULL;
          aux->prox = novo;
          this->ponto = j;

          printf("\nPonto inserido com sucesso\n");
        }

    }

    void ExcluiPonto(){
        int j, sair = 0;
        Vetores *aux;

        if(this->ponto <= (-1)){
            return;
        }

        for(j=0, aux = v; sair!=1; j++){
            if((j+1) == this->ponto){
                Vetores *aux2;
                aux2 = aux->prox;
                aux->prox = aux2->prox;
                sair = 1;
                free(aux2);
                printf("\nPonto removido com sucesso\n");
            }
            if(aux->prox == NULL && sair != 1){
                aux = v;
            }
            else{
                aux = aux->prox;
            }
        }
        this->ponto--;
    }

    // Loads the model
    int Load(char* filename, int i)
    {
        string line;
        ifstream objFile (filename);

        // If obj file is open, continue
        if (objFile.is_open())
        {
            // Go to end of the file, get file size
            // we'll use this to register memory for our 3d model
            objFile.seekg (0, ios::end);
            long fileSize = objFile.tellg();
            objFile.seekg (0, ios::beg);

            // Allocate memory for the verteces
            vertexBuffer = (float*) malloc (fileSize);
            vertexBuffer_aux = (float*) malloc (fileSize);

            // Allocate memory for the triangles
            Faces_Triangles = (float*) malloc(fileSize*sizeof(float));

            // Allocate memory for the normals
            normals  = (float*) malloc(fileSize*sizeof(float));

            vertexNumber = (int*) malloc(fileSize*sizeof(int));
            vertexNumberBuffer_aux = (int*) malloc(fileSize*sizeof(int));

            // Set triangle index to zero
            int triangle_index = 0;

            // Set normal index to zero
            int normal_index = 0;

            int pos=0;

            // Start reading file data
            while (! objFile.eof() )
            {
                // Get line from file
                getline (objFile,line);

                // The first character is a v: on this line is a vertex stored.
                if (line.c_str()[0] == 'v')
                {
                    // Set first character to 0. This will allow us to use sscanf
                    line[0] = ' ';

                    // Read floats from the line: v X Y Z
                    sscanf(line.c_str(),"%f %f %f ",
                        &vertexBuffer[TotalConnectedPoints],
                        &vertexBuffer[TotalConnectedPoints+1],
                        &vertexBuffer[TotalConnectedPoints+2]);

                    vertexBuffer_aux[TotalConnectedPoints] =
                        vertexBuffer[TotalConnectedPoints];

                    vertexBuffer_aux[TotalConnectedPoints+1] =
                        vertexBuffer[TotalConnectedPoints+1];

                    vertexBuffer_aux[TotalConnectedPoints+2] =
                        vertexBuffer[TotalConnectedPoints+2];

                    // Add 3 to the total connected points
                    TotalConnectedPoints += POINTS_PER_VERTEX;

                    }

                    // The first character is an 'f': on this line is a point stored
                    if (line.c_str()[0] == 'f')
                    {
                    // Set first character to 0. This will allow us to use sscanf
                    line[0] = ' ';

                    // Read integers from the line:  f 1 2 3
                    sscanf(line.c_str(),"%i%i%i",
                    // First point of our triangle. This is an
                    // pointer to our vertexBuffer list
                    // each point represents an x,y,z.
                    &vertexNumber[TotalVertexNumber],
                    &vertexNumber[TotalVertexNumber+1],
                    &vertexNumber[TotalVertexNumber+2]);

                    // OBJ file starts counting from 1
                    vertexNumber[TotalVertexNumber] -= 1;

                    // OBJ file starts counting from 1
                    vertexNumber[TotalVertexNumber+1] -= 1;

                    // OBJ file starts counting from 1
                    vertexNumber[TotalVertexNumber+2] -= 1;

                    TotalVertexNumber += 3;


                    /********************************************************************
                    * Create triangles (f 1 2 3) from points: (v X Y Z) (v X Y Z) (v X Y Z).
                    * The vertexBuffer contains all verteces
                    * The triangles will be created using the verteces we read previously

                    */
                    int tCounter = 0;
                    for (int i = 0; i < POINTS_PER_VERTEX; i++)
                    {
                        Faces_Triangles[triangle_index + tCounter] =
                            vertexBuffer_aux[3*vertexNumber[i+pos]];

                        Faces_Triangles[triangle_index + tCounter +1] =
                                vertexBuffer_aux[3*vertexNumber[i+pos]+1];

                        Faces_Triangles[triangle_index + tCounter +2] =
                                vertexBuffer_aux[3*vertexNumber[i+pos]+2];

                        tCounter += POINTS_PER_VERTEX;
                    }
                    pos+=3;

                /*****************************************************************
                 * Calculate all normals, used for lighting

                 */
                /*float coord1[3] = { Faces_Triangles[triangle_index],
                                        Faces_Triangles[triangle_index+1],
                                        Faces_Triangles[triangle_index+2]};


                    float coord2[3] = { Faces_Triangles[triangle_index+3],
                                        Faces_Triangles[triangle_index+4],
                                        Faces_Triangles[triangle_index+5]};

                    float coord3[3] = { Faces_Triangles[triangle_index+6],

                                        Faces_Triangles[triangle_index+7],
                                        Faces_Triangles[triangle_index+8]};

                    float *norm = this->calculateNormal(coord1, coord2, coord3);


                    tCounter = 0;
                    for (int i = 0; i < POINTS_PER_VERTEX; i++)
                    {
                        normals[normal_index + tCounter ] = norm[0];

                        normals[normal_index + tCounter +1] = norm[1];
                        normals[normal_index + tCounter +2] = norm[2];
                        tCounter += POINTS_PER_VERTEX;
                    }*/

                    triangle_index += TOTAL_FLOATS_IN_TRIANGLE;
                    //normal_index += TOTAL_FLOATS_IN_TRIANGLE;
                    TotalConnectedTriangles += TOTAL_FLOATS_IN_TRIANGLE;
                }
            }
            // Close OBJ file
            objFile.close();
        }
        else
        {
            cout << "Unable to open file";
        }
        return 0;
    }

    //Controla o tempo de contracao do coracao
    void Tempo_Contracao(){
        switch(tv%6){
            case 0:
                kv = 0;
                ka = -0.005;
                break;
            case 1:
                kv = 0;
                ka = -0.01;
                break;
            case 2:
                kv = -0.005;
                ka = -0.005;
                break;
            case 3:
                kv = -0.01;
                ka = 0;
                break;
            case 4:
                kv = -0.005;
                ka = 0;
                break;
            case 5:
                kv = 0;
                ka = 0;
                break;
        }
        tv++;

        //Recalcula os pontos
        Forca();
    }

    //Calcula a forca dos pontos no coracao
    void Forca(){
        int triangle_index = 0;
        int pos = 0,i,j=0;
        Vetores *aux1;

        float X1, Y1, Z1, D1;

        //Forca total
        float F;

        //#pragma omp parallel for private(aux1, i)
        for(i=0; i<TotalConnectedPoints; i+=3){
            F = 0;

            for(aux1 = v; aux1 != NULL;aux1 = aux1->prox,j++){
                X1 = abs(vertexBuffer_aux[i] - aux1->x);
                Y1 = abs(vertexBuffer_aux[i+1] - aux1->y);
                Z1 = abs(vertexBuffer_aux[i+2] - aux1->z);
                D1 = sqrt(pow(X1,2) + pow(Y1,2) + pow(Z1,2));

                if(aux1->tipo == 'v'){
                    if(D1 < aux1->d1){
                        if(D1 < aux1->d2){
                            aux1->F = aux1->fv2*(kv/(D1));

                        }
                        else
                            aux1->F = aux1->fv1*(kv/(D1));
                    }
                    else{
                         aux1->F = 0;
                    }
                }

                else{
                    if(D1 < aux1->d1){
                        if(D1 < aux1->d2)
                            aux1->F = aux1->fv2*(ka/(D1));
                        else
                            aux1->F = aux1->fv1*(ka/(D1));
                    }
                    else{
                         aux1->F = 0;
                    }
                }

                F += aux1->F;
            }

            vertexBuffer_aux[i] = vertexBuffer[i] + (F*vertexBuffer[i]);

            vertexBuffer_aux[i+1] = vertexBuffer[i+1] + (F*vertexBuffer[i+1]);

            vertexBuffer_aux[i+2] = vertexBuffer[i+2] + (F*vertexBuffer[i+2]);
         }

         for(int h=0; h<TotalVertexNumber; h+=3){

            int tCounter = 0;
            for (int j = 0; j < POINTS_PER_VERTEX; j++)
            {
                Faces_Triangles[triangle_index + tCounter] =
                            vertexBuffer_aux[3*vertexNumber[j+pos]];

                Faces_Triangles[triangle_index + tCounter +1] =
                                vertexBuffer_aux[3*vertexNumber[j+pos]+1];

                Faces_Triangles[triangle_index + tCounter +2] =
                                vertexBuffer_aux[3*vertexNumber[j+pos]+2];

                tCounter += POINTS_PER_VERTEX;
             }
            triangle_index += TOTAL_FLOATS_IN_TRIANGLE;
            pos+=3;
        }

        free(aux1);
    }

     // Draws the model on the screen
    void Draw()
    {
        glColor3f(1 , 0, 0);
        // Enable vertex arrays
        glEnableClientState(GL_VERTEX_ARRAY);

        // Enable normal arrays
        glEnableClientState(GL_NORMAL_ARRAY);

        // Vertex Pointer to triangle array
        glVertexPointer(3,GL_FLOAT, 0,Faces_Triangles);

        // Normal pointer to normal array
        glNormalPointer(GL_FLOAT, 0, normals);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Draw the triangles
        glDrawArrays(GL_TRIANGLES, 0, TotalConnectedTriangles);

        Vetores *aux1;
        int j, soma = 0;

        glPointSize(10);
        glBegin(GL_POINTS);
            aux1 = v;
            j = 0;
            while(aux1 != NULL){
                if(j == this->ponto){
                    glColor3f(0,0,0);
                    glVertex3f(aux1->x, aux1->y, aux1->z);
                    soma = 0;
                }
                else{
                    glColor3f(1, 1, 0);
                    glVertex3f(aux1->x, aux1->y, aux1->z);
                    soma = 0;
                }
                if(aux1->prox == NULL && j < this->ponto){
                    soma = 1;
                }
                if(soma == 0){
                    aux1 = aux1->prox;
                }
                else{
                    aux1 = v;
                }
                j++;
            }
        glEnd();



        // Disable vertex arrays
        glDisableClientState(GL_VERTEX_ARRAY);

        // Disable normal arrays
        glDisableClientState(GL_NORMAL_ARRAY);
    }

    //Funcao para armazenar as modificacoes feitas nas forcas
    void Guarda_Forca(){
        Vetores *aux;
        //Arquivo para guardar as forcas
        FILE *arq;
        //Abertura do arquivo
        arq = fopen("forca.txt", "w");

        if(arq == NULL){
            printf("Erro, nao foi possivel abrir o arquivo\n");
            return ;
        }

        for(aux = v; aux != NULL; aux = aux->prox){
            fprintf(arq,"%f\t",aux->x);
            fprintf(arq,"%f\t",aux->y);
            fprintf(arq,"%f\t",aux->z);
            fprintf(arq,"%f\t",aux->d1);
            fprintf(arq,"%f\t",aux->d2);
            fprintf(arq,"%f\t",aux->F);
            fprintf(arq,"%f\t",aux->fv1);
            fprintf(arq,"%f\t",aux->fv2);
            fprintf(arq,"%c\n",aux->tipo);
        }
        fclose(arq);
    }

    // Release the model
    void Release()
    {
        free(this->Faces_Triangles);
        free(this->normals);
        free(this->vertexBuffer);
        free(v);
    }
};
