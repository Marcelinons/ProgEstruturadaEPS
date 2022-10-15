#include <stdio.h>

/* EP04_05
 *
 * Creates a Athlete type structure to storage athletes' names, ages and
 * heights. Reads from the keyboard n athletes' info, and prints the ages in a
 * crescent order.
 *
 * -Nicolas M. 14-10-2022
 */

/// @brief Stores athlete's name, age and height.
typedef struct TAthData
{
    char name[50];
    int age;
    float height;
} Athlete;

/// @brief Reads name, age and height of n athletes. Stores the values inside
/// structures.
/// @param n Number of athletes;
/// @param athletes Pointer to a list of n Athlete structures;
/// @return 1.
int ReadAthData(int numAth, Athlete *athletes);

/// @brief Sort a given int vector of n elements in de-crescent order;
/// @param n Number of elements in the list;
/// @param v Pointer to a list of n elements;
/// @return 1.
int Sorted(int n, int *v);

/// @brief Stores athletes' ages inside a de-crescent int vector
/// @param numAth Number of athletes;
/// @param ages Pointer to int vector of size numAth;
/// @param athletes Pointer to a list of numAth Athlete structures;
/// @return 1.
int GetAgeVector(int numAth, int *ages, Athlete *athletes);


int ReadAthData(int numAth, Athlete *athletes)
{
    for (int i = 0; i < numAth; i++)
    {
        scanf("%s ", athletes[i].name);
        scanf("%d ", &athletes[i].age);
        scanf("%f", &athletes[i].height);
    };
    return 1;
};

int Sorted(int n, int *v)
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (v[i] < v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            };
        };
    };
    return 1;
};

int GetAgeVector(int numAth, int *ages, Athlete *athletes)
{
    for (int i = 0; i < numAth; i++)
    {
        ages[i] = athletes[i].age;
    };
    Sorted(numAth, ages);
    return 1;
};

int PrintVet(int n, int *v)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    };
    printf("\n");
};

int main()
{
    int numAth = 4;
    int athAges[numAth];

    Athlete athletes[numAth];

    Athlete *athletesPointer = athletes;

    ReadAthData(numAth, athletesPointer);
    GetAgeVector(numAth, athAges, athletesPointer);
    PrintVet(numAth, athAges);

    return 1;
};
