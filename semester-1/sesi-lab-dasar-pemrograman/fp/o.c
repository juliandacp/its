#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

int main(){
    int T, A;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &A);
        if(A%6==0) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}