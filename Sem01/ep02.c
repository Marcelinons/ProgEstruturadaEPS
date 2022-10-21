#include <stdio.h>

/// @brief Receives 3 ints and prints out some fictional information about it.
void main() {
    int sony, dell, tosh;
    scanf("%d%d%d", &sony, &dell, &tosh);
    int ttl = sony + dell + tosh;
    printf("%d notebook(s) da Sony\n%d notebook(s) da Dell\n", sony, dell);
    printf("%d notebook(s) da Toshiba\nTotal de %d notebooks", tosh, ttl);
}