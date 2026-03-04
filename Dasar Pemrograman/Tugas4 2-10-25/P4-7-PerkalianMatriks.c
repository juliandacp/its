#include<stdio.h>

int main(){
    int M, N, P;
    scanf("%d %d %d", &M, &N, &P);
    int A[M][N], B[N][P], C[M][P];
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &A[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<P; j++){
            scanf("%d", &B[i][j]);
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<P; j++){
            C[i][j] = 0;
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<P; j++){
            for(int k=0; k<N; k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<P; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}