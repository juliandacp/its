#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    float sum=0;
    scanf("%d", &n);
    int arr[n+5];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        sum+=arr[i];
    }
    float avg;
    avg=sum/(float)n;
    int total=0;
    for(int i=0; i<n; i++){
        if(arr[i]>avg) total++;
    }
    printf("%d\n", total);
    return 0;
}
