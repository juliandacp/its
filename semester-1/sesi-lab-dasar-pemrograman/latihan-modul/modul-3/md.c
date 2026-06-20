#include<stdio.h>

int min(int A[], int p, int q){
    if(p==q) return A[p-1];
    int res=min(A, p+1, q);
    if(A[p-1]<res) return A[p-1];
    else return res;
}

int main(){
    int N, T;
    scanf("%d %d", &N, &T);

    int A[N+5];
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    int p[N+5], q[N+5];
    for(int i=0; i<T; i++){
        scanf("%d %d", &p[i], &q[i]);
    }
    for(int i=0; i<T; i++){
        printf("%d\n", min(A, p[i], q[i]));
    }
    return 0;
}