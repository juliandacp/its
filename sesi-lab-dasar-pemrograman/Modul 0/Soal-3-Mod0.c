#include<stdio.h>

int main(){
    int a, b, c;
    float res;
    scanf("%d %d %d", &a, &b, &c);
    res=(float)(a+b)/c;
    printf("%.2f", res);
    return 0;
}