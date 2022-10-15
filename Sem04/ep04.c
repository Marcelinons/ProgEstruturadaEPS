#include <stdio.h>
#include <string.h>

/* EP04_04
 *
 * - Nicolas M. 14-10-2022
*/

/// @brief Stores athlete's name, age and height.
typedef struct TAthletesData {
    char name[50];
    int age;
    float height;
} Athlete;

/// @brief Reads name, age and height of n athletes. Stores the values inside
/// structures.
/// @param n Number of athletes;
/// @param athletes Pointer to a list of n Athlete structures;
/// @return 1.
int ReadAthData(int n, Athlete *athletes);

/// @brief Prints oldest athlete's name. Returns correspondent index.
/// @param n Number of athletes;
/// @param athletes Pointer to a list of n Athlete structures;
/// @return Oldest athlete's index on the structure list.
int GetOldestAth(int n, Athlete *athletes);

/// @brief Prints highest athlete's name. Returns correspondent index.
/// @param n Number of athletes;
/// @param athletes Pointer to a list of n Athlete structs;
/// @return Highest athlete's index on the structure list.
int GetHighestAth(int n, Athlete *athletes);


int ReadAthData(int n, Athlete *athletes) {

    for (int i = 0; i < n; i++) {

        scanf("%s ", athletes[i].name);
        scanf("%d ", &athletes[i].age);
        scanf("%f", &athletes[i].height);
    };
    return 1;
};

int GetOldestAth(int n, Athlete *athletes) {
    int highestAge = athletes[0].age, index = 0;
    for (int i = 0; i < n; i++) {
        if (athletes[i].age > highestAge) {
            highestAge = athletes[i].age;
            index = i;
        };
    };
    printf("Mais velho: %s\n", athletes[index].name);
    return index;
};

int GetHighestAth(int n, Athlete *athletes) {
    float highest = athletes[0].height;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (athletes[i].height > highest) {
            highest = athletes[i].height;
            index = i;
        };
    };
    printf("Mais alto: %s\n", athletes[index].name);
    return index;
};

int main() {
    int numAthletes = 4;

    Athlete athletes[numAthletes];

    Athlete *athPointer = athletes;

    ReadAthData(numAthletes, athletes);
    GetHighestAth(numAthletes, athletes);
    GetOldestAth(numAthletes, athletes);

    return 1;
};
