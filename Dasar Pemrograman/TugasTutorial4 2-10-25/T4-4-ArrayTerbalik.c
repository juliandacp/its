#include <stdio.h>

int main(){
    int N, data[100];
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &data[i]);
    }
    for(int i=N-1; i>=0; i--) {
        printf("%d ", data[i]);
    }
    return 0;
}