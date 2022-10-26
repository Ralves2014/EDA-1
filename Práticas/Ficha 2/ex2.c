#include "stackar.c"
#include <stdio.h>
#include <stdlib.h>


int main(){

    int a, b;
    
    struct StackRecord *stack= CreateStack(100);

    //a) 23 56- 3* 1 3 4 / + /
    
    Push(23,stack);
    Push(56,stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a-b),stack);
    Push(3,stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a*b),stack);

    Push(1,stack);
    Push(3,stack);
    Push(4,stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a/b),stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a+b),stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a/b),stack);

    printf("%d\n", Pop(stack));
    //printf("%d\n", Top(stack));

    /*

    //b) 2 4 7 32 / + 7 5 - 3 *- -
    
    Push(2,stack);
    Push(4,stack);
    Push(7,stack);
    Push(32,stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a/b),stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a+b),stack);

    Push(7,stack);
    Push(5,stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a-b),stack);

    Push(3,stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a*b),stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a-b),stack);

    b=Pop(stack);
    a=Pop(stack);

    Push((a-b),stack);

    printf("%d\n", Pop(stack));

    
    //c) 2 6 + 4 7 * 5 - / 6 9 / * 4 9 * 5 3 / + -

    
    Push(2,stack);
    Push(6,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a+b,stack);
    Push(4,stack);
    Push(7,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a*b,stack);
    Push(5,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a-b,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a/b,stack);
    Push(6,stack);
    Push(9,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a/b,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a*b,stack);
    Push(4,stack);
    Push(9,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a*b,stack);
    Push(5,stack);
    Push(3,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a/b,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a+b,stack);

    b=Pop(stack);
    a=Pop(stack);
    
    Push(a-b,stack);

    printf("%d\n", Pop(stack));

    */

    return 0;
}