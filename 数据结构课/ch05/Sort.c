#include <stdio.h>
void Swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void Sort(int a[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (a[i] % 2 == 0 && a[j] % 2 == 1)
            Swap(&a[i++], &a[j--]);
        if (a[i] % 2 == 1)
            i++;
        if (a[j] % 2 == 0)
            j--;
    }
}
void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
int main()
{
    int a[] = {1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9, 0, 1, 1, 2, 3};
    Sort(a, 12);
    Print(a, 12);
}
