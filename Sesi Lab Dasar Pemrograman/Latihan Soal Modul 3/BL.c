#include<stdio.h>

int deret(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return deret(n-1) + deret(n-2);
}

int main(){
    int n;
    scanf("%d", &n);
    int hasil=deret(n);
    if(hasil%2==0) hasil*=321;
    else hasil*=123;
    printf("%d\n", hasil);
    if(hasil%5==0) printf("AKU TERJEBAK DALAM DUNIAKU\n");
    else printf("TERIMAKASIH LUPUT TELAH MENJADI PASANGANKU\n");
    return 0;
}