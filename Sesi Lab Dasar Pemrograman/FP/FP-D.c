#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll x1, x2, y1, y2;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        ll dx=x2-x1;
        ll dy=y2-y1;
        ll res=dx*dy+1;
        printf("%lld\n", res);
    }
    return 0;
}