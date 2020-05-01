#include <stdio.h>
int main()
{
    int find_gcd_1(int m, int n);
    int find_gcd_2(int m, int n);
    int a, b;
    int gcd;
    scanf("%d %d", &a, &b);
    if (a < b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    gcd = find_gcd_2(a, b);
    printf("%d", gcd);
}

int find_gcd_1(int m, int n)
{
    int r;
    while (n > 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int find_gcd_2(int m, int n)
{
    int i;
    int gcd = 1;
    for (i = 1; i <= n; i++)
    {
        if (m % i == 0 && n % i == 0)
            gcd = i;
    }
    return gcd;
}