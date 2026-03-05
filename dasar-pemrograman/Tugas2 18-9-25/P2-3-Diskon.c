#include<stdio.h>

int main(){
    float total_belanja;
    scanf("%f", &total_belanja);
    if(total_belanja>=500000) total_belanja-=total_belanja*0.2;
    else if(total_belanja>=250000) total_belanja-=total_belanja*0.1;
    printf("%.2f\n", total_belanja);
    return 0;
}