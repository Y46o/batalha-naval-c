#include <stdio.h>
#include <stdlib.h> // para abs()

#define TAM 10       // Tamanho do tabuleiro
#define HAB 5        // Tamanho das matrizes de habilidade

int main() {

    // =====================================================
    // 1. DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO
    // =====================================================

    int tabuleiro[TAM][TAM];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =====================================================
    // 2. POSICIONAMENTO DE NAVIOS (VALOR 3)
    // =====================================================

    // Navio horizontal
    tabuleiro[4][4] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[4][6] = 3;

    // Navio vertical
    tabuleiro[1][8] = 3;
    tabuleiro[2][8] = 3;
    tabuleiro[3][8] = 3;

    // =====================================================
    // 3. CRIAÇÃO DAS MATRIZES DE HABILIDADE
    // =====================================================

    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    int centro = HAB / 2;

    // Construção dinâmica das formas
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            // -------------------------
            // CONE (aponta para baixo)
            // -------------------------
            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;

            // -------------------------
            // CRUZ
            // -------------------------
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;

            // -------------------------
            // OCTAEDRO (LOSANGO)
            // Distância Manhattan
            // -------------------------
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // =====================================================
    // 4. SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO
    // =====================================================

    // ----------- APLICANDO CONE -----------
    int origem_linha = 2;
    int origem_coluna = 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            // Verificação de limites
            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (cone[i][j] == 1)
                    tabuleiro[linha_tab][coluna_tab] = 5;
            }
        }
    }

    // ----------- APLICANDO CRUZ -----------
    origem_linha = 7;
    origem_coluna = 7;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (cruz[i][j] == 1)
                    tabuleiro[linha_tab][coluna_tab] = 5;
            }
        }
    }

    // ----------- APLICANDO OCTAEDRO -----------
    origem_linha = 5;
    origem_coluna = 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (octaedro[i][j] == 1)
                    tabuleiro[linha_tab][coluna_tab] = 5;
            }
        }
    }

    // =====================================================
    // 5. EXIBIÇÃO FINAL DO TABULEIRO (0, 3, 5)
    // =====================================================

    printf("\nTABULEIRO FINAL\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
