#include<stdio.h>

int main(){
    float luas, alas, tinggi;
    scanf("%f %f", &alas, &tinggi);
    luas=0.5*alas*tinggi;
    printf("%.2f\n", luas);
    return 0;
}