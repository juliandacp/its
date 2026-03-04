#include<stdio.h>
#include<string.h>

typedef struct{
    char cmd[105];
    int r,c,x;
    int len;
}Blob;

int main(){
    int n, r, c; 
    scanf("%d", &n);
    scanf("%d %d", &r, &c);
    int arr[r+5][c+5];
    Blob blob[n];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            arr[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &blob[i].r, &blob[i].c, &blob[i].x, &blob[i].len);
        scanf(" %s", blob[i].cmd);
        arr[blob[i].r][blob[i].c]+=blob[i].x;
    }
    int q; 
    scanf("%d", &q);
    for(int i=0; i<q; i++){
        int y;
        scanf("%d", &y);
        for(int j=0; j<blob[y].len; j++){
            if(blob[y].cmd[j]=='W') blob[y].r--;
            else if(blob[y].cmd[j]=='S') blob[y].r++;
            else if(blob[y].cmd[j]=='A') blob[y].c--;
            else if(blob[y].cmd[j]=='D') blob[y].c++;
            if(blob[y].x%2==1) blob[y].x=blob[y].x*3+ 1;
            else blob[y].x/=2;
            arr[blob[y].r][blob[y].c]+=blob[y].x;
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}