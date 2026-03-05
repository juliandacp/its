#include<stdio.h>

int main(){
    unsigned short nilai;
    scanf("%hu", &nilai);
    if(nilai>=60) printf("Lulus\n");
    else printf("Tidak Lulus\n");
    return 0;
}