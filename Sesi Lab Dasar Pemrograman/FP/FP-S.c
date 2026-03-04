#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

int main(){
    int n;
    scanf("%d", &n);
    ll bil=1;
    for(int i=0; i<=n; i++){
        if(i==0) bil=1;
        else bil=bil*(n-i+1)/i;
        printf("%lld", bil);
        if(i<n) printf(" ");
    }
    return 0;
}