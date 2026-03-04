#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n==0) printf("Nol\n");
    else if(n>0) printf("Positif\n");
    else printf("Negatif\n");
    return 0;
}