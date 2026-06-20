#include<stdio.h>

int main(){
    unsigned int n;
    scanf("%u", &n);
    for(int i=1; i<=n; i++){
        if(i%2==0) printf("* ");
        else printf("%u ", i);
    }
    printf("\n");
    return 0;
}