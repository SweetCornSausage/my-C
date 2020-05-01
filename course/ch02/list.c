#include "list.h"
#include "../include/list.c"
#include <stdio.h>
#include <stdlib.h>

void PrintList(List L)
{
    if (L == NULL)
    {
        printf("空表");
        return;
    }
    Position p = L;
    while (p->Next != NULL && p->Next != L)
    {
        p = p->Next;
        printf("%d ", p->Element);
        if (p->Next == L)
            printf("循环结束");
    }
    printf("\n");
}

void SwapNextTwo(Position BP, List L)
{
    Position P, AP;
    P = BP->Next;
    AP = P->Next;
    P->Next = AP->Next;
    BP->Next = AP;
    AP->Next = P;
}

void TurnAround(List L)
{
    Position p = L;
    Position last = NULL;
    while (last != L->Next->Next)
    {
        while (p->Next->Next != last)
        {
            SwapNextTwo(p, L);
            p = p->Next;
        }
        PrintList(L);
        last = p->Next;
        p = L;
    }
}

void Merge(List L1, List L2)
{
    Position p1 = L1;
    Position p2 = L2;
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
    //L2 = NULL;
    p2->Next = L1;
}

List AddHead(List L){
    Position tmp=malloc(sizeof(struct Node));
    tmp->Next = L;
    Position p = L;
    while (p->Next !=NULL)
    {
        p = p->Next;
    }
    p->Next = tmp;
    return tmp;
}

int main()
{
    List L;
    Position P;
    int i;
    L = MakeEmpty(NULL);
    P = L;
    for (i = 0; i < 10; i++)
    {
        Insert(i, L, P);
        P = P->Next;
    }
    P->Next = L;
    List L2;
    L2 = MakeEmpty(NULL);
    P = L2;
    for (i = 0; i < 10; i++)
    {
        Insert(i, L2, P);
        P = P->Next;
    }
    P->Next = L2;
    PrintList(L);
    //TurnAround(L);
    //PrintList(L);
    Merge(L, L2);
    printf("last:\n");
    //L = AddHead(L);
    PrintList(L);
    //printf("%d\n", L2 == NULL);
    PrintList(L2);
    return 0;
}
