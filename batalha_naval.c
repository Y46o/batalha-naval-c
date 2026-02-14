#include <stdio.h>

#define TAMANHO 10      // Define o tamanho do tabuleiro (10x10)
#define NAVIO_TAM 3     // Define o tamanho fixo dos navios

int main() {

    // Declaração da matriz que representa o tabuleiro
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicialização do tabuleiro com 0 (representando água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==========================
    // Definição do primeiro navio (horizontal)
    // ==========================

    int navio_horizontal[NAVIO_TAM] = {3, 3, 3};  // Vetor representando o navio
    int linha_h = 2;   // Linha inicial
    int coluna_h = 4;  // Coluna inicial

    // Validação de limite horizontal
    if (coluna_h + NAVIO_TAM <= TAMANHO) {

        // Verificação de sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < NAVIO_TAM; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) {
                sobreposicao = 1;
            }
        }

        // Posicionamento do navio se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO_TAM; i++) {
                tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
            }
        }
    }

    // ==========================
    // Definição do segundo navio (vertical)
    // ==========================

    int navio_vertical[NAVIO_TAM] = {3, 3, 3};  // Vetor representando o navio
    int linha_v = 5;   // Linha inicial
    int coluna_v = 1;  // Coluna inicial

    // Validação de limite vertical
    if (linha_v + NAVIO_TAM <= TAMANHO) {

        int sobreposicao = 0;
        for (int i = 0; i < NAVIO_TAM; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                sobreposicao = 1;
            }
        }

        // Posicionamento do navio se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO_TAM; i++) {
                tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
            }
        }
    }

    // ==========================
    // Exibição do tabuleiro
    // ==========================

    printf("\nTABULEIRO BATALHA NAVAL (NÍVEL NOVATO)\n\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
