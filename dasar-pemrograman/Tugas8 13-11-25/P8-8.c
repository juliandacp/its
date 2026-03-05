#include<stdio.h>
#include<stdlib.h>

long long sort(long long arr[], int n, long long X) {
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            long long selisih1=llabs(arr[j]-X);
            long long selisih2=llabs(arr[j+1]-X);
            int cek=0;
            if(selisih1>selisih2) cek=1;
            else if(selisih1==selisih2 && arr[j]>arr[j+1]) cek=1;
            if(cek){
                long long temp=arr[j];
                arr[j]=arr[j + 1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    long long x;
    scanf("%d %lld", &n, &x);
    long long arr[n];
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    sort(arr, n, x);
    for(int i=0; i<n; i++){
        printf("%lld", arr[i]);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
    return 0;
}