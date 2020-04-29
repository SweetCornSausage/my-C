#include "tree.h"
#include "fatal.h"
#include <stdlib.h>

struct TreeNode
{
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};
