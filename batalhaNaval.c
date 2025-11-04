#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linhaH = 1, colunaH = 2;
    int linhaV = 7, colunaV = 5;
    int linhaD1 = 7, colunaD1 = 7;
    int linhaD2 = 3, colunaD2 = 1;
    int navio = 3;
    int numeroLinha = 1;

    //Inicializando o tabuleiro (Matriz 10x10)
    int tabuleiro[LINHAS][COLUNAS];
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
        return 0;
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
        return 0;
    }


    // Posicionando o navio diagonal 1 (3 casas)
    //Verifica se tem sobreposição
    // Verifica se cabe no tabuleiro
    if(linhaD1 + 3 <= 10){
        if(colunaD1 + 3 <= 10){
            for(int i = 0; i < 3; i++){
                    if(tabuleiro[linhaD1 + i][colunaD1 + i] == 0){
                        tabuleiro[linhaD1 + i][colunaD1 + i] = navio;
                    } else{
                        printf("Aviso! Tentativa de sobreposisção detectada, altere os navios de posição.\n");
                        return 0;
                    }
                }
            } else{
                printf("Erro: o navio diagonal não cabe no tabuleiro!\n");
                return 0;
            }
        } else{
            printf("Erro: o navio diagonal não cabe no tabuleiro!\n");
            return 0;
        }

    // Posicionando o navio diagonal 2 (3 casas)
    //Verifica se tem sobreposição
    // Verifica se cabe no tabuleiro
    if(linhaD2 + 3 <= 10){
        if(colunaD2 + 3 <= 10){
            for(int i = 0; i < 3; i++){
                    if(tabuleiro[linhaD2 + i][colunaD2 + i] == 0){
                        tabuleiro[linhaD2 + i][colunaD2 + i] = navio;
                    } else{
                        printf("Aviso! Tentativa de sobreposisção detectada, altere os navios de posição.\n");
                        return 0;
                    }
                }
            } else{
                printf("Erro: o navio diagonal não cabe no tabuleiro!\n");
                return 0;
            }
        } else{
            printf("Erro: o navio diagonal não cabe no tabuleiro!\n");
            return 0;
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
