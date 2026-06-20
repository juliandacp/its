#include<stdio.h>

int deret(int n){
    if(n==1) return n;
    else return n + deret(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    int res=deret(n);
    printf("%d\n", res);
    return 0;
}