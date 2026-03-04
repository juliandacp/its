#include <stdio.h>

int main(){
    int data[10];
    for(int i=0; i<10; i++){
        scanf("%d", &data[i]);
    }
    for (int i=0; i<10; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}