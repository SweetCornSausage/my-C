#include <stdio.h>
#include <stdlib.h>
#define None (0)
#define Minsize (10)
typedef int ElementType;
struct ElementNode;
struct MatrixNode;
typedef struct MatrixNode *Matrix;

Matrix InitMatrix(int n);
void Scan(Matrix m, ElementType *a);
void PrintFull(Matrix m);
void Print(Matrix m);
ElementType GetDiagSum(Matrix m);
Matrix Transpose(Matrix m);

struct ElementNode
{
    int i;
    int j;
    ElementType element;
};
struct MatrixNode
{
    int n;
    int num;
    struct ElementNode *data;
};
Matrix InitMatrix(int n)
{
    Matrix m = malloc(sizeof(struct MatrixNode));
    m->n = n;
    m->num = 0;
    int size = Minsize > n * n * 0.05 ? Minsize : n * n * 0.05;
    m->data = malloc(sizeof(struct ElementNode) * size);
    return m;
}
void Scan(Matrix m, ElementType *a)
{
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->n; j++)
        {
            if (a[i * m->n + j] != None)
            {
                m->data[m->num].i = i + 1;
                m->data[m->num].j = j + 1;
                m->data[m->num].element = a[i * m->n + j];
                m->num++;
            }
            else
                continue;
        }
    }
}
void PrintFull(Matrix m)
{
    int pointer = 0;
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->n; j++)
        {
            if (m->data[pointer].i == i + 1 && m->data[pointer].j == j + 1)
            {
                printf("%d\t", m->data[pointer].element);
                pointer++;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
}
void Print(Matrix m)
{
    printf("行、列为%d的方阵,非零元素%d个:\n", m->n, m->num);
    for (int i = 0; i < m->num; i++)
        printf("第%d行第%d列:%d\n", m->data[i].i, m->data[i].j, m->data[i].element);
}
ElementType GetDiagSum(Matrix m)
{
    ElementType s = None;
    for (int i = 0; i < m->num; i++)
    {
        if (m->data[i].i == m->data[i].j || m->data[i].i - m->data[i].j == 1 || m->data[i].i - m->data[i].j == -1)
            s += m->data[i].element;
    }
    return s;
}
Matrix Transpose(Matrix m)
{
    Matrix t = InitMatrix(m->n);
    int nums[m->n];
    int loc[m->n];
    loc[0] = 0;
    int i;
    for (i = 0; i < m->n; i++)
        nums[i] = 0;
    for (i = 0; i < m->num; i++)
        nums[m->data[i].j - 1]++;
    for (i = 1; i < m->n; i++)
        loc[i] = loc[i - 1] + nums[i - 1];
    for (i = 0; i < m->num; i++)
    {
        t->data[loc[m->data[i].j - 1]].i = m->data[i].j;
        t->data[loc[m->data[i].j - 1]].j = m->data[i].i;
        t->data[loc[m->data[i].j - 1]].element = m->data[i].element;
        loc[m->data[i].j - 1]++;
        t->num++;
    }
    return t;
}
int main()
{
    int a[2][2] = {1, 2, 3, 0};
    Matrix m = InitMatrix(2);
    Scan(m, a);
    printf("对角线之和为%d\n", GetDiagSum(m));
    PrintFull(m);
    Print(m);
    Matrix n = Transpose(m);
    PrintFull(n);
    printf("对角线之和为%d\n", GetDiagSum(n));
}
