#include<stdio.h>

int main(){
    int matrix[5][5];
    int transpose[5][5];
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            transpose[j][i]=matrix[i][j];
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}