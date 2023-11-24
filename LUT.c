#include "LUT.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculateR(double T) {
    T+=273.15;
    double T0 = 25+273.15, B = 3394, R0 = 10000;
    double x = B * (1.0 / T - 1.0 / T0);
    double result = R0 * exp(x);
    return result;
}


double** SetLut(double T_Min, double T_Max, int precision) {
    double temperature = T_Min;
    double tension = 0;
    double At = (T_Max - T_Min)/precision;
    double Av = 5.0/precision;
    double** Lut = (double**)malloc((precision+1) * sizeof(double*));

    for (int i = 0; i <= precision; i++) {
        Lut[i] = (double*)malloc(3 * sizeof(double));
    }

    for (int i = 0; i <= precision; i++) {
        Lut[i][0] = temperature;
        Lut[i][1] = calculateR(temperature);
        Lut[i][2] = tension;        
        temperature +=At;
        tension += Av;
    }

    return Lut;
}

void FreeLut(double** matriz, int size) {
    for (int i = 0; i <= size; i++) {
        free(matriz[i]);
    }
    free(matriz);
}



