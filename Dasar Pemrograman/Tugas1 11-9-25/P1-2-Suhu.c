#include<stdio.h>
#define konversi 1.8

int main(){
    float c, farenheit;
    scanf("%f", &c);
    farenheit=konversi*c+32.0;
    printf("%.2f\n", farenheit);
    return 0;
}