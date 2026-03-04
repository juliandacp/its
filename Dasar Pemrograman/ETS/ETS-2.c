#include<stdio.h>

int main(){
    int r;
    scanf("%d", &r);
    int x=3*r;
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            if(i==0 || i==x-1 || j==0 || j==x-1) printf("#");
            else if(j!=0 || j!=x-1) printf("_");
        }
        printf("\n");
    }
    return 0;
}
