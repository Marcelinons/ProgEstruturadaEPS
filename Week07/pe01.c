#include <stdio.h>

/* EP07_01
 *
 * Prints the size (in bytes) of the int, char, float and double types.
 * 
 * NicolasMSilva <03/11/2022>
*/

void main () {
    printf("Char: %d\nInt: %d\nFloat: %d\nDouble: %d\n", (int)sizeof(char), 
    (int)sizeof(int), (int)sizeof(float), (int)sizeof(double));
}