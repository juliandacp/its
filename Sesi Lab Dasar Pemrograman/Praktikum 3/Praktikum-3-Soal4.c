#include<stdio.h>

double cangkang(double b, double n){
    if(n==0) return b;
    if(n>=100000) n=100000;
    return b + b/cangkang(b, n-1);
}

int main(){
    double b, n;
    scanf("%lf %lf", &b, &n);
    printf("%.8lf\n", cangkang(b, n));
    return 0;
}
