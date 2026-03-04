#include <stdio.h>

int main(){
    int data[4][3];
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &data[i][j]);
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            printf("%d ", data[i][j]);
        }
    printf("\n");
    }
 return 0;
}