#include<stdio.h>
#include<string.h>

int main(){
    unsigned int n;
    scanf("%hu", &n);
    unsigned int matrix[101][101];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%hu", &matrix[i][j]);
        }
    }
    char s[101];
    unsigned long long rotasi;
    unsigned long long N=0;
    while(1){
        scanf("%s", s);
        if(strcmp(s, "quit")!=0){
            scanf("%llu", &rotasi);
            N+=rotasi;
        }else break;
    }
    N%=4;
    if(N==0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%hu ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else if(N==1){
        for(int j=0; j<n; j++){
            for(int i=n-1; i>=0; i--){
                printf("%hu ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else if(N==2){
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                printf("%hu ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else if(N==3){
        for(int j=n-1; j>=0; j--){
            for(int i=0; i<n; i++){
                printf("%hu ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
