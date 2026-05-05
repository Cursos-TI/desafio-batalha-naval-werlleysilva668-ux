#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {

    int tabuleiro[TAM][TAM];

    // ===== Inicializa tabuleiro com 0 =====
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===== Coordenadas iniciais =====
    // Horizontal
    int lH = 1, cH = 2;

    // Vertical
    int lV = 5, cV = 0;

    // Diagonal principal (↘)
    int lD1 = 0, cD1 = 0;

    // Diagonal secundária (↙)
    int lD2 = 0, cD2 = 9;

    // ===== NAVIO HORIZONTAL =====
    if (cH + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[lH][cH + i] != 0) {
                printf("Erro: sobreposição horizontal\n");
                return 1;
            }
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[lH][cH + i] = 3;
        }
    } else {
        printf("Erro: horizontal fora do tabuleiro\n");
        return 1;
    }

    // ===== NAVIO VERTICAL =====
    if (lV + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[lV + i][cV] != 0) {
                printf("Erro: sobreposição vertical\n");
                return 1;
            }
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[lV + i][cV] = 3;
        }
    } else {
        printf("Erro: vertical fora do tabuleiro\n");
        return 1;
    }

    // ===== NAVIO DIAGONAL (↘) =====
    if (lD1 + NAVIO <= TAM && cD1 + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[lD1 + i][cD1 + i] != 0) {
                printf("Erro: sobreposição diagonal 1\n");
                return 1;
            }
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[lD1 + i][cD1 + i] = 3;
        }
    } else {
        printf("Erro: diagonal 1 fora do tabuleiro\n");
        return 1;
    }

    // ===== NAVIO DIAGONAL (↙) =====
    if (lD2 + NAVIO <= TAM && cD2 - NAVIO + 1 >= 0) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[lD2 + i][cD2 - i] != 0) {
                printf("Erro: sobreposição diagonal 2\n");
                return 1;
            }
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[lD2 + i][cD2 - i] = 3;
        }
    } else {
        printf("Erro: diagonal 2 fora do tabuleiro\n");
        return 1;
    }

    // ===== EXIBE O TABULEIRO =====
    printf("\nTabuleiro Batalha Naval:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}