#include<stdio.h>

int main(){
    int N, X, hasil=0, total1=0;
    scanf("%d %d", &N, &X);
    for(int i=0; i<N; i++){
        int bil;
        scanf("%d", &bil);
        while(bil>0){
            total1+=(bil&1);
            bil>>=1;
        }
    }
    hasil=total1/X;
    printf("%d %d\n", total1, hasil);
    if(total1%X==0) printf("ADIL NIH, TERIMAKASIH LAPET\n");
    else printf("UNTUK MEMPERERAT TALI SILATURAHMI, BOLEHKAH SAYA PINJAM DULU SERATUS");
    return 0;
}