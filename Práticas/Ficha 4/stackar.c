#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>


#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )


struct StackRecord
{
    int Capacity;
    int TopOfStack;   // posiçao do ultimo elemento da pilha
    ElementType *Array;
};



Stack CreateStack( int MaxElements )
{

    Stack S;	

	if( MaxElements < MinStackSize )
		Error( "Stack size is too small" );

	S = malloc( sizeof( struct StackRecord ) );  // malloc serve para guardar um espaço na memoria
	if( S == NULL )
		FatalError( "Out of space!!!" );

	S->Array = malloc( sizeof( ElementType ) * MaxElements );
	if( S->Array == NULL )
		FatalError( "Out of space!!!" );

	S->Capacity = MaxElements;
	makeEmpty( S );

	return S;
}



void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}


int isEmpty( Stack S )
{
	if (S->TopOfStack== EmptyTOS)
	
		return 1;
	
	return 0;
}


int IsFull( Stack S )
{
	if (S->TopOfStack == S->Capacity-1)
	
		return 1;
	
	
	return 0;
}


void makeEmpty( Stack S )
{
	while (S->TopOfStack!= EmptyTOS)
	
		Pop(S);
	
	
}


void Push( ElementType X, Stack S )  // elementtype=int
{
	if (!IsFull(S))
	{
		S->TopOfStack+=1;
		S->Array[S->TopOfStack]=X;
	}
	
}


ElementType Top( Stack S )
{
    return S->Array[S->TopOfStack];
}


ElementType Pop( Stack S )
{
	if (!isEmpty(S))
	{
		int x=S->Array[S->TopOfStack];
		S->TopOfStack-=1;
		return x;
	}else 
	
		return EmptyTOS;
	
		
}