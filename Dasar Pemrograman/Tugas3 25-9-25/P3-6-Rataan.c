#include<stdio.h>

int main(){
    int n, pembagi=0, total=0;
    scanf("%d", &n);
    while(n!=-999){
        pembagi+=1;
        total+=n;
        scanf("%d\n", &n);
    }
    float res;
    res=(float)total/pembagi;
    printf("%.2f\n", res);
    return 0;
}