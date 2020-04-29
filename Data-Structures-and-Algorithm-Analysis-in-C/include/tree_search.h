typedef int ElementType;
#ifndef _Tree_H
#define _Tree_H

struct TreeNode;
typedef struct TreeNode *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);
#endif