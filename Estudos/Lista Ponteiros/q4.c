#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int valor;
    struct reg *prox;
} No;

void insere(No **topo, int valor) {
    No *novo = (No*)malloc(sizeof(No));

    if(!novo) {
        return;
    }

    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int main() {
    No *pilha = NULL;
    int opcao, sair = 0, valor;

    while(!sair) {
        printf("Deseja inserir um valor?\n1 - Sim\n0 - Não\n");
        scanf("%d", &opcao);
    switch(opcao) {

        case 1: 
        printf("Qual valor deseja inserir?\n");
        scanf("%d", &valor);
        insere(&pilha, valor);
        printf("Valor %d inserido.\n", valor);
        break;

        case 0:
        printf("Saindo...");
        sair = 1;
        break;
    }
}
}