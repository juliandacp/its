#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n+1];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int total_unik=0;
    for(int i=0; i<n; i++){
        int unik=1;
        for(int j=0; j<n; j++){
            if(i!=j && arr[i]==arr[j]){
            unik=0;
            break;
            }
        }
        if(unik){
            total_unik++;
            printf("%d ", arr[i]);
        }
    }
    if(total_unik==0) printf("-\n");
    else printf("\n");
    return 0;
}