#include "list.h"
#include <stdlib.h>
#include "fatal.h"
#include <stdbool.h>
#include "list.c"
#include "stackar.h"
#include "stackar.c"

void PrintList(List L){
    Position P = Header(L);
    
    while (!IsLast(P, L)) {
        printf("%d ", Retrieve(P->Next));
        P = Advance(P);
    }
}


int main (){


    //alterar 
    struct StackRecord *stack=CreateStack(100);
    List L= malloc(sizeof(struct Node));

    Position P=Header(L);

  
    Push(1,stack);
    Push(2,stack);
    Push(3,stack);
    Push(4,stack);
    

    while (!isEmpty(stack))
    {
        Insert(Pop(stack),L,P);
        P=Advance(P);
    }
    
    PrintList(L);

    return 0;
}