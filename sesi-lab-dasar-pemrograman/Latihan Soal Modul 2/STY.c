#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char S[101];
    int N, M, total=0;
    scanf("%s", S);
    scanf("%d %d", &N, &M);
    int panjang_S=strlen(S);
    for(int i=0; i<panjang_S; i++){
        S[i]=toupper(S[i]);
    }
    char nama[101][101];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%c", &nama[i][j]);
            nama[i][j]=toupper(nama[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if()
        }
    }
    return 0;
}