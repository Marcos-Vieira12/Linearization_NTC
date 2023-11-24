#include <stdio.h>
#include "LUT.h"
#include <math.h>

int main(){
double T_Min, T_max;
int precision;

printf("Digite a temperatura minima, em celsius, a temperatura máxima, em celsius,\n e a quantidade de linhas(quanto maior, maior a precisão)\n");
scanf("%lf %lf %d", &T_Min, &T_max, &precision);
double** Lut = SetLut(T_Min,T_max,precision);


FILE *arquivo = fopen("saida.txt", "w");
    
    // Verificando se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1; // Sair do programa com código de erro
    }

    // Escrevendo a matriz no arquivo
    for (int i = 0; i <= precision; i++) {
        fprintf(arquivo, "%f %f \n", Lut[i][1], Lut[i][2]);
    }

    // Fechando o arquivo
    fclose(arquivo);

    // Liberando a memória alocada para a matriz
    FreeLut(Lut, precision);

    return 0;
}

