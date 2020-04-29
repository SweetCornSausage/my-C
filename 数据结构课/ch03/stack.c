#include <stdlib.h>
typedef int ElementType;
struct Node;
typedef struct Node *Position;
typedef Position Stack;

Stack CreateStack(void);
void DistroyStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
int IsEmpty(Stack S);

struct Node
{
    ElementType Element;
    Position Next;
};

Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S == NULL)
        exit(1);
    S->Next = NULL;
    return S;
}

void MakeEmpty(Stack S)
{
    if (S == NULL)
    {
        printf("No stack\n");
        return;
    }
    else
        while (!IsEmpty(S))
            Pop(S);
}

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void DistroyStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

void Push(ElementType X, Stack S)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        exit(1);
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    printf("Empty stack\n");
    return 0;
}

void Pop(Stack S)
{
    Position FirstCell;
    if (!IsEmpty(S))
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
    else
        printf("Empty stack\n");
    return;
}