#include<stdio.h>

int main(){
    int gaji;
    scanf("%d", &gaji);
    if(gaji>=10000000) printf("Kaya\n");
    else if(gaji>=3000000) printf("Menengah Atas\n");
    else if(gaji>=1000000) printf("Menengah Bawah\n");
    else printf("Miskin\n");
    return 0;
}