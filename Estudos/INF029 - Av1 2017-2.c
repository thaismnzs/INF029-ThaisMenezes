#include <stdio.h>
#define TAM_MAX 10

int inserirCaractere(char vector[], int *qtd){
     char c; 
     if(*qtd >= TAM_MAX) {
    printf("Cheio.");
        return 0;
     }

    printf("Informe um caractere:\n");
    scanf(" %c", &c);

    vector[*qtd] = c;
    (*qtd)++;
    printf("Inserido com sucesso.\n");
    return 1;
}

int trocaCaractere(char vector[], int qtd, char *subs) {
    char novo_c;
    printf("Informe um novo caractere:\n");
    scanf(" %c", &novo_c);

    for(int i=0; i<qtd; i++) {
        if(vector[i] > novo_c) {
            *subs = vector[i];
            vector[i] = novo_c;
            printf("Substituido: %c\nTrocado por: %c\n", *subs, novo_c);
            return 1;
        }
    }
        printf("Nao foi possivel substituir.");
        return 0;
}


int removerCaractere(char vector[], char *excluir, int *qtd) {
    if(*qtd == 0) {
        printf("Vetor vazio.");
        return 0;
    } else {
        (*qtd)--;
        *excluir = vector[*qtd];
        printf("Removido com sucesso.\n");
        return 1;
    }
}
    

void listarCaracteres(char vector[], int qtd) {
    for(int i=0; i<qtd; i++){
        printf("%c ", vector[i]);
    }
    printf("\n");
}

void imprimirCaracteresDistintos(char vector[], int qtd) {
    
     for(int i=0; i<qtd; i++){
        int temp = 0;

        for(int j=0; j<i; j++){
            if(vector[i] == vector[j]){
                temp = 1;
                break;
        }
    }

    if(!temp) {
        int contador=0;
        for(int j=0; j<qtd; j++) {
             if(vector[i] == vector[j]){
                contador++;
    }
}
printf("%c - %d vezes\n", vector[i], contador);
        }
    }
}

int menu() {
    int opcao;
    printf("\n--- MENU ---\n");
        printf("1. Inserir caractere\n");
        printf("2. Trocar caractere\n");
        printf("3. Remover caractere\n");
        printf("4. Listar caracteres\n");
        printf("5. Imprimir caracteres distintos e contagem\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        return opcao;

}

main(){
    char vector[TAM_MAX];
    char excluir, subs;
    int qtd=0;
    int opcao, sair=0;;

    while(!sair) {
        opcao = menu();

        switch(opcao) {
            case 1:{
                inserirCaractere(vector, &qtd);
                break;
        }

        case 2: {
            trocaCaractere(vector, qtd, &subs);
            break;
        }

        case 3: {
            removerCaractere(vector, &excluir, &qtd);
            break;
        }
        case 4: {
            listarCaracteres(vector, qtd);
            break;
        }

        case 5:{
            imprimirCaracteresDistintos(vector, qtd);
            break;
        }

        case 0:
        printf("Saindo...\n");
        sair=1;
        break;

        default:
        printf("Opcao invalida.");
 }
    }
}