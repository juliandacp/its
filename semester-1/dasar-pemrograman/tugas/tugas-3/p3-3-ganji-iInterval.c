#include<stdio.h>

int main(){
    int A, B, total=0;
    scanf("%d %d", &A, &B);
    A+=1;
    for(int i=A; i<B; i++){
        if(i%2==1) total+=i;
    }
    printf("%d\n", total);
    return 0;
}