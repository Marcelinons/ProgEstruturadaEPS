#include <stdio.h>

/// @brief Formats a given day, month and year and prints it.
void main() {
    int dia, mes, ano;
    scanf("%d%d%d", &dia, &mes, &ano);
    printf("%d/%d/%d", dia, mes, ano);
}