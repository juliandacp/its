#include<stdio.h>

int kombinasi(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return kombinasi(n-1) + kombinasi(n-2);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", kombinasi(n));
    return 0;
}