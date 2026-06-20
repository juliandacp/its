#include <stdio.h>

int main() {
    int n, kapital=1;
    scanf("%d", &n);
    if(n==0){
        printf("Nol");
        return 0;
    }
    if(n>=100 && n<1000){
        int ratus=n/100;
        if(ratus==1) printf("Seratus");
        else if(ratus==2) printf("Dua ratus");
        else if(ratus==3) printf("Tiga ratus");
        else if(ratus==4) printf("Empat ratus");
        else if(ratus==5) printf("Lima ratus");
        else if(ratus==6) printf("Enam ratus");
        else if(ratus==7) printf("Tujuh ratus");
        else if(ratus==8) printf("Delapan ratus");
        else if(ratus==9) printf("Sembilan ratus");
        n%=100;
        kapital=0;
        if(n>0) printf(" ");
    }
    if(n>=10 && n<=19){
        if(kapital){
            if(n==10) printf("Sepuluh");
            else if(n==11) printf("Sebelas");
            else if(n==12) printf("Dua belas");
            else if(n==13) printf("Tiga belas");
            else if(n==14) printf("Empat belas");
            else if(n==15) printf("Lima belas");
            else if(n==16) printf("Enam belas");
            else if(n==17) printf("Tujuh belas");
            else if(n==18) printf("Delapan belas");
            else if(n==19) printf("Sembilan belas");
        }else{
            if(n==10) printf("sepuluh");
            else if(n==11) printf("sebelas");
            else if(n==12) printf("dua belas");
            else if(n==13) printf("tiga belas");
            else if(n==14) printf("empat belas");
            else if(n==15) printf("lima belas");
            else if(n==17) printf("tujuh belas");
            else if(n==18) printf("delapan belas");
            else if(n==19) printf("sembilan belas");
        }
        n=0;
        kapital=0;
    } 
    else if(n>=20 && n<100) {
        int puluh=n/10;
        if(kapital){
            if(puluh==2) printf("Dua puluh");
            else if(puluh==3) printf("Tiga puluh");
            else if(puluh==4) printf("Empat puluh");
            else if(puluh==5) printf("Lima puluh");
            else if(puluh==6) printf("Enam puluh");
            else if(puluh==7) printf("Tujuh puluh");
            else if(puluh==8) printf("Delapan puluh");
            else if(puluh==9) printf("Sembilan puluh");
        }else{
            if(puluh==2) printf("dua puluh");
            else if(puluh==3) printf("tiga puluh");
            else if(puluh==4) printf("empat puluh");
            else if(puluh==5) printf("lima puluh");
            else if(puluh==6) printf("enam puluh");
            else if(puluh==7) printf("tujuh puluh");
            else if(puluh==8) printf("delapan puluh");
            else if(puluh==9) printf("sembilan puluh");
        }
        n%=10;
        kapital=0;
        if(n>0) printf(" ");
    }
    if(n>0 && n<10){
        if(kapital){
            if(n==1) printf("Satu");
            else if(n==2) printf("Dua");
            else if(n==3) printf("Tiga");
            else if(n==4) printf("Empat");
            else if(n==5) printf("Lima");
            else if(n==6) printf("Enam");
            else if(n==7) printf("Tujuh");
            else if(n==8) printf("Delapan");
            else if(n==9) printf("Sembilan");
        }else{
            if(n==1) printf("satu");
            else if(n==2) printf("dua");
            else if(n==3) printf("tiga");
            else if(n==4) printf("empat");
            else if(n==5) printf("lima");
            else if(n==6) printf("enam");
            else if(n==7) printf("tujuh");
            else if(n==8) printf("delapan");
            else if(n==9) printf("sembilan");
        }
    }
    return 0;
}