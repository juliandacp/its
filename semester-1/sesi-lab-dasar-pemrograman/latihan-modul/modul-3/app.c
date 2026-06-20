#include<stdio.h>
#include<string.h>

void pw(int n, int res){
    if(res==0) return;
    pw(n, res-1);
    if(res==n){
        for(int i=0; i<res; i++){
            printf("z");
        }
    }else if(res%2==1){
        for(int i=0; i<res; i++){
            printf("d");
        }
    }else{
        for(int i=0; i<res; i++){
            printf("e");
        }
    }
    printf("\n");
    pw(n, res-1);
}

int main() {
    int N;
    scanf("%d", &N);
    pw(N, N);
    return 0;
}