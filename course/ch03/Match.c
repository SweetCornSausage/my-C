#include <stdio.h>
#include <stdlib.h>
#define True (1)
#define False (0)
#define MinStackSize (20)
#define EmptyTOS (-1)
typedef int ElementType;
struct StackRecord;
typedef struct StackRecord *Stack;

Stack InitStack(int MaxElements);
void DestroyStack(Stack S);
int IsEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
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

void DestroyStack(Stack S)
{
    if (S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

void Push(ElementType X, Stack S)
{
    if (IsFull(S))
        Error("栈满!");
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if (IsEmpty(S))
        Error("空栈!");
    else
        return S->Array[S->TopOfStack];
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

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

int MatchBrackets(const char *Str)
{
    Stack s = InitStack(50);
    int i = 0;
    char tmp;
    while (Str[i] != 0)
    {
        if (Str[i] == '(' || Str[i] == '[' || Str[i] == '{')
            Push(Str[i], s);
        if (Str[i] == ')')
        {
            tmp = Pop(s);
            if (tmp != '(')
            {
                printf("不匹配!\n");
                return False;
            }
        }
        if (Str[i] == ']')
        {
            tmp = Pop(s);
            if (tmp != '[')
            {
                printf("不匹配!\n");
                return False;
            }
        }
        if (Str[i] == '}')
        {
            tmp = Pop(s);
            if (tmp != '{')
            {
                printf("不匹配!\n");
                return False;
            }
        }
        i++;
    }
    if (IsEmpty(s))
    {
        printf("匹配!\n");
        DestroyStack(s);
        return True;
    }
    else
    {
        printf("不匹配!\n");
        DestroyStack(s);
        return False;
    }
}

int main()
{
    char a1[100];
    printf("\n请输入一个字符串:\n");
    fgets(a1, 100, stdin);
    MatchBrackets(a1);
}