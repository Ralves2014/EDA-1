#include<stdio.h>

// a formula que esta no enunciado esta errado, a que esta apresentada a baixo e a correta

struct maxmin{
    float max;
    float min;
};


struct maxmin MaxMinFinder(float x, float y, float z){
    
    struct maxmin data;
    data.max = x;
    data.min = x;
    
    if(y > data.max){
        data.max = y;
    }
    if(z > data.max){
        data.max = z;
    }
    
    if(y < data.min){
        data.min = y;
    }
    if(z < data.min){
        data.min = z;
    }
    
    return data;
}

void rgb2hsv( int R, int G, int B, float *h, float *s, float *v ){


    float r = ((float) R) / 255.0;
    float g = ((float) G) / 255.0;
    float b = ((float) B) / 255.0;


    struct maxmin data = MaxMinFinder(r, g, b);

   if(data.max == r){
        *h = (60*((g-b)/(data.max - data.min))+360);
    }
    else if (data.max == g){
        *h = (60*((b-r)/(data.max - data.min))+120);
    }
    else if (data.max == b){
        *h = (60*((r-g)/(data.max - data.min))+240);
    }
    else if((data.max - data.min) == 0){
        *h = 0;
    }
    
    *s = (float)(data.max - data.min) / (float)data.max;
    
    *v = data.max;

}


int main (){

    int R, G, B;
    
    float h1, s1, v1;
    
    float *h = &h1, *s = &s1, *v = &v1;
    
    printf("Insira os valores em RGB para ser efetuada a conversão: ");
    scanf("%d %d %d", &R, &G, &B);
    rgb2hsv(R, G, B, h, s, v);
    
    printf("\n\nRGB=(%d, %d, %d) <=> HSV=(%.3f, %.3f, %.3f)\n\n", R,G,B, h1, s1, v1);
    return 0;
}