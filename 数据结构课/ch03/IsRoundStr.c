#include <stdio.h>
#include <stdlib.h>
#define MinStackSize (20)
#define EmptyTOS (-1)
typedef int ElementType;
struct StackRecord;
typedef struct StackRecord *Stack;
Stack InitStack(int MaxElements);
//void DestroyStack(Stack S);
int IsEmpty(Stack S);
void Push(ElementType X, Stack S);
//ElementType Top(Stack S);
ElementType Pop(Stack S);

void Error(const char *Str)
{
    printf("%s\n", Str);
    exit(2);
}

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack InitStack(int MaxElements)
{
    Stack S;
    S = malloc(sizeof(struct StackRecord));
    if (S == NULL)
        Error("空间不足!");
    if (MaxElements < MinStackSize)
    {
        printf("栈太小，默认最小20!\n");
        MaxElements = MinStackSize;
    }
    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL)
        Error("空间不足!");
    S->Capacity = MaxElements;
    S->TopOfStack = EmptyTOS;
    return S;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

void Push(ElementType X, Stack S)
{
    if (IsFull(S))
        Error("栈满!");
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S))
        Error("空栈!");
    else
        return S->Array[S->TopOfStack--];
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsRound(const char *p)
{
    Stack s = InitStack(50);
    int i = 0;
    while (p[i] != 0 && p[i] != '@')
        Push(p[i++], s);
    i = 0;
    while (!IsEmpty(s))
    {
        if (Pop(s) != p[i++])
            return 0;
    }
    return 1;
}

int main()
{
    char *p = "absdba@";
    printf("%d\n", IsRound(p));
}

// void EnQueue(Lnode *rear, ElemType e)
// {
//     Lnode *tmp = malloc(sizeof(Lnode));
//     tmp->Element = e;
//     tmp->next = rear->next;
//     rear->next = tmp;
//     rear = rear->next;
// }