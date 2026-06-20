#include<stdio.h>

int sort(int arr[], int n){
    int low=0;
    int high=n-1;
    int mid=0;
    while(mid<=high){
        if(arr[mid]==0){
            int temp=arr[low];
            arr[low++]=arr[mid];
            arr[mid++]=temp;
        }else if(arr[mid]==1) mid++;
        else{
            int temp=arr[mid];
            arr[mid]=arr[high];
            arr[high--]=temp;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    for(int i=0; i<n; i++) {
        printf("%d", arr[i]);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
    return 0;
}