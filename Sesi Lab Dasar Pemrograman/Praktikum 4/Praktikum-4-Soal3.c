#include<stdio.h>
#include<stdlib.h>

void magician(long long *a1, long long *a2, long long *x, long long *res){
    if(*x==1) *res=*a1;
    else if(*x==2) *res=*a2;
    else{
        long long prev=*a1;
        long long cur=*a2;
        long long sum;
        for(int i=3; i<=*x; i++){
            sum=prev+cur;
            prev=cur;
            cur=sum;
        }
        *res=cur;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    long long a1, a2, x;
    for(int i=0; i<t; i++){
        scanf("%lld %lld %lld", &a1, &a2, &x);
        long long res;
        magician(&a1, &a2, &x, &res);
        printf("%lld\n", res);
    }
    return 0;
}