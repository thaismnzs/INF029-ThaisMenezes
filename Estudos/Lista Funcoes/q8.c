#include <stdio.h>

typedef struct {
    char nome[20];
    char dataNascimento[11];
    char cpf[20];
    char sexo;
} Cliente;

Cliente cadastrarCliente() {
    Cliente cliente;

   printf("---Nome:\n");
    scanf("%s", cliente.nome);
    printf("---Data de nascimento (dd/mm/aaaa):\n");
    scanf("%s", cliente.dataNascimento);
    printf("---CPF (XXX.XXX.XXX-XX):\n");
    scanf("%s", cliente.cpf);
    printf("---Sexo (M-m/F-f/O-o):\n");
    scanf(" %c", &cliente.sexo);
    
    return cliente;
}

int main() {
    Cliente cliente = cadastrarCliente();

    printf("-----DADOS DO CLIENTE:-----\n");
    printf("Nome: %s\n", cliente.nome);
    printf("Data de nascimento: %s\n", cliente.dataNascimento);
    printf("CPF: %s\n", cliente.cpf);
    printf("Sexo: %c\n", cliente.sexo);
}