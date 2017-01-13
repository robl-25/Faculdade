#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

void achar_jogadas(vector< vector<int> >& grafo, int pos_col_ini, int pos_li_ini,
                   int pos_col_fim, int pos_li_fim){

    int i = pos_li_ini, j = pos_col_ini, aux;

    if(pos_col_fim != j || pos_li_fim != i){
        if(i > -1 && i < 8 && j > -1 && j < 8){

            i = pos_li_ini;
            j = pos_col_ini;

            i+=2;
            j+=1;

            if(i > -1 && i < 8 && j > -1 && j < 8){
                aux = grafo[pos_li_ini][pos_col_ini] + 1;

                if(grafo[i][j] > aux){
                    grafo[i][j] = aux;
                    achar_jogadas(grafo, j, i, pos_col_fim, pos_li_fim);
                }
            }

            if(pos_col_fim != j || pos_li_fim != i){
                i = pos_li_ini;
                j = pos_col_ini;

                i+=2;
                j-=1;

                if(i > -1 && i < 8 && j > -1 && j < 8){
                    aux = grafo[pos_li_ini][pos_col_ini] + 1;

                    if(grafo[i][j] > aux){
                        grafo[i][j] = aux;
                        achar_jogadas(grafo, j, i, pos_col_fim, pos_li_fim);
                    }
                }

                if(pos_col_fim != j || pos_li_fim != i){
                    i = pos_li_ini;
                    j = pos_col_ini;

                    i-=2;
                    j+=1;

                    if(i < 8 && j < 8 && j > -1 && i > -1){
                        aux = grafo[pos_li_ini][pos_col_ini] + 1;

                        if(grafo[i][j] > aux){
                            grafo[i][j] = aux;
                            achar_jogadas(grafo, j, i, pos_col_fim, pos_li_fim);
                        }
                    }

                    if(pos_col_fim != j || pos_li_fim != i){
                        i = pos_li_ini;
                        j = pos_col_ini;

                        i-=2;
                        j-=1;

                        if(i < 8 && j < 8 && j > -1 && i > -1){
                            aux = grafo[pos_li_ini][pos_col_ini] + 1;

                            if(grafo[i][j] > aux){
                                grafo[i][j] = aux;
                                achar_jogadas(grafo, j, i, pos_col_fim, pos_li_fim);
                            }
                        }

                        if(pos_col_fim != j || pos_li_fim != i){
                          i = pos_li_ini;
                          j = pos_col_ini;

                          i+=1;
                          j+=2;

                          if(i < 8 && j < 8 && j > -1 && i > -1){
                              aux = grafo[pos_li_ini][pos_col_ini] + 1;

                              if(grafo[i][j] > aux){
                                  grafo[i][j] = aux;
                                  achar_jogadas(grafo, j, i, pos_col_fim, pos_li_fim);
                              }
                          }

                          if(pos_col_fim != j || pos_li_fim != i){
                            i = pos_li_ini;
                            j = pos_col_ini;

                            i-=1;
                            j+=2;

                            if(i < 8 && j < 8 && j > -1 && i > -1){
                                aux = grafo[pos_li_ini][pos_col_ini] + 1;

                                if(grafo[i][j] > aux){
                                    grafo[i][j] = aux;
                                    achar_jogadas(grafo, j, i, pos_col_fim, pos_li_fim);
                                }
                            }

                            if(pos_col_fim != j || pos_li_fim != i){
                              i = pos_li_ini;
                              j = pos_col_ini;

                              i+=1;
                              j-=2;

                              if(i < 8 && j < 8 && j > -1 && i > -1){
                                  aux = grafo[pos_li_ini][pos_col_ini] + 1;

                                  if(grafo[i][j] > aux){
                                      grafo[i][j] = aux;
                                      achar_jogadas(grafo, j, i, pos_col_fim, pos_li_fim);
                                  }
                              }

                              if(pos_col_fim != j || pos_li_fim != i){
                                i = pos_li_ini;
                                j = pos_col_ini;

                                i-=1;
                                j-=2;

                                if(i < 8 && j < 8 && j > -1 && i > -1){
                                    aux = grafo[pos_li_ini][pos_col_ini] + 1;

                                    if(grafo[i][j] > aux){
                                        grafo[i][j] = aux;
                                        achar_jogadas(grafo, j, i, pos_col_fim, pos_li_fim);
                                    }
                                }
                              }
                            }
                          }
                        }
                    }

                }
            }

        }
    }

    return;
}

int main(){
    vector<char> coluna(8, 'a');
    vector<int> linha(8, 1);
    int pos_li_ini, pos_li_fim, i;
    char col_ini, col_fim;
    vector< vector<int> > grafo;
    vector<char>::iterator it;
    int pos_col_fim, pos_col_ini;

    for(i=1; i<8; i++){
      coluna[i] = (char) coluna[i-1] + 1;
      linha[i] = linha[i-1]+1;
    }

    cin >> col_ini >> pos_li_ini;
    cin >> col_fim >> pos_li_fim;

    pos_li_ini--;
    pos_li_fim--;

    for(i=0; i<8; i++){
        if(coluna[i] == col_ini){
            break;
        }
    }

    pos_col_ini = i;

    for(i=0; i<8; i++){
        if(coluna[i] == col_fim){
            break;
        }
    }

    pos_col_fim = i;

    for(i=0; i<8; i++){
        vector<int> aux(8, INT_MAX);

        grafo.push_back(aux);
    }

    grafo[pos_li_ini][pos_col_ini] = 0;

    if(pos_col_ini != pos_col_fim || pos_li_ini != pos_li_fim){
        achar_jogadas(grafo, pos_col_ini, pos_li_ini, pos_col_fim, pos_li_fim);
    }

    cout << grafo[pos_li_fim][pos_col_fim];
}
