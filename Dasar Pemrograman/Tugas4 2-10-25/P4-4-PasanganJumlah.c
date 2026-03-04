#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n+1];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int t;
    int total=0;
    scanf("%d", &t);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==t) total++;
        }
    }
    printf("%d\n", total);
    return 0;
}