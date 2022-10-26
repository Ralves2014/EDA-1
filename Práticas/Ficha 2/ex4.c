#include "stackar.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ParentesisMatch2(char *s){

    char ch;
    struct StackRecord *stack= CreateStack(100);

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i]=='(')
        {
            Push(s[i],stack);
        }
        else if (s[i]=='{')
        {
            Push(s[i],stack);
        }
        else if (s[i]=='[')
        {
            Push(s[i],stack);
        }
        else if (s[i]==')')
        {
            if (Top(stack)=='(')
                Pop(stack);
            else 
                return 0;
            
        }
        else if (s[i]=='}')
        {
            if (Top(stack)=='{')
                Pop(stack);
            else
                return 0;
            
        }
        else if (s[i]==']')
        {
            if (Top(stack)=='[')
                Pop(stack);
            else
                return 0;
            
        }
        
    }
    
    if (!IsEmpty(stack))
    {
        return 0;
    }
    
    return 1;
}
int main(){

    char str[]=")olá)[{}]";

    printf("%s: %d\n", str, ParentesisMatch2(str));


    return 0;
}