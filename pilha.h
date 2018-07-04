#include <stdio.h>
#include <stdlib.h>

struct no
{
    int num;
    struct no *prox;
};

typedef struct no node;

int tam;

int pilha(void);
int menu(void);
void inicia(node *PILHA);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void libera(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);
