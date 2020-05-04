# 实验内容
## 实验目的
### 掌握二叉树的定义和性质
### 熟悉二叉链表表示二叉树的结构和基本操作
### 掌握二叉链表表示二叉树的三种遍历(先序，中序，后序)
## 实验内容
### 按先序遍历的顺序构建一个基于二叉链表存储结构的二叉树
### 对构建的二叉树实现先序、中序和后序遍历，并输出对应的遍历序列

# 实验过程
实验环境:Manjaro Linux x86_64,vim,gcc-x64,UTF-8
## 实验分析
### 二叉树
一棵二叉树是若干节点的一个有限集合，该集合或者为空，或者由一个根节点加上两棵左子树和右子树组成，左右子树的次序不能颠倒。
### 二叉链表
二叉链表可以用来进行二叉树的链式存储结构。对于通常的二叉链表，链表的每个结点由三个域组成，数据域和左右指针域，左右指针分别用来给出该结点左孩子和右孩子所在的链结点的存储地址。
### 先序顺序创建二叉树
从标准输入读入下一个元素
申请当前节点并赋值
递归创建其左子树
递归创建其右子树
### 二叉树的三种遍历
#### 先序
访问当前节点，
访问当前节点的左子树，
访问当前节点的右子树
#### 中序
访问当前节点的左子树，
访问当前节点，
访问当前节点的右子树
#### 后序
访问当前节点的左子树，
访问当前节点的右子树，
访问当前节点
## 代码设计
### 头文件的声明
```c
#include <stdio.h> // 提供标准输入输出
#include <stdlib.h> // 动态分配内存函数
```
### 数据类型和函数声明
```c
typedef int ElementType; // 基本数据类型
struct Node; // 二叉链表的结点
typedef struct Node *PtrToNode; // 指向节点的指针
typedef struct Node *Tree; // 指向树根的指针

Tree CreateTree(); // 创建一棵空树
void CreateFromStdin(Tree T); // 创建一棵空树
void ScanPre(Tree T); // 先序遍历
void ScanIn(Tree T); // 中序遍历
void ScanBack(Tree T); // 后序遍历
```
### 二叉链表
```c
// 二叉链表结点内部
struct Node
{
    ElementType data;
    PtrToNode lchild;
    PtrToNode rchild;
};
// 创建新的空树
Tree CreateTree()
{
    Tree t = malloc(sizeof(struct Node));
    t->data = 0;
    return t;
}
```
### 先序输入创建二叉树
```c
void CreateFromStdin(Tree T)
{
    ElementType ch;
    ch = getchar();
    while (ch == '\n')
        ch = getchar();
    if (ch == '#')
        T = NULL;
    else
    {
        T->data = ch;
        T->lchild = CreateTree();
        T->rchild = CreateTree();
        CreateFromStdin(T->lchild);
        CreateFromStdin(T->rchild);
    }
}
```
### 三种遍历
```c
// 先序遍历
void ScanPre(Tree T)
{
    if (T->data != 0)
    {
        printf("%c", T->data);
        ScanPre(T->lchild);
        ScanPre(T->rchild);
    }
}
// 中序遍历
void ScanIn(Tree T)
{
    if (T->data != 0)
    {
        ScanIn(T->lchild);
        printf("%c", T->data);
        ScanIn(T->rchild);
    }
}
// 后序遍历
void ScanBack(Tree T)
{
    if (T->data != 0)
    {
        ScanBack(T->lchild);
        ScanBack(T->rchild);
        printf("%c", T->data);
    }
}
```
### 主函数
```c
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
```
# 实验结果
## 第一次实验
## 第二次实验
## 第三次实验

