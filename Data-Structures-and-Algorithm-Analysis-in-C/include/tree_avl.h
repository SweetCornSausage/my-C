typedef int ElementType;
#ifndef _AvlTree_H
#define _AvlTree_H

struct AvlNode;
typedef struct AvlNode *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode AvlTree;

AvlTree MakeEmpty(AvlTree);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

#endif