#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

int prima(int X){
    if(X<2) return 0;
    if(X==2) return 1;
    if(X%2==0) return 0;
    for(int i=3; i*i<=X; i+=2){
        if(X%i==0) return 0;
    }
    return 1;
}

int main(){
    int n, r;
    char X;
    scanf("%d %d", &n, &r);
    scanf(" %c", &X);
    char kode[105];
    for(int i=1; i<=n; i++){
        if(i==r) kode[i]=X;
        else{
            if(X=='A') kode[i] = 'C';
            else if(X=='B') kode[i] = 'A';
            else kode[i]='B';
        }
    }
    if(n%2==1){
        for(int i=2; i<=n; i+=2){
            if(i!=r) kode[i]=X;
        }
    }
    if(prima(r)){
        for(int i=1; i<=n; i++){
            if(i!=r && prima(i)){
                if(kode[i]=='A') kode[i]='B';
                else if(kode[i]=='B') kode[i]='C';
                else kode[i]='A';
            }
        }
    }
    int jumlah=0;
    for(int i=1; i<=n; i++){
        if(i!=r && kode[i]==X) jumlah++;
    }
    printf("%d\n", jumlah);
    return 0;
}