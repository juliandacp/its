#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

int main(){
    ll a, b, c, x, y;
    scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &x, &y);
    int lebah=(a+c>=x);
    int teman=(b+c>=y);
    int cukup=(a+b+c>=x+y);
    if(lebah && teman && cukup) printf("Okay, okay, okay, okay, okay, okay, gas bagiin ae Teto");
    else printf("WEH TAHAN DULU TETO, JAN DIBAGIIN DULU!");
    return 0;
}
