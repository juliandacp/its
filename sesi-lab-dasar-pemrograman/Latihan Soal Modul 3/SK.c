#include<stdio.h>

int kuadronacci(int n, int a, int b, int c, int d){
    if(n==1) return a;
    if(n==2) return b;
    if(n==3) return c;
    if(n==4) return d;
    return kuadronacci(n-1, a, b, c, d) + kuadronacci(n-2, a, b, c, d) + kuadronacci(n-3, a, b, c, d) + kuadronacci(n-4, a, b, c, d);
}

int main(){
    int R, C, a, b, c, d;
    scanf("%d %d %d %d %d %d", &R, &C, &a, &b, &c, &d);
    int total=R*C;
    for(int i=1; i<=total; i++){
        printf("%d", kuadronacci(i, a, b, c, d));
        if(i%C==0) printf("\n");
        else printf(" ");
    }
    printf("\n");
    return 0;
}