#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// ===== FUNÇÃO PARA MOSTRAR TABULEIRO =====
void mostrarTabuleiro(int tab[TAM][TAM]) {
    printf("\nTABULEIRO:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tab[i][j] == AGUA)
                printf("~ "); // água
            else if (tab[i][j] == NAVIO)
                printf("N "); // navio
            else if (tab[i][j] == HABILIDADE)
                printf("* "); // habilidade
        }
        printf("\n");
    }
}

// ===== SOBREPOR HABILIDADE NO TABULEIRO =====
void aplicarHabilidade(int tab[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int origemL, int origemC) {

    int meio = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (hab[i][j] == 1) {

                int l = origemL + (i - meio);
                int c = origemC + (j - meio);

                // Verifica limite do tabuleiro
                if (l >= 0 && l < TAM && c >= 0 && c < TAM) {

                    // Só marca se não for navio
                    if (tab[l][c] == AGUA)
                        tab[l][c] = HABILIDADE;
                }
            }
        }
    }
}

int main() {

    int tabuleiro[TAM][TAM];

    // ===== INICIALIZA TABULEIRO =====
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // ===== NAVIOS (exemplo simples) =====
    for (int i = 0; i < 3; i++)
        tabuleiro[2][i + 2] = NAVIO;

    // ===== MATRIZES DE HABILIDADE =====
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int meio = TAM_HAB / 2;

    // ===== CONE (▼) =====
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            // largura aumenta conforme desce
            if (j >= meio - i && j <= meio + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // ===== CRUZ (✚) =====
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // ===== OCTAEDRO (LOSANGO ◊) =====
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int dist = abs(i - meio) + abs(j - meio);

            if (dist <= meio)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ===== APLICAR HABILIDADES =====
    aplicarHabilidade(tabuleiro, cone, 5, 5);
    aplicarHabilidade(tabuleiro, cruz, 1, 7);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);

    // ===== MOSTRAR RESULTADO =====
    mostrarTabuleiro(tabuleiro);

    return 0;
}