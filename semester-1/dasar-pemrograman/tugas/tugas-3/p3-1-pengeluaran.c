#include<stdio.h>

int main(){
    int N, total=0;
    scanf("%d\n", &N);
    for(int i=0; i<N; i++){
        int x;
        scanf("%d", &x);
        total+=x;
    }
    printf("%d\n", total);
    return 0;
}