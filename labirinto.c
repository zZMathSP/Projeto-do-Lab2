#include <stdio.h>
#include <stdlib.h>
#include "labirinto.h"
#include "pilha.h"

//registro
struct controle {

    P2D *cabeca;
    int tamanho;

};

struct Ponto2D {

    int coordenada_x_linha;
    int coordenada_y_coluna;
    P2D *proximo;

};
//funçoes de alocar o labirinto
char **alocar_labirinto (int linha, int coluna){

    int i;
    char **labirinto_1 = (char**)malloc(linha*sizeof(char*));
    for(i=0;i<linha;i++){
        labirinto_1[i] = (char*)malloc(coluna*sizeof(char));
    }
    return labirinto_1;

}

void desalocar_labirinto (char ***labirinto_1, int linha, int coluna){

    int i;
    for(i=0;i<coluna;i++)
        free((*labirinto_1)[i]);
    free((*labirinto_1));

}

void recebe_labirinto (char**matriz){

    int i,j;
    char aux[10][20] =      {"11111111111111111111",
                             "1R0111000000011111Q1",
                             "11011111111111111101",
                             "11000000000111000101",
                             "11111111110111010101",
                             "11100000100111010101",
                             "11101110001111010101",
                             "11101111111111010101",
                             "11100000000000010001",
                             "11111111111111111111"};

    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            matriz[i][j]= aux[i][j];
}
    }

}

void imprimelabirinto (char **labirinto, int linha, int coluna){

    int i,j;
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            printf(" %c",labirinto[i][j]);
        }printf("\n");
    }
}
//funções de movimento e analise
int analise_vitorialocal (char **labirinto_1, int linha, int coluna){

    int i,j;
    int x,y;
    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            if(labirinto_1[i][j] == 'R')
                x = i;
                y = j;
        }
    }

    if((labirinto_1[x+1][y] == 'Q') && (x>0 && x<linha)){

            return 0;
       }
    if((labirinto_1[x-1][y] =='Q' )&& (x>0 && x<linha)){

            return 0;
    }
    if((labirinto_1[x][y+1] == 'Q') && (y>0 && y <coluna)){

            return 0;
        }
    if((labirinto_1[x][y-1] == 'Q') && (y>0 && y < coluna)){
            return 0;
    }
    return 1;
}

void analise_local (char **matriz, int *xc, int *yc){

    int i, j, verificar;

    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            if(matriz[i][j] == 'R'){
                    *xc = i;
                    *yc = j;
                    break;
            }


        }
    }


}

void movimento (char **matriz, int *linha, int *coluna){

    if(matriz[*linha+1][*coluna] == '0' && (*linha+1 > 0 && *linha+1 < 10)){
        matriz[*linha][*coluna] = ' ';
        *linha = *linha + 1;
        matriz[*linha][*coluna] ='R';
    }else{
        if(matriz[*linha-1][*coluna] =='0' && (*linha-1 > 0 && *linha-1 < 10)){
            matriz[*linha][*coluna] = ' ';
            *linha = *linha - 1;
            matriz[*linha][*coluna] ='R';
        }else{
                if(matriz[*linha][*coluna+1] =='0' && (*coluna+1 > 0 && *coluna+1 < 20)){
                    matriz[*linha][*coluna] = ' ';
                    *coluna = *coluna + 1;
                    matriz[*linha][*coluna] ='R';
                    }else{
                        if(matriz[*linha][*coluna-1] =='0' &&(*coluna-1 > 0 && *coluna-1 < 20)){
                            matriz[*linha][*coluna] = ' ';
                            *coluna = *coluna - 1;
                            matriz[*linha][*coluna] ='R';
    }}
        }
        }





}
//arquivo
void ler_dimensao (int *linha, int *coluna){




}

void ler_labirinto (char **labirinto, int coluna){

    FILE *arquivo;
    int i=0,j=0;
    char aux;
     arquivo = fopen("labirinto.txt","r");
     while ((aux = fgetc(arquivo))!= EOF){
        if((aux == '1' || aux == '0')||(aux == 'R' || aux == 'Q')){

                labirinto[i][j] = aux;
                j++;
                if(j == coluna){
                    i++;
                    j=0;
                }
        }


     }


     fclose(arquivo);

}
//funções da pilha
CON *criar_lista (void){

        CON *ptr = NULL;
        ptr->cabeca = NULL;
        ptr->tamanho = 0;

        return ptr;
}

void insere_final(CON *lista, int coodernada_x, int coodernada_y){

        if(lista->cabeca == NULL){

            P2D *novo = (P2D*)malloc(sizeof(P2D));
            novo->coordenada_x_linha = coodernada_x;
            novo->coordenada_y_coluna = coodernada_y;
            novo->proximo = NULL;
            lista->cabeca = novo;
            lista->tamanho++;
        }

        P2D *novo = (P2D*)malloc(sizeof(P2D));
        P2D *aux = lista->cabeca;
        novo->coordenada_x_linha = coodernada_x;
        novo->coordenada_y_coluna = coodernada_y;
        novo->proximo = NULL;
        while(aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo;
        lista->tamanho++;


}



