#include <stdio.h>

int main() {
    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int colunaH = 2, linhaH = 1;
    int colunaV = 5, linhaV = 7;
    int navio = 3;
    int numeroLinha = 1;

    //Inicializando o tabuleiro (Matriz 10x10)
    int tabuleiro[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionando o navio horizontal (3 casas)
    // Verifica se cabe no tabuleiro
    if (colunaH + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navio;
        }
    } else {
        printf("Erro: o navio horizontal não cabe no tabuleiro!\n");
    }

    // Posicionando o navio vertical (3 casas)
    //Verifica se tem sobreposição
    // Verifica se cabe no tabuleiro
    if (colunaV + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            //Garantindo que não vai ter sobreposição
            if (tabuleiro[linhaV + i][colunaV] == 0){
                tabuleiro[linhaV + i][colunaV] = navio;
            } else{
                printf("Aviso! Tentativa de sobreposisção detectada, altere os navios de posição.\n");
                return 0;
            }
        } 
    } else {
        printf("Erro: o navio horizontal não cabe no tabuleiro!\n");
    }

    //Exibindo o tabuleiro
    printf("\n=====  TABULEIRO DE BATALHA NAVAL   =====\n\n");
    for(int i = 0; i < 10; i++){
        printf("   %c", linha[i]);
    } 
    printf("\n\n");    
    for(int i = 0; i < 10; i ++){
        if(numeroLinha != 10){
            printf(" %d", numeroLinha);
            numeroLinha = numeroLinha + 1;
        } else{
            printf("%d", numeroLinha);
        }
        
        for(int j = 0; j < 10; j++){
            printf("  %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
