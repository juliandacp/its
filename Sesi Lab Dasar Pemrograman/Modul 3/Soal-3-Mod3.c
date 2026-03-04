#include<stdio.h>

long long max(long long arr[], int n){
    if(n==1){
        return arr[0];
    }
    long long temp=max(arr+1, n-1);
    if(arr[0]>temp){
        return arr[0];
    }else{
        return temp;
    }
}

long long min(long long arr[], int n){
    if(n==1){
        return arr[0];
    }
    long long temp=min(arr+1, n-1);
    if(arr[0]<temp){
        return arr[0];
    }else{
        return temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    long long arr[100005];
    for(int i=0; i<n; i++){
        scanf("%llu", &arr[i]);
    }
    printf("max: %lld\n", max(arr, n));
    printf("min: %lld\n", min(arr, n));
    return 0;
}