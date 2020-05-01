#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *GetPMT(const char *p)
{
    int len = strlen(p);
    int *pmt = malloc(sizeof(int) * len);
    // if (!pmt)
    //     ERROR("");
    pmt[0] = 0;
    int l = 0;
    for (int i = 1; i < len; i++)
    {
        while ((p[l] != p[i]) && (l > 0))
            l = pmt[l - 1];
        if (p[l] == p[i])
            l++;
        pmt[i] = l;
    }
    return pmt;
}
int KMP(const char *s, const char *p)
{
    int kmp = -1;
    int lens = strlen(s);
    int lenp = strlen(p);
    int *pmt = GetPMT(p);
    for (int i = 0, j = 0; i < lens; i++)
    {
        while ((j > 0) && (s[i] != p[j]))
            j = pmt[j - 1];
        if (s[i] == p[j])
            j++;
        if (j == lenp)
        {
            kmp = i + 1 - lenp;
            break;
        }
    }
    free(pmt);
    printf("%d",kmp);
    return kmp;
}
int main()
{
    char s1[] = "|A|B|C|D|A|B|D|A|B|C|D|A|B|C|";
    char s2[] = "|A|B|C|D|A|B|C|";
    KMP(s1, s2);
}