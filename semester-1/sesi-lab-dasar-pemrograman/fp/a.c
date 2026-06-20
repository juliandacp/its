#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ll D, M, N;
        scanf("%lld %lld %lld", &D, &M, &N);
        if(D<0){
            printf("NO\n");
            continue;
        }
        if(D==0){
            printf("YES\n");
            continue;
        }
        double akar4=sqrt(sqrt((double)D));
        ll hasil=(ll)(akar4+0.5);
        int found=0;
        ll cek=-1;
        for(ll bil=hasil-1; bil<=hasil+1; bil++){
            if(bil<0) continue;
            ll bil2=bil*bil;
            ll bil4=bil2*bil2;
            if(bil4==D){
                cek=bil;
                found=1;
                break;
            }
        }
        if(!found){
            printf("NO\n");
            continue;
        }
        if(cek<=N-M) printf("YES\n");
        else printf("NO\n");
    }
  
    return 0;
}