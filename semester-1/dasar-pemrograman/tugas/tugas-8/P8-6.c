#include<stdio.h>
#include<stdbool.h>

int freq[200005];

int swap(int *xp, int *yp){
    int temp=*xp;
    *xp=*yp;
    *yp=temp;
}

int main(){
    int n;
    bool swapped;
    scanf("%d", &n);
    for(int i=0; i<200005; i++){
        freq[i]=0;
    }
    int arr[n+5];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        freq[arr[i]+100000]++;
    }
    for(int i=0; i<n; i++){
        swapped=false;
        for(int j=0; j<n-i-1; j++){
            if(freq[arr[j]+100000]<freq[arr[j+1]+100000]){
                swap(&arr[j], &arr[j+1]);
                swapped=true;
            }else if(freq[arr[j]+100000]==freq[arr[j+1]+100000] && arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
        if(i!=n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
