#include <stdio.h>

int main(){
    int umur;
    scanf("%d", &umur);
    if(umur<=5) printf("Bayi\n");
    else if(umur<=11) printf("Anak-anak\n");
    else if(umur<=25) printf("Remaja\n");
    else if(umur<=45) printf("Dewasa\n");
    else if(umur<=65) printf("Lansia\n");
    else printf("Manula\n");
    return 0;
}