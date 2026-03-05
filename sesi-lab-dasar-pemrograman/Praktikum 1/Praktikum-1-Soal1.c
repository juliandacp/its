#include<stdio.h>
#include<math.h>

int main(){
    int x1, y1, x2, y2;
    float arah1;
    scanf("%d %d %f %d %d", &x1, &y1, &arah1, &x2, &y2);
    float arah2=atan2((y2-y1), (x2-x1));
    float selisih=fabs(arah1-arah2);
    if(x1==x2 && y1==y2) printf("Halo, Dan, aku Iel.");
    else if(selisih<0.01) printf("Aku akan berjalan lurus ke Dan!");
    else printf("Aku akan berputar ke arah tujuan!");
    return 0;
}