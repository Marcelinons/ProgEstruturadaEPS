#include <stdio.h>

/// @brief Calculate the area of a given rectangle;
/// @param b Rectangle's base size;
/// @param h Rectangle's height;
/// @return The area of the rectangle.
float calc_area(float b, float h);

float calc_area(float b, float h) {
    float area = b*h;
    return area;
}

/// @brief Checks if given sizes can form a rectangle (and not a square),
/// calculates its areas and prints what rectangle have the largest area.
void main() {
    float base_a, alt_a, base_b, alt_b;
    scanf("%f%f%f%f", &base_a, &alt_a, &base_b, &alt_b);
    if (base_a == alt_a || base_b == alt_b) {
        printf("Os dados informados nao formam o retangulo A ou o retangulo B!\n");
    } else {
        float area_a = calc_area(base_a, alt_a);
        float area_b = calc_area(base_b, alt_b);
        printf("A area do retangulo A eh: %f\nA area do retangulo B eh: %f\n", area_a, area_b);
        if (area_a == area_b) {
            printf("A area do retangulo A eh igual ao do retangulo B!\n");
        } else if (area_a < area_b) {
            printf("A area do retangulo B eh maior do que a do retangulo A!\n");
        } else {
            printf("A area do retangulo A eh maior do que a do retangulo B!\n");
        }
    }
}