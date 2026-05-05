#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro
#define NAVIO 3       // Tamanho dos navios

int main() {

    // Matriz do tabuleiro
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vetores representando os navios
    int navio_horizontal[NAVIO] = {3, 3, 3};
    int navio_vertical[NAVIO] = {3, 3, 3};

    // Coordenadas iniciais (definidas no código)
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 5, colunaV = 1; // Navio vertical

    // ===== Validação do navio horizontal =====
    if (colunaH + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                printf("Erro: Sobreposição no navio horizontal!\n");
                return 1;
            }
        }

        // Posiciona o navio horizontal
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
        }
    } else {
        printf("Erro: Navio horizontal fora do tabuleiro!\n");
        return 1;
    }

    // ===== Validação do navio vertical =====
    if (linhaV + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                printf("Erro: Sobreposição no navio vertical!\n");
                return 1;
            }
        }

        // Posiciona o navio vertical
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
        }
    } else {
        printf("Erro: Navio vertical fora do tabuleiro!\n");
        return 1;
    }

    // ===== Exibe o tabuleiro =====
    printf("\nTabuleiro Batalha Naval:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}