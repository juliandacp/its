#include<stdio.h>

int search(int arr[], int low, int high, int x) {
    if(low>high) return -1;                         
    int mid=(low+high)/2;
    if(arr[mid]==x) return mid;
    else if(x<arr[mid]) return search(arr, low, mid-1, x);
    else return search(arr, mid+1, high, x);
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n+5];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int x;
    scanf("%d", &x);
    printf("%d\n", search(arr, 0, n-1, x));
    return 0;
}