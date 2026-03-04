#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n<1 || n>10){
        scanf("%d", &n);
    }
    printf("%d\n", n);
    return 0;
}