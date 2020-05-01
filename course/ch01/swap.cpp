#include <stdio.h>
int main()
{
    void swap_1(int a, int b);
    void swap_2(int *a, int *b);
    void swap_3(int &a, int &b);
    int c, d;
    c = 1;
    d = 2;
    printf("原数据 c=%d &c=>%d,d=%d &d=>%d\n", c,&c, d,&d);
    swap_1(c, d);
    printf("值传递结果 c=%d &c=>%d,d=%d &d=>%d\n\n", c,&c, d,&d);
    c = 1;
    d = 2;
    printf("原数据 c=%d &c=>%d,d=%d &d=>%d\n", c,&c, d,&d);
    swap_2(&c, &d);
    printf("指针传递结果 c=%d &c=>%d,d=%d &d=>%d\n\n", c,&c, d,&d);
    c = 1;
    d = 2;
    printf("原数据 c=%d &c=>%d,d=%d &d=>%d\n", c,&c, d,&d);
    swap_3(c, d);
    printf("引用传递结果 c=%d &c=>%d,d=%d &d=>%d\n\n", c,&c, d,&d);
}

void swap_1(int a, int b)
{
    int tmp;
    //printf("&a=>%d &b=>%d &tmp=>%d\n", &a, &b, &tmp);
    tmp = a;
    //printf("&a=>%d &b=>%d &tmp=>%d\n", &a, &b, &tmp);
    a = b;
    //printf("&a=>%d &b=>%d &tmp=>%d\n", &a, &b, &tmp);
    b = tmp;
    printf("&a=>%d &b=>%d &tmp=>%d\n", &a, &b, &tmp);
}

void swap_2(int *a, int *b)
{
    int tmp;
    //printf("a=>%d b=>%d &tmp=>%d\n", a, b, &tmp);
    tmp = *a;
    //printf("a=>%d b=>%d &tmp=>%d\n", a, b, &tmp);
    *a = *b;
    //printf("a=>%d b=>%d &tmp=>%d\n", a, b, &tmp);
    *b = tmp;
    printf("a=>%d b=>%d &tmp=>%d\n", a, b, &tmp);
}

void swap_3(int &a, int &b)
{
    int tmp;
    //printf("&a=>%d &b=>%d &tmp=>%d\n", &a, &b, &tmp);
    tmp = a;
    //printf("&a=>%d &b=>%d &tmp=>%d\n", &a, &b, &tmp);
    a = b;
    //printf("&a=>%d &b=>%d &tmp=>%d\n", &a, &b, &tmp);
    b = tmp;
    printf("&a=>%d &b=>%d &tmp=>%d\n", &a, &b, &tmp);
}