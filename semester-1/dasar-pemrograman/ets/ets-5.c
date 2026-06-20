#include<stdio.h>
#include<stdlib.h>

int main(){
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int tot1=0, tot2=0, sum=0;
    sum=abs(x1-x2)+abs(y1-y2);
    printf("%d\n", sum);
    return 0;
}
