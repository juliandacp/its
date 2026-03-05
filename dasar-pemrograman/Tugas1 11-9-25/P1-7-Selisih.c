#include<stdio.h>

int main(){
    int bil1, bil2, selisih;
    scanf("%d %d", &bil1, &bil2);
    selisih=abs(bil1-bil2);
    printf("%d\n", selisih);
    return 0;
}