# 实验改进
## 鲁棒性
从标准输入创建树很方便，因为在完整输入代表一棵树的顺序序列之前，输入的请求不会结束。但更多情况是，无法直观的看出一串很长的序列是否能解析成一棵二叉树，一口气输入了这串序列，做了无用功。此时，一个程序的鲁棒性就至关重要了。  
鲁棒性，Robust的音译，也就是健壮和强壮的意思。它也是在异常和危险情况下系统生存的能力。比如说，计算机软件在输入错误、磁盘故障、网络过载或有意攻击情况下，能否不死机、不崩溃，就是该软件的鲁棒性。  
对于上述设计的程序，可以通过改进顺序序列创建二叉树的函数，实现识别一串顺序序列是否能解析成一棵二叉树。
## 分析
对于一串顺序序列，由于创建是递归的，采用逐个元素读取，如果是符合要求的序列，那么序列应该正好读取完毕。反之，序列过短会导致递归无法结束，序列过长会导致序列有剩余未读取元素。从原序列读取是先进，创建树时读取是先出，采用队列解决。  
将元序列转换为队列，并入队结束符0。在出队时，进行队列判空的判定，以判定是否强制结束递归。在递归完全结束时，检查队列，为空则过短，队头为结束符0则创建成功，其余情况则是原序列过长。
## 代码实现
```c
// 要使用的队列的头文件
#include "queue_ar.c"
// 要使用到的队列有关函数
Queue CreateQueue(int MaxElements); // 创建空队列
int IsEmpty(Queue Q); // 队列判空
void Enqueue(ElementType X, Queue Q); // 入队
ElementType FrontAndDequeue(Queue Q); // 出对
ElementType Front(Queue Q); // 队头
// 使用队列创建树的函数声明
void CreateWithQueue(Tree T);
static void CreateFromQueue(Tree T, Queue Q);
// 具体函数
void CreateWithQueue(Tree T)
{
    Queue q = CreateQueue(64);
    ElementType ch;
    ch = getchar();
    while (ch != '\n')
    {
        Enqueue(ch, q);
        ch = getchar();
    }
    Enqueue('\0', q);
    CreateFromQueue(T, q);
    if (IsEmpty(q))
    {
        printf("太短\n");
        exit(0);
    }
    else if (Front(q) == '\0')
        printf("可以,继续\n");
    else
    {
        printf("太长\n");
        exit(0);
    }
}
static void CreateFromQueue(Tree T, Queue Q)
{
    if (IsEmpty(Q))
        return;
    ElementType ch;
    ch = FrontAndDequeue(Q);
    if (ch == '#')
        T = NULL;
    else
    {
        T->data = ch;
        T->lchild = CreateTree();
        T->rchild = CreateTree();
        CreateFromQueue(T->lchild, Q);
        CreateFromQueue(T->rchild, Q);
    }
}
```
## 测试
### 主函数
```c
int main()
{
    Tree t = CreateTree();
    CreateWithQueue(t);
    printf("先序输出:\n");
    ScanPre(t);
    printf("\n中序输出:\n");
    ScanIn(t);
    printf("\n后序输出:\n");
    ScanBack(t);
}
```
### 实验结果
## 另一种解决方法
二叉树的顺序序列有其自身的特点，一是总的空结点数比总的非空结点数多一，二是最后的元素总是空结点，三是在最后一个结点之前，非空结点个数>=空结点个数。  
通过对输入序列进行上述三个条件的检查，也可以实现检验。
# 实验总结
## 二叉树与递归
二叉树中递归的思想很重要，在笔者进行二叉树的解释时，就采用了递归的思想。  
该集合或者为空，或者由一个根节点加上两棵左子树和右子树组成  
如果就定义为：每一个顶点的度不大于3，唯一的父结点，和最多2个子结点。  
虽然更简洁易懂，但是少了递归的思想在里面，对后面的分析和代码都有很大的影响。  
在上述几乎每个程序中，都用到了递归的思想。
## 序列合理性检验
尽管采用直接对序列的格式检验更快，更方便，但是使用队列是在笔者写最基础的从标准输入创建树时就自然而然想到的。能够用到之前所学的知识也是一件很开心的事。
## 结束递归
C语言中不能直接强行结束递归，想要在某种情况下结束递归，大多数时候会采用一个标志符号，标志符号定义为全局变量，或是定义为局部变量，每次递归都传入该局部变量。  
在上述程序中，可以直接使用队列空作为标志符号。
## 二叉树的类图形化输出
既然满足一定条件的序列就可以解析为一颗树，那么不需要事先构建这棵树，直接随意写序列，主要满足上述三个条件就可以。但是这样就不知道这棵树的具体形状。如果能（类）图形化输出一颗二叉树就好了。
思路是采用层次遍历的思想，需要使用队列。
层次遍历的基本思想是：父结点出队的同时两个子节点进队
在层次遍历的基础上，保留父结点，再保留空结点的标志，最终可以得到一个满二叉树，其深度是原二叉树+1。类图形化输出满二叉树就比较简单了。
## 感想
无