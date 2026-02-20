#include <stdio.h>
#include <stdlib.h> // para abs()

#define TAM 10
#define HAB 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tab[TAM][TAM]) {

    printf("\nTABULEIRO FINAL\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tab[i][j] == 0)
                printf("~ ");      // Água
            else if (tab[i][j] == 3)
                printf("N ");      // Navio
            else if (tab[i][j] == 5)
                printf("* ");      // Área afetada
        }
        printf("\n");
    }
}

int main() {

    int tabuleiro[TAM][TAM];

    // Inicializa com água
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // Exemplo simples de navio
    tabuleiro[4][4] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[4][6] = 3;

    // =============================
    // MATRIZES DE HABILIDADE
    // =============================

    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    int centro = HAB / 2;

    // Construção dinâmica das habilidades
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            // CONE (aponta para baixo)
            if (j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;

            // CRUZ
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;

            // OCTAEDRO (losango)
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // =============================
    // SOBREPOSIÇÃO DAS HABILIDADES
    // =============================

    int origem_linha = 2;
    int origem_coluna = 2;

    // Exemplo aplicando CONE no tabuleiro
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            // Verificação de limite
            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (cone[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    // Aplicando CRUZ em outro ponto
    origem_linha = 7;
    origem_coluna = 7;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (cruz[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    // Aplicando OCTAEDRO
    origem_linha = 5;
    origem_coluna = 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            int linha_tab = origem_linha + i - centro;
            int coluna_tab = origem_coluna + j - centro;

            if (linha_tab >= 0 && linha_tab < TAM &&
                coluna_tab >= 0 && coluna_tab < TAM) {

                if (octaedro[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
    }

    imprimirTabuleiro(tabuleiro);

    return 0;
}
