#include<stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n+5][m+5];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int k;
    scanf("%d", &k);
    int find=k-1;
    int sum=0;
    for(int i=0; i<m; i++){
        sum+=arr[find][i];
    }
    printf("%d\n", sum);
    return 0;
}
