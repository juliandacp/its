#include<stdio.h>

int main(){
    unsigned short n;
    scanf("%hu", &n);
    int arr[n+5];
    for(int i=0; i<n; i++){
        scanf("%hu", &arr[i]);
    }
    for(int i=n-1; i>=0; i--){
        printf("%hu\n", arr[i]);
    }
    return 0;
}