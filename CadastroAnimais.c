#include <stdio.h>
#define TAM 3

typedef struct {
    char nome[255];
    char sexo;
    int idade;
} Animal;

typedef struct {
    int ano;
    int mes;
    int dia;
} Data;

int menu() {
    int opcao;
    printf("\nOpções:\n");
    printf("1 -> Cadastrar animal\n");
    printf("2 -> Imprimir todos\n");
    printf("3 -> Imprimir animais com idade acima da média\n");
    printf("4 -> Remover animal\n");
    printf("5 -> Atualizar animal\n");
    printf("0 -> Sair\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    return opcao;
}

void dataDeNascimento(Data *dataNasc, int index) {
    printf("Informe a data de nascimento (DD MM AAAA):\n");
    scanf("%d %d %d", &dataNasc[index].dia, &dataNasc[index].mes, &dataNasc[index].ano);
}

int main() {
    Animal animais[TAM];
    Data dataNasc[TAM];
    int opcao, sair = 0, qtd = 0, excluir, att;

    while (!sair) {
        opcao = menu();

        switch (opcao) {
            case 1: {
                if (qtd < TAM) {
                    printf("Informe o nome:\n");
                    scanf("%s", animais[qtd].nome);

                    printf("Informe a idade:\n");
                    scanf("%d", &animais[qtd].idade);

                    printf("Informe o sexo (M/F):\n");
                    scanf(" %c", &animais[qtd].sexo);

                    dataDeNascimento(dataNasc, qtd);

                    qtd++;
                } else {
                    printf("Cadastro cheio.\n");
                }
                break;
            }

            case 2: {
                printf("Animais cadastrados:\n");
                for (int i = 0; i < qtd; i++) {
                    printf("\n%dº Animal:\n", i + 1);
                    printf("Nome: %s\n", animais[i].nome);
                    printf("Sexo: %c\n", animais[i].sexo);
                    printf("Idade: %d\n", animais[i].idade);
                    printf("Data de nascimento: %d/%d/%d\n", dataNasc[i].dia, dataNasc[i].mes, dataNasc[i].ano);
                }
                break;
            }

            case 3: {
                int soma = 0;
                for (int i = 0; i < qtd; i++) {
                    soma += animais[i].idade;
                }

                if (qtd == 0) {
                    printf("Nenhum animal cadastrado.\n");
                    break;
                }

                int media = soma / qtd;
                printf("Média de idade: %d\n", media);
                printf("Animais com idade acima da média:\n");

                for (int i = 0; i < qtd; i++) {
                    if (animais[i].idade > media) {
                        printf("\nNome: %s\n", animais[i].nome);
                        printf("Sexo: %c\n", animais[i].sexo);
                        printf("Idade: %d\n", animais[i].idade);
                        printf("Data de nascimento: %d/%d/%d\n", dataNasc[i].dia, dataNasc[i].mes, dataNasc[i].ano);
                    }
                }
                break;
            }

            case 4: {
                if (qtd == 0) {
                    printf("Nenhum animal para remover.\n");
                    break;
                }

                printf("Informe o número do animal que deseja excluir:\n");
                for (int i = 0; i < qtd; i++) {
                    printf("%d - %s\n", i+1, animais[i].nome);
                }
                scanf("%d", &excluir);

                if (excluir >= 0 && excluir < qtd) {
                    for (int i = excluir; i < qtd - 1; i++) {
                        animais[i] = animais[i + 1];
                        dataNasc[i] = dataNasc[i + 1];
                    }
                    qtd--;
                    printf("Animal excluído com sucesso!\n");
                } else {
                    printf("Índice inválido.\n");
                }

                break;
            }

            case 5: {
                if (qtd == 0) {
                    printf("Nenhum animal para atualizar.\n");
                    break;
                }

                printf("Informe o número do animal que deseja atualizar:\n");
                for (int i = 0; i < qtd; i++) {
                    printf("%d - %s\n", i, animais[i].nome);
                }
                scanf("%d", &att);

                if (att >= 0 && att < qtd) {
                    printf("Atualizando dados do animal: %s\n", animais[att].nome);

                    printf("Novo nome:\n");
                    scanf("%s", animais[att].nome);

                    printf("Nova idade:\n");
                    scanf("%d", &animais[att].idade);

                    printf("Novo sexo (M/F):\n");
                    scanf(" %c", &animais[att].sexo);

                    dataDeNascimento(dataNasc, att);

                    printf("Animal atualizado com sucesso!\n");
                } else {
                    printf("Índice inválido.\n");
                }

                break;
            }

            case 0: {
                sair = 1;
                printf("Saindo...\n");
                break;
            }

            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
