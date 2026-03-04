#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n+1];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int x, total=0;
    scanf("%d", &x);
    for(int i=0; i<n; i++){
        if(arr[i]==x) total+=1;
    }
    printf("%d\n", total);
    return 0;
}