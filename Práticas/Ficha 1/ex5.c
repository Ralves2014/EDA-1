#include<stdio.h>

int horasMin( int min, int *horas, int *minutos ){

  
    *horas=(min/60);
    *minutos=min-(*horas*60);

    

    if (min>1440)
        return 1;

    return 0;
    
}
int main (){

    int m, f, *h, *min;
    int minut=0, hor=0;

    h=&hor;
    min=&minut;

    printf("Insira o total de minutos:");
    scanf("%d", &m);

    f=horasMin(m,h,min);

    printf("%d , %d h : %d min\n", f, hor, minut);

    printf("%d\n",f);

    return 0;
}