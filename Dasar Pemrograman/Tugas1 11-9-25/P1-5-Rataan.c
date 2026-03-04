#include<stdio.h>

int main(){
    int bil1, bil2, bil3;
    float rata2;
    scanf("%d %d %d", &bil1, &bil2, &bil3);
    rata2=(float)(bil1+bil2+bil3)/3;
    printf("%.2f", rata2);
    return 0;
}