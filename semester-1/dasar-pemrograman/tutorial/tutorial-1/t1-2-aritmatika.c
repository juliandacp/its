#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Penjumlahan: %d\n", a+b);
    printf("Pengurangan: %d\n", a-b);
    printf("Perkalian: %d\n", a*b);
    printf("Pembagian: %.2f\n", (float)a/b);
    return 0;
}