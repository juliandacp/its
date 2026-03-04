#include<stdio.h>

int max(int arr[], int n) {
    if(n == 1){
        return arr[0];
    }
    int temp = max(arr+1, n-1);
    if(arr[0] > temp){
        return arr[0];
    }else{
        return temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", max(arr, n));
    return 0;
}