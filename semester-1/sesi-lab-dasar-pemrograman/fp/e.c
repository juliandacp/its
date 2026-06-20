#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

char hasil[1000005];
ll jumlah[10][1000005];

ll f(ll x){
    if(x==0) return 1;
    if(x%10==0) return f(x/10);
    return (x%10)*f(x/10);
}

ll g(ll x){
    while(x>=10) x=f(x);
    return x;
}

int main(){
    ll Q;
    scanf("%lld", &Q);
    for(ll i=1; i<=1000000; i++){
        hasil[i]=g(i);
    }
    for(ll i=1; i<=9; i++){
        jumlah[i][0]=0;
    }
    for(ll i=1; i<=1000000; i++){
        for(ll j=1; j<=9; j++){
            jumlah[j][i]=jumlah[j][i-1]+(hasil[i]==j);
        }
    }
    while(Q--){
        ll C, G, K;
        scanf("%lld %lld %lld", &C, &G, &K);
        ll hasil_akhir=jumlah[K][G]-jumlah[K][C-1];
        printf("%lld\n", hasil_akhir);
    }
    return 0;
}