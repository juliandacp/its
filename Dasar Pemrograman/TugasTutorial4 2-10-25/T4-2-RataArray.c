#include <stdio.h>

int main(){
    int N, data[100], sum=0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &data[i]);
        sum += data[i];
    }
    printf("%.2f\n", (float)sum/N);
    return 0;
}