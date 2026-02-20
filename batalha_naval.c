#include <stdio.h>
#include <stdlib.h> // para abs()

#define TAM 10
#define HAB 5

int main() {

    // =====================================================
    // 1. DECLARAÇÃO E INICIALIZAÇÃO DO TABULEIRO
    // =====================================================

    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // 0 = Água
        }
    }

    // =====================================================
    // 2. POSICIONAMENTO DE NAVIOS (VALOR 3)
    // =====================================================

    // Navio horizontal
    for (int j = 3; j <= 5; j++) {
        tabuleiro[6][j] = 3;
    }

    // Navio vertical
    for (int i = 1; i <= 3; i++) {
        tabuleiro[i][8] = 3;
    }

    // =====================================================
    // 3. CRIAÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE
    // =====================================================

    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            // -------------------------
            // CONE (apontando para baixo)
            // Expande horizontalmente conforme desce
            // -------------------------
            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;

            // -------------------------
            // CRUZ
            // Linha central e coluna central
            // -------------------------
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;

            // -------------------------
            // OCTAEDRO (LOSANGO)
            // Distância Manhattan <= centro
            // -------------------------
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // =====================================================
    // 4. FUNÇÃO DE SOBREPOSIÇÃO COM VALIDAÇÃO
    // =====================================================

    int origem_linha, origem_coluna;

    // ---------- CONE ----------
    origem_linha = 2;
    origem_coluna = 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (cone[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] != 3)
                    tabuleiro[linha_tab][coluna_tab] = 5; // 5 = Habilidade
            }
        }
    }

    // ---------- CRUZ ----------
    origem_linha = 7;
    origem_coluna = 7;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (cruz[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] != 3)
                    tabuleiro[linha_tab][coluna_tab] = 5;
            }
        }
    }

    // ---------- OCTAEDRO ----------
    origem_linha = 4;
    origem_coluna = 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (octaedro[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] != 3)
                    tabuleiro[linha_tab][coluna_tab] = 5;
            }
        }
    }

    // =====================================================
    // 5. EXIBIÇÃO DO TABULEIRO (COM CONDICIONAIS)
    // =====================================================

    printf("\nTABULEIRO FINAL\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0)
                printf("0 ");
            else if (tabuleiro[i][j] == 3)
                printf("3 ");
            else if (tabuleiro[i][j] == 5)
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
