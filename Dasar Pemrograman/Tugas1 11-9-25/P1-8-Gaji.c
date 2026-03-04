#include<stdio.h>

int main(){
    float gaji_pokok, tunjangan, pajak, gaji_bersih;
    scanf("%f", &gaji_pokok);
    tunjangan=0.2*gaji_pokok;
    pajak=0.1*(gaji_pokok+tunjangan);
    gaji_bersih=gaji_pokok+tunjangan-pajak;
    printf("%.2f\n", gaji_bersih);
    return 0;
}