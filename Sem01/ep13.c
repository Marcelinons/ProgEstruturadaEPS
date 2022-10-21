#include <stdio.h>

/// @brief Receives three floats (the sides of a triangle) and prints wether
/// it is a equilateral triangle, a scalene triangle, a isosceles triangle or
/// if it is not a triangle a all.
void main() {
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Entrada INVALIDA!\n");
    } else if (a == b && a == c) {
        printf("Triangulo EQUILATERO!\n");
    } else if (a != b && a != c && b != c) {
        printf("Triangulo ESCALENO!\n");
    } else {
        printf("Triangulo ISOSCELES!\n");
    }
}