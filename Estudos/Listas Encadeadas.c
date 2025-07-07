#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
   int valor;
   struct reg *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void inserirInicio(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
}

void inserirFinal(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    
    if(lista->inicio == NULL) {
        lista->inicio = novo;
        novo->proximo = NULL;
    } else {
        No *percorrer = lista->inicio;
        while(percorrer->proximo != NULL) {
            percorrer = percorrer->proximo;
        }
        percorrer->proximo = novo;
        novo->proximo = NULL;
    }
    lista->tam++;
}

void excluirElemento(Lista *lista, int valor) {
    No *remover;
    if(lista->inicio->valor == valor) {
        remover = lista->inicio;
        lista->inicio = remover->proximo;
        remover->proximo = NULL;
        free(remover);
        lista->tam--;
    } else {
        No *percorrer = lista->inicio;
        while(percorrer->proximo != NULL && percorrer->proximo->valor != valor){
            percorrer = percorrer->proximo;
        }
        if(percorrer->proximo == NULL) {
            printf("O valor não existe na lista.");
        } else {
            remover = percorrer->proximo;
            percorrer->proximo = remover->proximo;
            remover->proximo = NULL;
            free(remover);
            printf("Valor %d removido.\n", valor);
            lista->tam--;
        }
    }
}

void imprimirLista(Lista *lista) {
    No *percorrer = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    
    while(percorrer != NULL) {
        printf("%d -> ", percorrer->valor);
        percorrer = percorrer->proximo;
    }
}

void dividirLista(Lista *lista) {
    No *percorrer = lista->inicio;
    int contador=0, contador1, contador2;
    
    while(percorrer != NULL) {
        contador++;
       percorrer = percorrer->proximo;
    }
    
    if(contador % 2 == 0) {
        contador1 = contador/2;
        contador2 = contador/2;
    } else if (contador % 2 != 0) {
        contador1 = (contador-1) / 2;
        contador2 = (contador-1) / 2;
        contador1++;
    }
    
    Lista *lista1 = (Lista*)malloc(sizeof(Lista));
    Lista *lista2 = (Lista*)malloc(sizeof(Lista));
    lista1->inicio = NULL;
    lista1->tam = 0;
    lista2->inicio = NULL;
    lista2->tam = 0;
    int i=0;
    No *atual = lista->inicio;

    while(atual != NULL) {
        if(i < contador1) {
            inserirFinal(lista1, atual->valor);
        } else {
            inserirFinal(lista2, atual->valor);
        }
        atual = atual->proximo;
        i++;
    }
    
        printf("Lista 1:\n");
            imprimirLista(lista1);
            printf("\n");
            printf("Lista 2:\n");
            imprimirLista(lista2);
}

int menu(){
    int opcao;
    printf("\n-----MENU-----\n");
    printf("1 - Inserir no inicio\n2 - Inserir no final\n3 - Remover elemento\n4 - Imprimir lista\n5 - Dividir lista\n0 - Sair\n");
    printf("Opção desejada:\n");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    Lista lista;
    int opcao, valor, sair=0;
    lista.tam = 0;
    lista.inicio = NULL;
    
    
    while(!sair) {
        opcao = menu();
    switch(opcao) {
        case 1:
        printf("Informe o valor a ser inserido:\n");
        scanf("%d", &valor);
        inserirInicio(&lista, valor);
        printf("Valor inserido!");
        break;
        
        case 2:
        printf("Informe o valor a ser inserido:\n");
        scanf("%d", &valor);
        inserirFinal(&lista, valor);
        printf("Valor inserido!");
        break;
        
        case 3:
        printf("Informe o valor a ser removido:\n");
        scanf("%d", &valor);
        excluirElemento(&lista, valor);
        printf("Valor removido!");
        break;
        
        case 4:
        imprimirLista(&lista);
        break;
        
        case 5:
        dividirLista(&lista);
        break;
        
        case 0:
        printf("Saindo...");
        break;
        
        default:
        printf("Opção inválida.");
        break;
    }
    
    }
}
  
