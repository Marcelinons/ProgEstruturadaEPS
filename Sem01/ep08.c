#include <stdio.h>
#include <math.h>

/// Calcula a hipotenusa usando pitágoras com base em dois catetos, a e b.
float hipotenusa(float a, float b);

float hipotenusa(float a, float b) {
    float h = sqrt(a*a + b*b);
    return h;
}

void main() {
    float a, b;
    scanf("%f%f", &a, &b);
    float h = hipotenusa(a, b);
    printf("A hipotenusa eh: %f", h);
}