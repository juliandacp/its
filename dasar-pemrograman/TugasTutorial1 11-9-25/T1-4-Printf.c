#include <stdio.h>

int main(){
    char nama[50];
    int usia;
    float tinggi;
    scanf("%s %d %f", &nama, &usia, &tinggi);
    printf("Halo, %s! Anda berusia %d tahun dan memiliki tinggi %.2f meter.\n", nama, usia, tinggi);
    return 0;
}