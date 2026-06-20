#include<stdio.h>

int main(){
    char nilai;
    scanf("%c", &nilai);
    switch(nilai){
    case 'A':
        printf("4.00\n");
        break;
    case 'B':
        printf("3.00\n");
        break;
    case 'C':
        printf("2.00\n");
        break;
    case 'D':
        printf("1.00\n");
        break;
    case 'E':
        printf("0.00\n");
        break;
    }
    return 0;
}