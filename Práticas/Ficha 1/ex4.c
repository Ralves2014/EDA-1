#include<stdio.h>

void vmaior( int *v1, int *v2 ){

    if (*v1>*v2)
        printf("Maior: endereço=%p, valor=%d\n", v1,*v1);
    else if (*v2>*v1)
        printf("Maior: endereço=%p, valor=%d\n", v2,*v2);

}
int main (){

    int n1, n2, *p1, *p2, f;

    p1=&n1;
    p2=&n2;

    printf("Insira o primeiro número:");
    scanf("%d", &n1);
    printf("Insira o segundo número:");
    scanf("%d", &n2);

    vmaior(p1,p2);

}