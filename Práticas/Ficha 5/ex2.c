#include "btree.h"
#include <stdlib.h>
#include "fatal.h"
#include "btree.c"

typedef int ElemenType;

void PrintInorder( BTree T){

    if (T!=NULL)
    {
        PrintInorder(T->Left);
        printf("%d ",T->Element);
        PrintInorder(T->Right);
    }
    
}



int main (){

    Position node[7];

    for (int i = 0; i < 4; i++)
        node[i]=SetTree(i,);
    
    node[4]


    return 0;
}