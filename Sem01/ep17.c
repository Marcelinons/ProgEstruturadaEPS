//#include "sequencia.h" // Moodle's library;
#include <stdio.h>

/// Recebe uma temperatura em Fahrenheit e a retorna convertida para Celsius.
float calcular_c(float temp);

float calcular_c(float temp) {
    float celsius = (temp-32.0)*(5.0/9.0);
    return celsius;
}