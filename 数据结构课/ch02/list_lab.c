#include "list_labh.c"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    List L1;
    Pointer P;
    int i;
    L1 = MakeEmpty(NULL);
    P = L1;
    srand(56);
    for (i = 0; i < 10; i += 2)
    {
        Insert(rand() % 10, L1, P);
        P = P->Next;
    }
    Sort(L1);
    PrintList(L1);
    List L2;
    L2 = MakeEmpty(NULL);
    P = L2;
    srand(rand());
    for (i = 1; i < 10; i += 2)
    {
        Insert(rand() % 10, L2, P);
        P = P->Next;
    }
    Sort(L2);
    PrintList(L2);
    List L3 = Merge(L1, L2);
    PrintList(L3);
}