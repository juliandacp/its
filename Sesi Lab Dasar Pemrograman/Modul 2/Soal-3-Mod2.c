#include<stdio.h>

int main(){
    unsigned int n;
    scanf("%u", &n);
    for(int i=2; i<=n; i++){
        int prima=1;
        for(int j=2; j*j<=i; j++){
            if(i%j==0){
                prima=0;
                break;
            }
        }
        if(prima==1) printf("* ");
        else printf("%u ", i);
    }
    printf("\n");
    return 0;
}