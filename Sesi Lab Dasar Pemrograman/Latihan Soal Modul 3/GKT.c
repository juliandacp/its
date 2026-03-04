#include<stdio.h>

int memo[1001];

int deret(int n){
    if(memo[n]!=-1) return memo[n];
    if(n==0) return memo[0]=0;
    if(n==1) return memo[1]=1;
    if(n==2) return memo[2]=2;
    return memo[n]=(deret(n-1) + deret(n-2) + deret(n-3)) % 100;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
        memo[i]=-1;
    }
    for(int i=n; i>=0; i--){
        printf("%d ", deret(i));
    }
    return 0;
}