#include<stdio.h>

int main(){
    int P, N, t, g;
    scanf("%d %d", &P, &N);
    t=P/N;
    g=P%N;
    printf("Teman-teman mendapatkan %d potong :)\n", t);
    printf("Ghifari mendapatkan %d potong :(\n", g);
    return 0;
}