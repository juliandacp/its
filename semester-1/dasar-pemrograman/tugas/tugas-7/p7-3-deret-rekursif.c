#include<stdio.h>

int deret(int n){
    if(n==1) return 1;
    return n + deret(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", deret(n));
    return 0;
}