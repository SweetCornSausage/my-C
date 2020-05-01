
#include <stdio.h>
#include <stdlib.h>
#define InitSize (100)
#define Increasement (10)
typedef int ElementType;
struct List_Ar
{
    ElementType *Arr;
    int Capacity;
    int Size;
};
typedef struct List_Ar *List;

int InitList(List L)
{
    L->Arr = malloc(InitSize * sizeof(ElementType));
    if (L->Arr == NULL)
        exit(0);
    L->Capacity = InitSize;
    L->Size = 0;
    return 1;
}

int GetElem(List L, int i, ElementType *e)
{
    if (i < 1 || i > L->Size)
        return 0;
    *e = L->Arr[i - 1];
    return 1;
}

int NextElem(List L, ElementType e, ElementType *next_e)
{
    if (L->Size < 2)
        return 0;
    int i = 1;
    while (i <= L->Size && L->Arr[i] != e)
    {
        i++;
    }
    if (i = L->Size + 1)
        return 0;
    *next_e = L->Arr[i];
    return 1;
}
