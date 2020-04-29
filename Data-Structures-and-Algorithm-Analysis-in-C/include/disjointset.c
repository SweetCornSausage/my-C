#define NumSets 128
#define FastAlg
#ifndef _DisjSet_H
typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;
void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjSet S);
#endif

void Initialize(DisjSet S)
{
    int i;
    for (i = NumSets; i > 0; i--)
        S[i] = 0;
}
#ifdef SlowAlg
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    S[Root2] = Root1;
}
SetType Find(ElementType X, DisjSet S)
{
    if (S[X] <= 0)
        return X;
    else
        return Find(S[X], S);
}
#else
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    if (S[Root2] < S[Root1])
        S[Root1] = Root2;
    else
    {
        if (S[Root1] == S[Root2])
            S[Root1]--;
        S[Root2] = Root1;
    }
}
SetType Find(ElementType X, DisjSet S)
{
    if (S[X] <= 0)
        return X;
    else
        return S[X] = Find(S[X], S);
}
#endif