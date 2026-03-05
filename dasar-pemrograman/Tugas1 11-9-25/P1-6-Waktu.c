#include<stdio.h>

int main(){
    int detik, jam, menit, detik2;
    scanf("%d", &detik);
    jam=detik/3600;
    menit=detik%3600/60;
    detik2=detik%3600%60;
    printf("%d %d %d\n", jam, menit, detik2);
    return 0;
}