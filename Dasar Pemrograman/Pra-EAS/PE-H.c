#include<stdio.h>

int cari_kiri(int arr[], int n, int x){
    int low=0, high=n-1, result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            result=mid;
            high=mid-1;
        }
        else if(x<arr[mid]) high=mid-1;
        else low=mid+1;
    }
    return result;
}

int cari_kanan(int arr[], int n, int x){
    int low=0, high=n-1, result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            result=mid;
            low=mid+1;
        }
        else if(x<arr[mid]) high=mid-1;
        else low=mid+1;
    }
    return result;
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
    
    int kiri=cari_kiri(arr, n, x);
    int kanan=cari_kanan(arr, n, x);
    printf("%d\n", kanan-kiri+1);
    return 0;
}