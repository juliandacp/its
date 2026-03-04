#include<stdio.h>

int main(){
    int N;
    char hewan[10][20];
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", hewan[i]);
    }
    for(int i = 0; i < N; i++){
        if(hewan[i][0] == 'T'){
            printf("%s\n", hewan[i]);
        }
    }
    return 0;
}