#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int genap=0, ganjil=0;
    for(int i=0; i<n; i++){
        if(arr[i]%2==0) genap++;
        else ganjil++;
    }
    printf("%d\n", genap);
    printf("%d\n", ganjil);
    return 0;
}