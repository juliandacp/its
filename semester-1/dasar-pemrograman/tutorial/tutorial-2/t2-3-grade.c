#include <stdio.h>

int main(){
    int nilai;
    scanf("%d", &nilai);
    if(nilai>=85) printf("A\n");
    else if(nilai>=70) printf("B\n");
    else if(nilai>=55) printf("C\n");
    else printf("D\n");
    return 0;
}