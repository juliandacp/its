#include<stdio.h>

int search_first(int arr[], int low, int high, int x){
    if (low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==x){
        if(mid==0 || arr[mid-1]!=x) return mid;
        else return search_first(arr, low, mid-1, x);
    }
    else if(x<arr[mid]) return search_first(arr, low, mid-1, x);
    else return search_first(arr, mid+1, high, x);
    return -1;
}

int search_last(int arr[], int low, int high, int x, int n) {
    if (low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==x){
        if(mid==n-1 || arr[mid+1]!=x) return mid;
        else return search_last(arr, mid+1, high, x, n);
    }
    else if(x<arr[mid]) return search_last(arr, low, mid-1, x, n);
    else return search_last(arr, mid+1, high, x, n);
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int x;
    scanf("%d", &x);
    printf("%d %d\n", search_first(arr, 0, n - 1, x), search_last(arr, 0, n - 1, x, n));    
    return 0;
}