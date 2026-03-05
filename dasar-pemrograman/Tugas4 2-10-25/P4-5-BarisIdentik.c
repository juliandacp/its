#include<stdio.h>

int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    int matrix[M+1][N+1];
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int baris_identik=0;
    for(int i=0; i<M; i++){
        for(int j=i+1; j<M; j++){
            int identik=1;
            for(int k=0; k<N; k++){
                if(matrix[i][k]!=matrix[j][k]){
                    identik=0;
                    break;
                }
            }
            if(identik){
                baris_identik=1;
                break;
            }
        }
        if(baris_identik) break;
    }
    if(baris_identik) printf("YA\n");
    else printf("TIDAK\n");
    return 0;
}