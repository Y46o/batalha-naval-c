#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {

    // ===============================
    // 1. Declaração do tabuleiro
    // ===============================
    int tabuleiro[TAM][TAM];

    // Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===============================
    // 2. Navio Horizontal
    // ===============================
    int linha_h = 1, coluna_h = 2;

    if (coluna_h + NAVIO <= TAM) {

        int sobreposicao = 0;

        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linha_h][coluna_h + i] = 3;
            }
        }
    }

    // ===============================
    // 3. Navio Vertical
    // ===============================
    int linha_v = 4, coluna_v = 0;

    if (linha_v + NAVIO <= TAM) {

        int sobreposicao = 0;

        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = 3;
            }
        }
    }

    // ===============================
    // 4. Navio Diagonal ↘ (principal)
    // ===============================
    int linha_d1 = 6, coluna_d1 = 6;

    if (linha_d1 + NAVIO <= TAM && coluna_d1 + NAVIO <= TAM) {

        int sobreposicao = 0;

        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha_d1 + i][coluna_d1 + i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
            }
        }
    }

    // ===============================
    // 5. Navio Diagonal ↙ (secundária)
    // ===============================
    int linha_d2 = 0, coluna_d2 = 9;

    if (linha_d2 + NAVIO <= TAM && coluna_d2 - (NAVIO - 1) >= 0) {

        int sobreposicao = 0;

        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha_d2 + i][coluna_d2 - i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
            }
        }
    }

    // ===============================
    // 6. Exibição do Tabuleiro
    // ===============================
    printf("\nTABULEIRO - NÍVEL AVENTUREIRO\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
