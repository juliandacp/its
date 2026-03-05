#include<stdio.h>

int main(){
    int n, ori, temp, reverse=0;
    scanf("%d", &n);
    ori=n;
    while(n!=0){
        temp=n%10;
        reverse=reverse*10+temp;
        n/=10;
    }
    if(ori==reverse) printf("YA\n");
    else printf ("TIDAK\n");
    return 0;
}