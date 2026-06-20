#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

ll gcd(ll A, ll B){
    if(B==0) return A;
    return gcd(B, A%B);
}

ll chi(ll A, ll B, ll *x, ll*y){
    if(B==0){
        *x=1;
        *y=0;
        return A;
    }
    ll x_new, y_new;
    ll fpb=chi(B, A%B, &x_new, &y_new);
    *x=y_new;
    *y=x_new-(A/B)*y_new;
    return fpb;
}

ll hitung_energi(ll kap_isi, ll kap_tampung, ll target){
    ll fpb=gcd(kap_isi, kap_tampung);
    ll a=kap_isi/fpb;
    ll b=kap_tampung/fpb;
    ll c=target/fpb;
    ll x, y;
    chi(a, b, &x, &y);
    x=(x%b+b)%b;
    ll minim=(x*c)%b;
    if(minim==0) minim=b;
    ll total_chi=minim*kap_isi;
    ll jumlah_kosong=(total_chi-target)/kap_tampung;
    ll energi=2*minim+2*jumlah_kosong;
    if(target<=kap_isi){
        ll alternatif=energi-2;
        if(alternatif>0) return alternatif;
    }
    return energi;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        ll A, B, X;
        scanf("%lld %lld %lld", &A, &B, &X);
        if(X==0){
            printf("0\n");
            continue;
        }
        if(X==A || X==B){
            printf("1\n");
            continue;
        }
        if((X>A && X>B) || (X%gcd(A, B)!=0)){
            printf("IMPOSSIBLE\n");
            continue;
        }
        ll strategi1=hitung_energi(A, B, X);
        ll strategi2=hitung_energi(B, A, X);
        if(strategi1<strategi2) printf("%lld\n", strategi1);
        else printf("%lld\n",strategi2);
    }
    return 0;
}