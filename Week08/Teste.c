#include "StaticList.c"

/* Code to test the methods of StaticList.c (someday I'll finish) */

void main() {
    
    List *li = NULL;
    li = CreateList();
    InsertNewElem(li, 5);
    InsertNewElem(li, 10);
    InsertNewElem(li, 14);
    printf("List in the beginning: ");
    PrintList(li);
    SwitchInts(li, 14, 10);
    printf("List after switching 2 element's position: ");
    PrintList(li);


    List *li2 = CreateList();
    List *li3 = CreateList();

    InsertNewElem(li2, 3);
    InsertNewElem(li2, 5);
    InsertNewElem(li3, 6);
    InsertNewElem(li3, 14);

    li = ConcatLists(li2, li3);
    printf("List after concatenating li2 and li3: ");
    PrintList(li);

    FreeMemory(li);
    
}