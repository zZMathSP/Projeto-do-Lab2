#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "labirinto.h"
#include "pilha.h"

int main()
{
    //=============================
    char **labirinto = NULL;
    int vitoria = 1, linha, coluna;
    int cx,cy;
    //=============================

    node *PILHA = (node *) malloc(sizeof(node));

    if(!PILHA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }inicia(PILHA);



    printf("Dimensao labirinto \nlinha: ");
    scanf("%d", &linha);
    printf("coluna: ");
    scanf("%d", &coluna);
    labirinto = alocar_labirinto(linha,coluna);

    //recebe_labirinto(labirinto);
    ler_labirinto(labirinto, coluna);
    while(vitoria){
    imprimelabirinto(labirinto,linha,coluna);
    analise_local(labirinto,&cx,&cy);
    movimento(labirinto, &cx, &cy);
    //Sleep(1000);
    getchar();
    system("cls");

    }
    printf("nn");


    desalocar_labirinto(&labirinto,10,20);
    return 0;
}
