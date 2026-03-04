#include<stdio.h>

int main(){
    unsigned int n;
    scanf("%u", &n);
    if(n%2==0) printf("Genap\n");
    else printf("Ganjil\n");
    return 0;
}