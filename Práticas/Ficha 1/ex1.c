#include <stdio.h>


int main(){

    int var1=5;
    char var2='a';

    int *ptr1;
    char *ptr2;

    ptr2=&var2;
    ptr1=&var1;

    printf("var1 tem o endereço %p e o valor %d\n", ptr1, *ptr1 );
    printf("var2 tem o endereço %p e o valor %c\n", ptr2, *ptr2 );

    printf("\n");

    printf("Tamanho de int: %ld\n",sizeof(var1));
    printf("Tamanho de char: %ld\n",sizeof(var2));
    printf("Tamanho de int *: %ld\n",sizeof(*ptr1));
    printf("Tamanho de char *: %ld\n",sizeof(*ptr2));

    printf("\n");

    printf("var1+1 tem o endereço %p e o valor %d\n", ptr1+1, *ptr1+1 );
    printf("var2+1 tem o endereço %p e o valor %c\n", ptr2+1, *ptr2+1 );
}