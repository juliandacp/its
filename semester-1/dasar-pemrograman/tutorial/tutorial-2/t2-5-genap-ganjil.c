#include <stdio.h>

int main(){
    int angka;
    scanf("%d", &angka);
    if(angka % 2 == 0) printf("Genap\n");
    else printf("Ganjil\n");
    return 0;
}