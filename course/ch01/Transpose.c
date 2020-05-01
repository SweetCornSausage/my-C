#include "Transpose.h"
#include <stdio.h>
#include <stdlib.h>
#define MinSize (1)

struct MatrixElements
{
    double **Arr;
    int n;
    int m;
};
typedef struct MatrixElements *Matrix;

Matrix Initialize()
{
    Matrix T = malloc(sizeof(struct MatrixElements));
    return T;
}

void FreeMatrix(Matrix T)
{
    int i;
    for (i = 0; i < (T->n); i++)
        free(T->Arr[i]);
    free(T->Arr);
}

void SetSize(Matrix T, int a, int b)
{
    if (a < MinSize || b < MinSize)
    {
        printf("矩阵太小！");
        return;
    }
    T->Arr = malloc(sizeof(double *) * a);
    for (int i = 0; i < a; i++)
        T->Arr[i] = malloc(sizeof(double) * b);
    T->n = a;
    T->m = b;
}

void SetMatrix(Matrix T, double *arr)
{
    int i, j, n;
    n = 0;
    for (i = 0; i < T->n; i++)
        for (j = 0; j < T->m; j++)
            T->Arr[i][j] = arr[n++];
}

void Print(Matrix T)
{
    int i, j;
    for (i = 0; i < T->n; i++)
    {
        for (j = 0; j < T->m; j++)
            printf("%.0f\t", T->Arr[i][j]);
        printf("\n");
    }
}

void Transpose(Matrix T, Matrix M)
{
    SetSize(M, T->m, T->n);
    int i, j;
    for (i = 0; i < M->n; i++)
        for (j = 0; j < M->m; j++)
            M->Arr[i][j] = T->Arr[j][i];
}

int main()
{
    printf("请输入行和列：");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("请输入至少%d个数据：", a * b);
    double arr[a * b];
    fflush(stdin);
    for (int i = 0; i < a * b; i++)
        scanf("%lf", &arr[i]);
    fflush(stdin);
    Matrix m = Initialize();
    Matrix n = Initialize();
    SetSize(m, a, b);
    SetMatrix(m, arr);
    printf("原始矩阵如下：\n");
    Print(m);
    Transpose(m, n);
    printf("转置矩阵如下：\n");
    Print(n);
}