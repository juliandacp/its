#include<stdio.h>

int main(){
    unsigned short jam;
    scanf("%hu", &jam);
    if(jam==0) printf("12 AM\n");
    else if(jam==12) printf("12 PM\n");
    else if(jam>12){
        jam%=12;
        printf("%hu PM\n", jam);
    }else printf("%hu AM\n", jam);
    return 0;
}