#include<stdio.h>

int main(){
    unsigned short skor;
    scanf("%hu", &skor);
    if(skor>=90) printf("Luar Biasa\n");
    else if(skor>=70) printf("Bagus\n");
    else if(skor>=50) printf("Cukup\n");
    else printf("Kurang\n");
    return 0;
}