#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define NUM_NAVIOS 5

char mapa1[TAM][TAM], mapa2[TAM][TAM];
int navios1_restantes = 0, navios2_restantes = 0;

void inicializarMapa(char mapa[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            mapa[i][j] = ' ';
}

void mostrarMapa(char mapa[TAM][TAM], int visivel) {
    printf("   ");
    for (int j = 0; j < TAM; j++) printf(" %d", j);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (!visivel && mapa[i][j] == 'N') printf("  ");
            else printf("[%c]", mapa[i][j]);
        }
        printf("\n");
    }
}

int podePosicionar(char mapa[TAM][TAM], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') {
            if (y + i >= TAM || mapa[x][y + i] != ' ') return 0;
        } else {
            if (x + i >= TAM || mapa[x + i][y] != ' ') return 0;
        }
    }
    return 1;
}

void posicionarNavio(char mapa[TAM][TAM], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') mapa[x][y + i] = 'N';
        else mapa[x + i][y] = 'N';
    }
}

void colocarNavios(char mapa[TAM][TAM], int jogador) {
    int tamanhos[NUM_NAVIOS] = {4, 3, 1, 1, 1};
    int x, y;
    char dir;
    printf("Jogador %d, posicione seus navios.\n", jogador);
    for (int i = 0; i < NUM_NAVIOS; i++) {
        do {
            printf("Navio de tamanho %d - Informe linha, coluna e direção (H/V): ", tamanhos[i]);
            scanf("%d %d %c", &x, &y, &dir);
            dir = (dir >= 'a') ? dir - 32 : dir;
            if (!podePosicionar(mapa, x, y, tamanhos[i], dir)) {
                printf("Posição inválida! Tente novamente.\n");
            }
        } while (!podePosicionar(mapa, x, y, tamanhos[i], dir));
        posicionarNavio(mapa, x, y, tamanhos[i], dir);
    }
}

int atirar(char mapa[TAM][TAM], int x, int y) {
    if (mapa[x][y] == 'N') {
        mapa[x][y] = '0';
        return 1;
    } else if (mapa[x][y] == ' '){
        mapa[x][y] = 'X';
        return 0;
    }
    return -1;
}

int contarAcertos(char mapa[TAM][TAM]) {
    int acertos = 0;
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            if (mapa[i][j] == '0') acertos++;
    return acertos;
}

int totalPecas() {
    return 4 + 3 + 1 + 1 + 1;

void limparTela() {
    printf("\n\n----------------------------\n\n");
}

int main() {
    int linha, coluna, turno = 1;
    inicializarMapa(mapa1);
    inicializarMapa(mapa2);

    colocarNavios(mapa1, 1);
    limparTela();
    colocarNavios(mapa2, 2);

    while (1) {
        limparTela();
        printf("Turno do Jogador %d\n", turno);
        printf("\nSeu mapa:\n");
        mostrarMapa((turno == 1) ? mapa1 : mapa2, 1);
        printf("\nMapa do inimigo:\n");
        mostrarMapa((turno == 1) ? mapa2 : mapa1, 0);

        do {
            printf("Informe a linha e coluna para atirar: ");
            scanf("%d %d", &linha, &coluna);
        } while (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM ||
                atirar((turno == 1) ? mapa2 : mapa1, linha, coluna) == -1);

        if (contarAcertos((turno == 1) ? mapa2 : mapa1) == totalPecas()) {
            limparTela();
            printf("Jogador %d venceu a batalha naval!\n", turno);
            break;
        }

        turno = (turno == 1) ? 2 : 1;
    }

    return 0;
}
