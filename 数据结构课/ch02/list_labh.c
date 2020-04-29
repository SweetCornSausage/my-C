#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node;
typedef struct Node *Pointer;
typedef struct Node *List;
List MakeEmpty(List L);
void Insert(ElementType X, List L, Pointer P);
void DeleteList(List L);
void PrintList(List L);
void Sort(List L);
List Merge(List L1, List L2);

struct Node
{
    ElementType Element;
    Pointer Next;
};

List MakeEmpty(List L)
{
    if (L != NULL)
        DeleteList(L);
    L = malloc(sizeof(struct Node));
    if (L == NULL)
        exit(1);
    L->Next = NULL;
    return L;
}

void Insert(ElementType X, List L, Pointer P)
{
    Pointer TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        exit(1);
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Pointer P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

void PrintList(List L)
{
    if (L->Next == NULL)
    {
        printf("空表\n");
        return;
    }
    Pointer p = L;
    printf("如下:\n");
    while (p->Next != NULL && p->Next != L)
    {
        p = p->Next;
        printf("%d ", p->Element);
        if (p->Next == L)
            printf("循环结束");
    }
    printf("\n");
}

static void SwapNextTwo(Pointer BP, List L)
{
    Pointer P, AP;
    P = BP->Next;
    AP = P->Next;
    if (P->Element < AP->Element)
        return;
    P->Next = AP->Next;
    BP->Next = AP;
    AP->Next = P;
}

void Sort(List L)
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

List Merge(List L1, List L2)
{
    List L3 = MakeEmpty(NULL);
    Pointer p1, p2, p3;
    p1 = L1->Next;
    p2 = L2->Next;
    p3 = L3;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->Element < p2->Element)
        {
            Insert(p1->Element, L3, p3);
            p1 = p1->Next;
        }
        else
        {
            Insert(p2->Element, L3, p3);
            p2 = p2->Next;
        }
        p3 = p3->Next;
    }
    if (p1 == NULL)
    {
        while (p2 != NULL)
        {
            Insert(p2->Element, L3, p3);
            p2 = p2->Next;
            p3 = p3->Next;
        }
    }
    if (p2 == NULL)
    {
        while (p1 != NULL)
        {
            Insert(p1->Element, L3, p3);
            p1 = p1->Next;
            p3 = p3->Next;
        }
    }
    return L3;
}