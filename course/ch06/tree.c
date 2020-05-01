#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef struct Node *Tree;

Tree CreateTree();
void CreateFromStdin(Tree T);

void ScanPre(Tree T);
void ScanIn(Tree T);
void ScanBack(Tree T);

struct Node
{
    ElementType data;
    PtrToNode lchild;
    PtrToNode rchild;
};

Tree CreateTree()
{
    Tree t = malloc(sizeof(struct Node));
    return t;
}

void CreateFromStdin(Tree T)
{
    ElementType ch;
    ch = getchar();
    if (ch == '#')
        T = NULL;
    else
    {
        T->data = ch;
        T->lchild = malloc(sizeof(struct Node));
        T->rchild = malloc(sizeof(struct Node));
        CreateFromStdin(T->lchild);
        CreateFromStdin(T->rchild);
    }
}

void ScanPre(Tree T)
{
    if (T->data != 0)
    {
        printf("%c", T->data);
        ScanPre(T->lchild);
        ScanPre(T->rchild);
    }
}

void ScanIn(Tree T)
{
    if (T->data != 0)
    {
        ScanIn(T->lchild);
        printf("%c", T->data);
        ScanIn(T->rchild);
    }
}

void ScanBack(Tree T)
{
    if (T->data != 0)
    {
        ScanBack(T->lchild);
        ScanBack(T->rchild);
        printf("%c", T->data);
    }
}

int main()
{
    Tree t = CreateTree();
    CreateFromStdin(t);
    printf("先序输出:\n");
    ScanPre(t);
    printf("\n中序输出:\n");
    ScanIn(t);
    printf("\n后序输出:\n");
    ScanBack(t);
}
