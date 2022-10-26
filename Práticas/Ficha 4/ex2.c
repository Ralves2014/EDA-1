#include "list.h"
#include <stdlib.h>
#include "fatal.h"
#include <stdbool.h>
#include "list.c"

void PrintList(List L){
    Position P = Header(L);
    
    while (!IsLast(P, L)) {
        printf("%d ", Retrieve(P->Next));
        P = Advance(P);
    }
}



int main (){

    List L=malloc(sizeof(struct Node));

    Position P=Header(L);

    /*

    Insert(1,L,P);

    P=Advance(P);

    Insert(2,L,P);

    P=Advance(P);

    Insert(3,L,P);

    Delete(2,L);

    */

    for (int i = 1; i < 4; i++)
    {
        Insert(i,L,P);
        P=P->Next;  // Advance(P)
    }
    
    Delete(2,L);

    PrintList(L);

}