#include "stackar.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ParentesisMatch(char *s){

    char ch;
    struct StackRecord *stack= CreateStack(10);
    

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i]=='('){
            Push(s[i],stack);
        }
        else if (s[i]==')')
        {
            if (IsEmpty(stack))  
                return 0;
            ch=Pop(stack);
            
        }
        
    }

    if (!IsEmpty(stack))
        return 0;
    

    return 1;
    
}
int main(){

    char str[]="()";

    printf("%s: %d\n", str, ParentesisMatch(str));


    return 0;
}