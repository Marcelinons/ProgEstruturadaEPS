#include "DynamicList.c"

int main()
{
    int num = 0, i, pairs, largest, sum, largPos = 1;

    float media;
    List *li = CreateList();

    for (i = 0; i < 5; i++) {
        scanf("%d", &num);
        InsertNewElem(li, num);
    }
    printf("\nFirst 5 elements of the list: ");
    Head(li);
    pairs = CountPairElems(li);
    printf("Number of pair elements among these: %d\n", pairs);
    media = MeanFFive(li);
    printf("Mean of these elements: %.2f\n", media);
    largest = LargestAmongFFive(li, &largPos);
    printf("Largest number among these elements: %d at position %d\n",
        largest, largPos);
    sum = SumFFive(li);
    printf("Sum of these elements: %d\n", sum);

    FreeMemory(li);
    return 0;
}
