#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n>=2 && n%2==0){
        int l=n/2;
        int p=n*2;
        for(int i=0; i<l; i++){
            for(int j=0; j<p; j++){
                printf("#");
            }
            printf("\n");
        }
        for(int i=0; i<l; i++){
            for(int j=0; j<p; j++){
                printf(".");
            }
            printf("\n");
        }
    }else printf("#\n");
    return 0;
}