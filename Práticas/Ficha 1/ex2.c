#include <stdio.h>
int main(){

    int i, j, *p1, *p2, **pp1, **pp2;
    i=4;
    j=5;
    p1 = &i;
    p2 = &j;
    pp1 = &p2;
    pp2 = &p1;

    //i=4
    //*p2=5
    //&i=1000
    //&p2=1053
    //*pp1=1007 
    //*pp2=1000 
    //&(*p1)=1000 
    //j=5
    //*p1=4
    //*(&p1)=1000
    

}