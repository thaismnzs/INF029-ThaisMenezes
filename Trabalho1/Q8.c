#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarTabuleiro(char tabuleiro[3][3]) {
    printf("\n   1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < 3; j++) {
            printf("%c", tabuleiro[i][j]);
            if (j < 2) printf(" | ");
        }
        if (i < 2) printf("\n  -----------\n");
    }
    printf("\n");
}

int verificarGanhador(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {

        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return tabuleiro[0][i];
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return tabuleiro[0][2];
    return ' ';
}

int jogadaValida(char jogada[], char tabuleiro[3][3]) {
    if (strlen(jogada) != 2) return 0;
    char linha = jogada[0];
    char coluna = jogada[1];
    int i = linha - 'A';
    int j = coluna - '1';
    if (i >= 0 && i < 3 && j >= 0 && j < 3) {
        if (tabuleiro[i][j] == ' ')
            return 1;
    }
    return 0;
}

void realizarJogada(char jogada[], char tabuleiro[3][3], char simbolo) {
    int i = jogada[0] - 'A';
    int j = jogada[1] - '1';
    tabuleiro[i][j] = simbolo;
}

int main() {
    char tabuleiro[3][3];
    char jogada[3];
    int turno = 0;
    char ganhador = ' ';

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';

    while (turno < 9 && ganhador == ' ') {
        mostrarTabuleiro(tabuleiro);
        printf("Jogador %d, informe sua jogada (ex: A1): ", (turno % 2) + 1);
        scanf("%s", jogada);
        strupr(jogada);

        if (jogadaValida(jogada, tabuleiro)) {
            realizarJogada(jogada, tabuleiro, (turno % 2 == 0) ? 'X' : 'O');
            ganhador = verificarGanhador(tabuleiro);
            turno++;
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }
    }

    mostrarTabuleiro(tabuleiro);
    if (ganhador != ' ') {
        printf("Parabéns! Jogador %c venceu!\n", ganhador == 'X' ? '1' : '2');
    } else {
        printf("Empate! Nenhum jogador venceu.\n");
    }

    return 0;
}
