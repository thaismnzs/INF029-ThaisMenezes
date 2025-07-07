#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int valor;
    struct reg *proximo;
} No;

typedef struct aux {
    No *inicio; //inicio da sublista
    struct aux *proximo; //proxima sublista
} listaAuxiliar;

typedef struct {
    listaAuxiliar *inicio;
} listaPrincipal;

listaPrincipal lista;

void pegaDados(listaPrincipal *lista) {
    listaAuxiliar *atual = lista->inicio;
    int numListas = 1; //começa com uma lista, que é a atual
    
    if(atual == NULL) {
        return;
    }
    
    while(atual != NULL) {
        No *percorrer = atual->inicio;
        float somatorio = 0, tam = 0;
        
        while(percorrer != NULL) {
        somatorio += percorrer->valor;
        tam++;
        percorrer = percorrer->proximo;
    }
    if(tam == 0) {
        printf("Lista %d vazia.\n", numListas);
    } else {
        float media = somatorio / tam;
        printf("Lista %d:\nMédia: %f", numListas, media);
        printf("Elementos maiores que a média:\n");
        
        percorrer = atual->inicio;
        while(percorrer != NULL) {
            if(percorrer->valor > media) {
                printf("%d ", percorrer->valor);
            }
            percorrer = percorrer->proximo;
        }
        printf("\n");
    }
    
    atual = atual->proximo; //proxima lista
    numListas++;
    }
}

void insereLista(listaPrincipal *lista, int valor, int posicao) {
    listaAuxiliar *atual = lista->inicio;
    int numListas = 1;
    
    while(atual != NULL && numListas < posicao) {
        atual = atual->proximo;
        numListas++;
    }
    
    if(atual == NULL){
        return;
    }
    
     No *novo = (No*)malloc(sizeof(No));
     novo->valor = valor;
     novo->proximo = NULL;
     
     if(atual->inicio == NULL){
         atual->inicio = novo;
     } else {
         No *percorrer = atual->inicio;
         while(percorrer->proximo != NULL){
             percorrer = percorrer->proximo;
         }
         percorrer->proximo = novo;
     }
}

void criarLista(listaPrincipal *lista){
    listaAuxiliar *nova = (listaAuxiliar*)malloc(sizeof(listaAuxiliar));
    nova->inicio = NULL;
    nova->proximo = NULL;
    
    if(lista->inicio == NULL) {
        lista->inicio = nova;
    } else {
        listaAuxiliar *percorrer = lista->inicio;
        while(percorrer->proximo != NULL) {
            percorrer = percorrer->proximo;
        }
        percorrer->proximo = nova;
    }
    printf("Sublista criada.\n");
}

int menu(){
    int opcao;
    printf("1 - Criar nova sublista\n");
    printf("2 - Inserir valor em sublista\n");
    printf("3 - Mostrar elementos maiores que a média\n");
    printf("0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    lista.inicio = NULL;
    int opcao, sair=0, sublista, valor;

    
    while(!sair) {
        opcao = menu();
        switch(opcao) {
            case 1:
            criarLista(&lista);
            break;
            
            case 2:
            printf("Informe a sublista:\n");
            scanf("%d", &sublista);
            printf("Informe o valor a ser inserido:\n");
            scanf("%d", &valor);
            insereLista(&lista, valor, sublista);
            break;
            
            case 3: 
            pegaDados(&lista);
            break;
            
            case 0:
            printf("Saindo...");
            sair = 1;
            break;
            
            default:
            printf("Opção inválida.");
        }
    }
}

