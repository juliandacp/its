#include <stdio.h>

void update(int *a, int *b){
    int tambah = *a + *b;
    int kurang = *a - *b;
    printf("%d %d\n", tambah, kurang);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    update(&a, &b);
    return 0;
}