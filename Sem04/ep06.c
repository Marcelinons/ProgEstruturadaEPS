#include <stdio.h>
#include <math.h>

/* EP04_06
 *
 * Recebe do teclado as coordenadas de 4 pontos euclidianos (retangulo) e
 * mostra o tamanho da diagonal BD:
 *
 * 1 B - - - - - - C 2
 *   |             |
 *   |             |
 *   |             |
 * 0 A - - - - - - D 3
 *
 * Caso os pontos nao formem um retangulo, exibe uma mensagem de erro e retorna
 * 0.
 *
 * - Nicolas M. 16-10-2022
*/

/// @brief Armazena as coordenadas x e y de um ponto euclidiano.
struct Point
{
    float x;
    float y;
};

/// @brief Representa um quadrilatero: 4 pontos euclidianos.
typedef struct Quadrilateral
{
    struct Point p[4];
} Retangulo;

/// @brief Calcula a diagonal de um dado retangulo (struct Quadrilateral).
/// @param ret Pointeiro para struct Quadrilateral.
/// @return 1.
float CalcDiag(Retangulo *ret);

/// @brief Calcula a distancia entre dois dados pontos euclidianos.
/// @param aX Coordenada x do ponto A;
/// @param aY Coordenada y do ponto A;
/// @param bX Coordenada x do ponto B;
/// @param bY Coordenada y do ponto B;
/// @return Distancia entre os dois pontos.
float CalcTPDist(float aX, float aY, float bX, float bY);

/// @brief Verifica se os dados pontos da struct Retangulo formam de fato um
/// retangulo.
/// @param ret Ponteiro para uma struct do tipo Retangulo;
/// @return 1 se os pontos formarem um retangulo; 0 caso contrario.
int IsARectangle(Retangulo *ret);

float CalcDiag(Retangulo *ret)
{
    for (int i = 0; i < 4; i++)
    {
        scanf("%f ", &ret -> p[i].x);
        scanf("%f", &ret -> p[i].y);
    };

    if (!(IsARectangle(ret)))
    {
        printf("ERRO: Os pontos nao formam um retangulo.\n");
        return 0;
    };

    float distBD = CalcTPDist(
        ret -> p[1].x, ret -> p[1].y, ret -> p[3].x, ret -> p[3].y);

    return distBD;
};

float CalcTPDist(float aX, float aY, float bX, float bY)
{
    float dist = sqrt(pow(aX-bX, 2) + pow(aY-bY, 2));
    return dist;
};

int IsARectangle(Retangulo *ret)
{
    float distList[4];
    // pos 0: dist AB; pos 1: dist BC; pos 2: dist CD; pos 3: dist AD
    for (int i = 0; i < 3; i++)
    {
        float distP1P2 = CalcTPDist(
            ret -> p[i].x, ret -> p[i].y, ret -> p[i+1].x, ret -> p[i+1].y);
        distList[i] = distP1P2;
    };
    distList[3] = CalcTPDist(
        ret -> p[0].x, ret -> p[0].y, ret -> p[3].x, ret -> p[3].y);

    if (distList[0] != distList[2] || distList[1] != distList[3])
    {
        return 0;
    };
    return 1;
};

int main ()
{
    Retangulo ret;

    Retangulo *retPtr = &ret;

    float diag = CalcDiag(retPtr);
    printf("%.2f\n", diag);

    return 1;
};
