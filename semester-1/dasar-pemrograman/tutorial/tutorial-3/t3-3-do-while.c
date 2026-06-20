#include <stdio.h>

int main() {
    int angka, jumlah = 0;
    do {
        scanf("%d", &angka);
        if (angka >= 0) {
        jumlah += angka;
        }
    } while (angka >= 0);
        printf("%d\n", jumlah);
    return 0;
}