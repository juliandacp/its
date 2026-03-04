#include<stdio.h>
#define phi 3.14159

int main(){
    float volume, luas, r, tinggi;
    scanf("%f %f", &r, &tinggi);
    volume=phi*r*r*tinggi;
    luas=2*phi*r*(r+tinggi);
    printf("%.2f %.2f\n", volume, luas);
    return 0;
}