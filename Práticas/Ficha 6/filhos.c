#include "abp.h"
#include <stdlib.h>
#include "fatal.h"
#include "abp.c"

struct TreeNode{
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};

void filhosunicos(SearchTree T){

    struct TreeNode T;

    while (T!=NULL)
    {
        if (T->Left==NULL && T->Right!=NULL)
        {
            Retrieve(T->Left);
        }
        else if (T->Right==NULL && T->Left!=NULL )
        {
            Retrieve(T->Left);
        }
        
    }


}