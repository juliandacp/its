#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a>200 || b>150) printf("Sangat Tidak Sehat\n");
    else if(c>12) printf("Tidak Sehat\n");
    else if(a<50 && b<30) printf("Baik\n");
    else if((a>=50 && a<=100) || (b>=30 && b<=60)) printf("Sedang\n");
    else printf("Perlu Dipantau\n");
    return 0;
}
