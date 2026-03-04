#include<stdio.h>

int main() {
    int tahun;
    scanf("%d", &tahun);
    if((tahun%4==0 && tahun%100!=0) || tahun%400==0) printf("Kabisat\n");
    else printf("Bukan kabisat\n");
    return 0;
}