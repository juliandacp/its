#include<stdio.h>

unsigned long long faktorial(int n){
    if(n==0) return 1;
    else return n * faktorial(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%llu\n", faktorial(n));
    return 0;
}