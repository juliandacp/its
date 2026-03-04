#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
#define mod 1000000007

int main() {
    int N, K, P;
    scanf("%d %d %d", &N, &K, &P);
    int a[N+5], b[N+5];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    int dp[2][K+5][P+5];
    for(int i=0; i<2; i++){
        for(int k=0; k<=K; k++){
            for(int p=0; p<=P; p++){
                dp[i][k][p] = 0;
            }
        }
    }
    dp[0][0][0]=1;
    for(int i=1; i<=N; i++){
        int now=i%2;
        int prev=1-now;
        for(int k=0; k<=K; k++){
            for(int p=0; p<=P; p++){
                dp[now][k][p]=dp[prev][k][p];
            }
        }
        for(int j=1;j<=a[i];j++){
            int cost=j*b[i];
            if(cost>P) break;
            for(int k=j; k<=K; k++){
                for(int p=cost; p<=P; p++){
                    dp[now][k][p]=(dp[now][k][p]+dp[prev][k-j][p-cost])%mod;
                }
            }
        }
    }   
    printf("%d\n", dp[N%2][K][P]);
    return 0;
}