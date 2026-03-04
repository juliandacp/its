#include<stdio.h>

int main(){
    int n, sum;
    int total=0;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        sum+=arr[i];
    }
    float mean=sum/(float)n;
    for(int i=0; i<n; i++){
        if(arr[i]>mean){
            printf("%d ", arr[i]);
            total+=1;
        }
    }
    if(total==0) printf("Tidak ada");
    printf("\n");
    return 0;
}
