#include<stdio.h>

long long deretj(long long N, long long i, long long j){
    if(N==0) return i;
    if(N==1) return j;
    return deretj(N-1, i, j) + deretj(N-2, i, j);
}

long long deretr(long long N, long long i, long long j, long long k){
    if(N==0) return i;
    if(N==1) return j;
    return deretr(N-1, i, j, k) + deretr(N-2, i, j, k) - k;
}

int main(){
    long long N, i, j, k, hasil=0;
    scanf("%lld %lld %lld %lld", &N, &i, &j, &k);
    long long res1=deretj(N, i, j);
    long long res2=deretr(N, i, j, k);
    if(res1 > res2) hasil=res1-res2;
    else hasil=res2-res1;
    printf("%lld\n", hasil);
    return 0;
}
