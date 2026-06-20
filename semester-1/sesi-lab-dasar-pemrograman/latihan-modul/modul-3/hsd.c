#include<stdio.h>

unsigned long long vikturial(int n, int v){
    if(n<=0) return 1;
    else return n * vikturial(n-v, v);
}

int main(){
    int T;
    scanf("%d", &T);
    int n[T+5], v[T+5];
    for(int i=0; i<T; i++){
        scanf("%d %d", &n[i], &v[i]);
    }
    for(int i=0; i<T; i++){
        printf("%llu\n", vikturial(n[i], v[i]));
    }
    return 0;
}