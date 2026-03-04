#include<stdio.h>

int main(){
    int usia;
    scanf("%d", &usia);
    if(usia>60) printf("Pensiunan\n");
    else if(usia>=19) printf("Pekerja\n");
    else if(usia>=6) printf("Pelajar\n");
    else printf("Balita\n");
    return 0;
}