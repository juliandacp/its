#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int dominan=1;
    for(int i=0; i<n; i++){
        int diagonal=matrix[i][i];
        int sum=0;
        for(int j=0; j<n; j++){
            if(i!=j) sum+=matrix[i][j];
        }
        if(diagonal<=sum){
            dominan=0;
            break;
        }
    }
    if(dominan) printf("YA\n");
    else printf("TIDAK\n");
    return 0;
}