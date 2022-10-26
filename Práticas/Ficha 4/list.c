#include "list.h"
#include <stdlib.h>
#include "fatal.h"
#include <stdbool.h>



struct Node{
    ElementType Element;
    Position    Next;
};


List MakeEmpty( List L ){
    if (L==NULL)
    {
        L=malloc(sizeof(struct Node));

        if (L==NULL)
            FatalError("Out of memory");
        L->Next=NULL;   
    }
    else
    {
        DeleteList(L);
    }

    return L;
}

bool IsEmpty( List L ){
    return L->Next==NULL; // assumindo que e uma lista ligada com header
}

bool IsLast( Position P, List L ){
    return P->Next==NULL;
}

Position Find( ElementType X, List L ){   // posição do valor
    Position P;
    P=First(L); // P=L->Next;

    while (P != NULL && P->Element==X)
        P=P->Next;
    
    return P;
}


Position FindPrevious( ElementType X, List L ) {
    Position P;
    P=Header(L);

    while (P->Next != NULL && P->Next->Element!= X)
        P=P->Next;
    
    return P;
}


void Insert( ElementType X, List L, Position P ) {
    Position tmp;

    tmp=malloc(sizeof(struct Node));

    if (tmp==NULL)
        FatalError("Out of memory");

    tmp->Element=X;
    tmp->Next=P->Next;
    P->Next=tmp;
}

void Delete( ElementType X, List L ){
    Position P,tmp;
    P=FindPrevious(X,L);

    if (!IsLast(P,L))
    {
        tmp=P->Next;
        P->Next= tmp->Next;
        free(tmp);
    }
    
}


void DeleteList( List L ) {
    Position P,tmp;

    P=First(L);
    L->Next=NULL;

    while (P!=NULL)
    {
        tmp=P->Next;
        free(tmp);
        P=tmp;
    }
    
}


Position Header( List L ) {
    return L;
}


Position First( List L ) {
    return L->Next;
}


Position Advance( Position P ) {
    return P->Next;
}


ElementType Retrieve( Position P ) {    // é tipo o Top
    return P->Element;
}
