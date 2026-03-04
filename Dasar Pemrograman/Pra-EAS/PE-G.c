#include<stdio.h>

int sort(int arr[], int n){
    int total=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                total++;
            }
        }
    }
    return total;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n+5];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int total=sort(&arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("%d", total);
    return 0;
}
