#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    char dataNascimento[11];
    char cpf[20];
    char sexo;
} Cliente;

int validarNome(char *nome) {
    int tam = strlen(nome);
    if (tam == 0 || tam > 20) return 0;
    return 1;
}

int validarSexo(char sexo) {
    if (sexo == 'm' || sexo == 'M' ||
        sexo == 'f' || sexo == 'F' ||
        sexo == 'o' || sexo == 'O')
        return 1;

    return 0;
}

int validarCPF(char *cpf) {
    int tam = strlen(cpf);
    if (tam < 11 || tam > 20) return 0;

    return 1;
}

int validarData(char *data) {
    int dia, mes, ano;

    if (strlen(data) != 10) return 0;
    if (data[2] != '/' || data[5] != '/') return 0;

    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) return 0;

    if (dia < 1 || dia > 31) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (ano < 1900 || ano > 2025) return 0;

    return 1;
}

int cadastrarCliente(Cliente *cliente) {
    printf("---Nome:\n");
    scanf(" %[^\n]", cliente->nome);
    if (!validarNome(cliente->nome)) {
        printf("Erro: Nome invalido (max. 20 caracteres).\n");
        return 0;
    }

    printf("---Data de nascimento (dd/mm/aaaa):\n");
    scanf(" %s", cliente->dataNascimento);
    if (!validarData(cliente->dataNascimento)) {
        printf("Erro: Data de nascimento invalida.\n");
        return 0;
    }

    printf("---CPF (somente números ou com pontuação):\n");
    scanf(" %s", cliente->cpf);
    if (!validarCPF(cliente->cpf)) {
        printf("Erro: CPF invalido.\n");
        return 0;
    }

    printf("---Sexo (M/m, F/f, O/o):\n");
    scanf(" %c", &cliente->sexo);
    if (!validarSexo(cliente->sexo)) {
        printf("Erro: Sexo invalido.\n");
        return 0;
    }

    return 1;
}

int main() {
    Cliente cliente;

    if (cadastrarCliente(&cliente)) {
        printf("\n-----DADOS DO CLIENTE:-----\n");
        printf("Nome: %s\n", cliente.nome);
        printf("Data de nascimento: %s\n", cliente.dataNascimento);
        printf("CPF: %s\n", cliente.cpf);
        printf("Sexo: %c\n", cliente.sexo);
    } else {
        printf("\nCadastro nao realizado devido a erro nos dados.\n");
    }

    return 0;
}
