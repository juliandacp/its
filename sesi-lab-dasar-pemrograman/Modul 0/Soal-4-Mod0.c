#include<stdio.h>

int main(){
    int A, B, C, D, E, sum;
    float avg;
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    sum=A+B+C+D+E;
    avg=(float)sum/5;
    printf("%d %.1f", sum, avg);
}