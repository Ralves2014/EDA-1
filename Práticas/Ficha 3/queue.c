#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "fatal.h"


#define MinQueueSize ( 5 )

struct QueueRecord{
    int Capacity;
    int Front; //inicio
    int Rear;  //espaço a seguir ao fim
    ElementType *Array;
};


/* FUNCOES AUXILIARES */
/* numero de elementos na fila */
int size( Queue Q ){

    return (Q->Capacity-Q->Front+Q->Rear)/Q->Capacity;
}


/* indice do proximo elemento  */
int successor( int i, Queue Q ){

    return (i+1) % (Q->Capacity);
}



/* FUNCOES DE MANIPULACAO DE QUEUES */
Queue CreateQueue( int MaxElements ){
    Queue Q;

    if( MaxElements < MinQueueSize )
        Error( "Queue size is too small" );

    Q = malloc( sizeof( struct QueueRecord ) );
    if( Q == NULL )
        FatalError( "Out of space!!!" );

    Q->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( Q->Array == NULL )
        FatalError( "Out of space!!!" );

    Q->Capacity = MaxElements+1;  // importante
    MakeEmptyQueue( Q );

    return Q;
}


void DisposeQueue( Queue Q ){
    if( Q != NULL ){
        free( Q->Array );
        free( Q );
    }
}


bool IsEmptyQueue( Queue Q ){


    if (Q->Rear==Q->Front)
    
        return 1;
    
    
    return 0;
}


bool IsFullQueue( Queue Q ){

    if (size(Q)==Q->Capacity-1)
    
        return 1;
    
    
    return 0;
  
}


void MakeEmptyQueue( Queue Q ){
    
    while (Q->Front!=Q->Rear)
    
        Dequeue(Q);
    
    Q->Front=0;
    Q->Rear=0;
}


void Enqueue( ElementType X, Queue Q ){

    if (!IsFullQueue(Q))
    {
        Q->Array[Q->Rear]=X;
        Q->Rear=successor(Q->Rear,Q);
    }
    
}


ElementType Front( Queue Q ){

    return Q->Array[Q->Front];
}


ElementType Dequeue( Queue Q ){

    if (!IsEmptyQueue(Q))
    {
        int x=Q->Array[Q->Front];
        Q->Front+=1;
        return x;
    }
        
    
}
