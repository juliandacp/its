#include<stdio.h>

int countEven(int *arr, int n){
    int jumlah=0;
    for(int i=0; i<n; i++){
        if(*(arr+i)%2==0) jumlah++;
    }
    return jumlah;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n+5];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int total=countEven(&arr, n);
    printf("%d", total);
    return 0;
}
