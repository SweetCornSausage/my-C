#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node;
typedef struct Node *List;
typedef struct Node *Pointer;
struct Node
{
    ElementType Element;
    Pointer Next;
};

List MakeEmpty(List L)
{
    // if (L != NULL)
    //     DeleteList(L);
    L = malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
}

void Insert(ElementType X, List L, Pointer P)
{
    Pointer TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void PrintList(List L)
{
    if (L == NULL)
    {
        printf("空表");
        return;
    }
    Pointer p = L;
    while (p->Next != NULL && p->Next != L)
    {
        p = p->Next;
        printf("%d ", p->Element);
        if (p->Next == L)
            printf("循环结束");
    }
    printf("\n");
}

void SwapNextTwo(Pointer BP, List L)
{
    Pointer P, AP;
    P = BP->Next;
    AP = P->Next;
    P->Next = AP->Next;
    BP->Next = AP;
    AP->Next = P;
}

void TurnAround(List L)
{
    Pointer p = L;
    Pointer last = NULL;
    while (last != L->Next->Next)
    {
        while (p->Next->Next != last)
        {
            SwapNextTwo(p, L);
            p = p->Next;
        }
        last = p->Next;
        p = L;
    }
}

void Merge(List L1, List L2)
{
    Pointer p1 = L1;
    Pointer p2 = L2;
    while (p1->Next != L1)
    {
        p1 = p1->Next;
    }
    while (p2->Next != L2)
    {
        p2 = p2->Next;
    }
    p1->Next = L2->Next;
    free(L2);
    p2->Next = L1;
}

List AddHead(List L)
{
    Pointer tmp = malloc(sizeof(struct Node));
    tmp->Next = L;
    Pointer p = L;
    while (p->Next != NULL)
    {
        p = p->Next;
    }
    p->Next = tmp;
    return tmp;
}

int main(){
    List L;
    Pointer P;
    int i;
    L = MakeEmpty(NULL);
    P = L;
    P->Element = -1;
    for (i = 0; i < 10; i++)
    {
        Insert(i, L, P);
        P = P->Next;
    }
    printf("first:\n");
    PrintList(L);
    L=AddHead(L);
    printf("last:\n");
    PrintList(L);
}