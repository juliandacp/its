#include<stdio.h>

int main(){
    float berat, tinggi, BMI;
    scanf("%f %f", &berat, &tinggi);
    BMI=berat/(tinggi*tinggi);
    printf("%.2f\n", BMI);
    return 0;
}