#include<stdio.h>

int search(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            return i;
        }
    }
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
    printf("%d\n", search(arr, n, x));
    return 0;
}