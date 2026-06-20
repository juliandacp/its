#include <stdio.h>

int main(){
    int N, data[100];
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &data[i]);
    }
    int max=data[0], min=data[0];
    for(int i=1; i<N; i++){
        if(data[i]>max) max=data[i];
        if(data[i]<min) min=data[i];
    }
    printf("%d %d\n", max, min);
    return 0;
}