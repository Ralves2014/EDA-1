#include<stdio.h>

void ordena (int *a, int *b, int *c){

    if (*a>*b && *a>*c && *b<*c)
        printf("Ordem crescente: %d<%d<%d",*b,*c,*a);
    
    else if (*a>*b && *a>*c && *b>*c)
        printf("Ordem crescente: %d<%d<%d",*c,*b,*a);

    else if (*b>*a && *b>*c && *a<*c)
        printf("Ordem crescente: %d<%d<%d",*a,*c,*b);
    
    else if (*b>*a && *b>*c && *a>*c)
        printf("Ordem crescente: %d<%d<%d",*c,*a,*b);
    
    else if (*c>*a && *c>*b && *b<*a)
        printf("Ordem crescente: %d<%d<%d",*b,*a,*c);
    
    else if (*c>*a && *c>*b && *b>*a)
        printf("Ordem crescente: %d<%d<%d",*a,*b,*c);
    
    

}
int main (){

    int n1, n2, n3, *p1, *p2, *p3;

    p1=&n1;
    p2=&n2;
    p3=&n3;

    printf("Insira o primeiro número:");
    scanf("%d", &n1);
    printf("Insira o segundo número:");
    scanf("%d", &n2);
    printf("Insira o terceiro número:");
    scanf("%d", &n3);

    ordena(p1,p2,p3);

    return 0;
}