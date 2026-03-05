#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

int total_biaya=0;

void peti(int no, int from, int to){
    int jarak=abs(from-to);
    int biaya=no*jarak;
    total_biaya+=biaya;
    printf("Crate %d, Zone %d -> Zone %d (Cost: %d)\n", no, from, to, biaya);
}

void tumpukan(int jumlah_peti, int A, int C, int B){
    if(jumlah_peti==0) return;
    if(jumlah_peti==1){
        peti(jumlah_peti, A, C);
        return;
    }
    tumpukan(jumlah_peti-1, A, B, C);
    peti(jumlah_peti, A, C);
    tumpukan(jumlah_peti-1, B, C, A);
}

int main(){
    int N;
    scanf("%d", &N);
    tumpukan(N, 1, 3, 2);
    printf("%d\n", total_biaya);
    return 0;
}
