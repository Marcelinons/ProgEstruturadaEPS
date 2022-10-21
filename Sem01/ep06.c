#include <stdio.h>

/// @brief  Receives a int and prints out its successor and predecessor
void main() {
    int num;
    scanf("%d", &num);
    printf("Antecessor de %d eh: %d\nSucessor de %d eh: %d", num, num-1,
                                                             num, num+1);
}