#include<stdio.h>

int tambah(int a, int b, int *c){
    *c=a+b;
}

int main(){
    int a=1;
    int b=2;
    int c;
    tambah(a, b, &c);
    printf("%d\n", c);
    return 0;
}