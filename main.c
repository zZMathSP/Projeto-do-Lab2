//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LINHA 10
#define COLUNA 22
#define TOTAL 200

//registro
typedef struct Ponto2D{

    int x;
    int y;

} PILHA;

void alocar_matriz    (char ***matriz);
void desalocar_matriz (char ***matriz);
void recebe_labirinto (char ***matriz);
void analise_local (char **matriz, int *xc , int *yc);
void monta_pilha (PILHA **vet, int *topo, int xc, int xy);
void movimento(char **matriz, int *linha, int *coluna);
int analise(char** matriz, int linha, int coluna);

int main()
{
    char **labirinto = NULL;
    int i,j, vitoria = 0, topo = -1, xc, yc;
    PILHA *vet = (PILHA*)malloc(TOTAL*sizeof(PILHA));

    alocar_matriz(&labirinto);
    recebe_labirinto(&labirinto);
    analise_local(labirinto,&xc,&yc);
    monta_pilha(&vet, &topo, xc, yc);
    vitoria=analise(labirinto,xc,yc);
    getch();

    do{

        for(i=0;i<LINHA;i++){
          for(j=0;j<COLUNA;j++){

            printf("%c", labirinto[i][j]);
         }printf("\n");
         }

         movimento(labirinto,&xc,&yc);
         monta_pilha(&vet,&topo,xc,yc);
         //printf("\n%d", vitoria);
         //getch();

        Sleep(250);
        system("cls");

    }while(vitoria !=0);






    desalocar_matriz(&labirinto);
    free(vet);
    return 0;
}

void alocar_matriz    (char ***matriz){

    int i;
    (*matriz) = (char **)malloc(LINHA*sizeof(char*));

    for(i=0;i<LINHA;i++){

        (*matriz)[i] = (char*)malloc(COLUNA*sizeof(char));
    }


}
void desalocar_matriz (char ***matriz){

    int i;

    for(i=0;i<LINHA;i++)
        free((*matriz)[i]);

    free(**matriz);

}
void recebe_labirinto (char ***matriz){

    int i,j;
    char aux[LINHA][COLUNA] ={"11111111111111111111",
                             "1R0111000000011111Q1",
                             "11011110111101111101",
                             "11000000000111000101",
                             "11111111110001010101",
                             "11100000100111010101",
                             "11101110001111010101",
                             "11101111111111010101",
                             "11100000000000010001",
                             "11111111111111111111"};

    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            (*matriz)[i][j] = aux[i][j];
        }
    }

}
void analise_local (char **matriz, int *xc, int *yc){

    int i,j, verificar;

    for(i=0;i<LINHA;i++){
        for(j=0;j<COLUNA;j++){
            if(matriz[i][j] == 'R'){
                    *xc = i;
                    *yc = j;
                    break;
            }


        }
    }


}
void monta_pilha (PILHA **vet, int *topo, int xnovo, int ynovo){

    int aux;
    if (topo < TOTAL)
        *topo = *topo + 1;
        aux = *topo;
        (*vet)[aux].x = xnovo;
        (*vet)[aux].y = ynovo;


}
void movimento (char **matriz, int *linha, int *coluna){

    if(matriz[*linha+1][*coluna] == '0' && (*linha+1 > 0 && *linha+1 < LINHA)){
        matriz[*linha][*coluna] = '*';
        *linha = *linha + 1;
        matriz[*linha][*coluna] ='R';
    }else{
        if(matriz[*linha-1][*coluna] =='0' && (*linha-1 > 0 && *linha-1 < LINHA)){
            matriz[*linha][*coluna] = '*';
            *linha = *linha - 1;
            matriz[*linha][*coluna] ='R';
        }else{
                if(matriz[*linha][*coluna+1] =='0' && (*coluna+1 > 0 && *coluna+1 < COLUNA)){
                    matriz[*linha][*coluna] = '*';
                    *coluna = *coluna + 1;
                    matriz[*linha][*coluna] ='R';
                    }else{
                        if(matriz[*linha][*coluna-1] =='0' &&(*coluna-1 > 0 && *coluna-1 < COLUNA)){
                            matriz[*linha][*coluna] = '*';
                            *coluna = *coluna - 1;
                            matriz[*linha][*coluna] ='R';
                        }
                    }
        }

    }






}
int analise (char **matriz, int linha, int coluna){
    int verificar = 0;

    if(matriz[linha-1][coluna] =='0' && (linha-1 > 0 && linha-1 < LINHA))
        verificar++;

    if(matriz[linha+1][coluna] =='0' && (linha+1 > 0 && linha+1 < LINHA))
        verificar++;

    if(matriz[linha][coluna+1] =='0' && (coluna+1 > 0 && coluna+1 < COLUNA))
        verificar++;

    if(matriz[linha][coluna-1] =='0' &&(coluna-1 > 0 && coluna-1 < COLUNA))
        verificar++;




    return(verificar);

    }
