#include <stdio.h>

void main() {
    float prize = 780.0;
    float first_pct = 0.46, sec_pct = 0.32;
    float first_prize = prize*first_pct;
    float second_prize = prize*sec_pct;
    float third_prize = prize - first_prize - second_prize;
    printf("Primeiro ganhador: R$ %.2f\n", first_prize);
    printf("Segundo ganhador: R$ %.2f\n", second_prize);
    printf("Terceiro ganhador: R$ %.2f\n", third_prize);
}