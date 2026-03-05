#include <stdio.h>

int main(){
    int data[3][3], sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &data[i][j]);
        sum += data[i][j];
        }
    }
    printf("%d\n", sum);
    return 0;
}