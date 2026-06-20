#include<stdio.h>

int sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n+5];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
