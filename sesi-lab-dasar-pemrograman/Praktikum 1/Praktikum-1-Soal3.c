#include<stdio.h>

int main(){
     unsigned long long e, s, tes;
     scanf("%llu %llu", &e, &s);
     tes = e & s;
     if(tes==0) printf("hop on roblox!");
     else printf("we'll try again tomorrow :(");
     return 0;
}