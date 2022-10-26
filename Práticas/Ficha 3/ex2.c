#include <stdlib.h>
#include <stdbool.h>
#include "queue.c"
#include "fatal.h"
#include "stackar.h"
#include "stackar.c"
#include "queue.h"

void print_queue(Queue Q){
    for(int i = Q->Front; i != Q->Rear; i = successor(i, Q)){
        printf("%d ", Q->Array[i]);
    }
} 

Queue invert(Queue x){

    struct StackRecord *s1=CreateStack(100);
    

    while (!IsEmptyQueue(x))
        Push(Dequeue(x),s1);
    
    MakeEmptyQueue(x);

    while (!IsEmpty(s1))
        Enqueue(Pop(s1),x);
    
    return x;
    
}
int main (){

    int f;

    struct QueueRecord *q=CreateQueue(10);

    Enqueue(1,q);
    Enqueue(2,q);
    Enqueue(3,q);

    print_queue(invert(q));
    
    return 0;
}