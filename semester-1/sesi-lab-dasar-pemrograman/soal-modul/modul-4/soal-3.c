#include<stdio.h>

void reverse(int *arr, int a, int b){
    if(a>=b) return;
    int temp=*(arr+a);
    *(arr+a)=*(arr+b);
    *(arr+b)=temp;
    reverse(arr, a+1, b-1);
}

int main(){
    int n;
    scanf("%d", &n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    reverse(arr, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", *(arr+i));
    }
    return 0;
}