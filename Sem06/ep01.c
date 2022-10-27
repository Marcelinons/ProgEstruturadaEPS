#include <stdio.h>

/* EP06_01
 * 
 * Imprime o valor das variaveis x, y e z antes e depois de serem alteradas com
 * ponteiros.
 * 
 * NicolasMSilva <27/10/2022>
*/

int main () {
    int x = 3;
    float y = 3.4;
    char z = 'A';

    int* xPointer = NULL;
    float* yPointer = NULL;
    char* zPointer = NULL;
    
    xPointer = &x;
    yPointer = &y;
    zPointer = &z;

    printf("Antes:\nx = %d\ny = %f\nz = %c\n", *xPointer, *yPointer, *zPointer);

    scanf("%d %f %c", xPointer, yPointer, zPointer);

    printf("Depois:\nx = %d\ny = %f\nz = %c", *xPointer, *yPointer, *zPointer);

    return 1; 
}