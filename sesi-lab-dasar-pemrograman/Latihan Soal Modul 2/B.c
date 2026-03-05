#include<stdio.h>

int main(){
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);
    int M[A][B];
    for(int i=0; i<A; i++){
        for(int j=0; j<B; j++){
            scanf("%d", &M[i][j]);
        }
    }
    N=N%4;
    if(N<0) N+=4;
    if(N==0){
        for(int i=0; i<A; i++){
            for(int j=0; j<B; j++){
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    if(N==1){ 
        for(int j=0; j<B; j++){
            for(int i=A-1; i>=0; i--){
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
    }
    else if(N==2) {
        for(int i=A-1; i>=0; i--){
            for(int j=B-1; j>=0; j--){
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
    }
    else if(N==3){
        for(int j=B-1; j>=0; j--){
            for(int i=0; i<A; i++){
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}