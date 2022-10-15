#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* EP04_01
 *
 * Cria uma estrutura TypeTwoCoords que armazena as quatro coordenadas (x e y)
 * de dois pontos. Calcula e printa a distancia entre os dois pontos.
 * - Nicolas M. 13-10-2022
*/

/// @brief Armazena as 4 coordenadas de dois pontos cartesianos
typedef struct TypeTwoCoords {
    int aX;
    int aY;
    int bX;
    int bY;
} TwoCoords;

/// @brief Calcula a distancia entre dois dados pontos cartesianos.
/// @param aX Coordenada x do Ponto A;
/// @param aY Coordenada y Ponto A;
/// @param bX Coordenada x do Ponto B;
/// @param bY Coordenada y Ponto B;
/// @return Float - distância entre os dois pontos.
float CalcDist(int aX, int aY, int bX, int bY);


float CalcDisc(int aX, int aY, int bX, int bY) {
    float distEuclid = sqrt(pow(aX-bX, 2) + pow(aY-bY, 2));
    return distEuclid;
};

int main() {
    TwoCoords coords;
    scanf("%d", &coords.aX);
    scanf("%d", &coords.aY);
    scanf("%d", &coords.bX);
    scanf("%d", &coords.bY);

    float distancia = CalcDisc(coords.aX, coords.aY, coords.bX, coords.bY);

    printf("%.1f", distancia);
};
