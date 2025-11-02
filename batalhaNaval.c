#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se o navio cabe no tabuleiro e se não há sobreposição
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                         int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (horizontal ? 0 : i);
        int c = coluna + (horizontal ? i : 0);

        // Verifica se está dentro dos limites do tabuleiro
        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO) {
            return 0; // Não pode posicionar
        }

        // Verifica se a posição já está ocupada por outro navio
        if (tabuleiro[l][c] != AGUA) {
            return 0; // Sobreposição detectada
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha, int coluna, int horizontal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + (horizontal ? 0 : i);
        int c = coluna + (horizontal ? i : 0);
        tabuleiro[l][c] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais definidas no código
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;
    int linhaVertical = 5;
    int colunaVertical = 6;

    // Posiciona navio horizontalmente
    if (podePosicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 1)) {
        posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 1);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    // Posiciona navio verticalmente
    if (podePosicionarNavio(tabuleiro, linhaVertical, colunaVertical, 0)) {
        posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 0);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
