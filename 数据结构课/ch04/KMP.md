# 字符串找子串
> KMP算法

### 1. 部分匹配表(PMT)
前缀：除了最后一个字符外，一个字符串的全部头部组合  
后缀：除了第一个字符以外，一个字符串的全部尾部组合  
部分匹配值：前缀和后缀最长共有元素的长度  
```
|a|b|a|b|a|
  |a|b|a|b|a|       #=>0
|a|b|a|b|a|
    |a|b|a|b|a|     #=>3
|a|b|a|b|a|
      |a|b|a|b|a|   #=>0
|a|b|a|b|a|
        |a|b|a|b|a| #=>1
最终ababa的PMT值为3
当增加一个字符时，PMT至多增加1
|a|b|a|b|a|x|
    |a|b|a|b|a|x| 只要比较[PMT]位置的字符与新增字符
相等当然是好的，如果不相等
由于已经有3个(aba)是配对好的，现在掐头去尾再移动一下得到
|a|b|a|x| //上串的尾
  |a|b|a| //下串的头
再找(令x=a吧)
|a|b|a|x|
  |a|b|a|b|     #=>0
|a|b|a|x|
    |a|b|a|b|   #=>0
|a|b|a|x|
      |a|b|a|b| #=>1
注意到以上操作在计算aba的PMT值时已经操作过了
|a|b|a|x|
    |a|b|a| //在aba后增加一个字符
```
最终代码如下：
```C++
int *GetPMT(const char *p)
{
    int len = strlen(p);
    int *pmt = malloc(sizeof(int) * len);
    if (!pmt)
        ERROR("");
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
```
### 2. KMP算法
有了这个PMT后就该找子串了
```
|A|B|C|D|A|B|·|A|B|C|D|A|B|C|
|A|B|C|D|A|B|C
|A|B|C|D|A|B|·|A|B|C|D|A|B|C|
        |A|B
······
|A|B|C|D|A|B|·|A|B|C|D|A|B|C|
              |A|B|C|D|A|B|C|
移动位数 = 已匹配的字符数 - 对应的部分匹配值
```
最终代码如下：
```C++
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
    return kmp;
}
```