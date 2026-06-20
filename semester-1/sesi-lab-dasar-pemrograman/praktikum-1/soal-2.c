#include<stdio.h>

int main(){
    long a, b, c, miring, s1, s2, st;
    scanf("%ld %ld %ld", &a, &b, &c);
    if(a>0 && b>0 && c>0){
        if(a!=b && b!=c && c!=a){
            if(a>=b && a>=c){
                miring=a*a;
                s1=b*b;
                s2=c*c;
                st=s1+s2;
                if(miring==st) printf("Yatta, aku bisa membentuk segitiga!");
                else printf("Gomenasai, segitiga tidak dapat dibuat.");
            }else if(b>=a && b>=c){
                miring=b*b;
                s1=a*a;
                s2=c*c;
                st=s1+s2;
                if(miring==st) printf("Yatta, aku bisa membentuk segitiga!");
                else printf("Gomenasai, segitiga tidak dapat dibuat.");
            }else{
                miring=c*c;
                s1=a*a;
                s2=b*b;
                st=s1+s2;
                if(miring==st) printf("Yatta, aku bisa membentuk segitiga!");
                else printf("Gomenasai, segitiga tidak dapat dibuat.");
            }
        }else{
            printf("Gomenasai, segitiga tidak dapat dibuat.");
        }
    }else{
        printf("Gomenasai, segitiga tidak dapat dibuat.");
    }
    return 0;
}
