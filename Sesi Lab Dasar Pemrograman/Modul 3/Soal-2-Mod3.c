#include<stdio.h>

unsigned long long deret(int n){
    if(n==1) return n;
    else return deret(n-1) + (n*n);
}

int main(){
    unsigned long long n;
    scanf("%llu", &n);
    printf("%llu\n", deret(n));
    return 0;
}