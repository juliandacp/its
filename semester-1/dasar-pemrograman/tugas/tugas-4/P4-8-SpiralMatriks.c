#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int matriks[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &matriks[i][j]);
        }
    }
    int atas=0, bawah=N-1;
    int kiri=0, kanan=N-1;
    while(atas<=bawah && kiri<=kanan){
        for(int j=kiri; j<=kanan; j++){
            printf("%d ", matriks[atas][j]);
        }
        atas++;
        for(int i=atas; i<=bawah; i++){
            printf("%d ", matriks[i][kanan]);
        }
        kanan--;
        if(atas <= bawah){
            for(int j=kanan; j>=kiri; j--){
                printf("%d ", matriks[bawah][j]);
            }
            bawah--;
        }
        if(kiri <= kanan){
            for(int i=bawah; i>=atas; i--){
                printf("%d ", matriks[i][kiri]);
            }
            kiri++;
        }
    }
    printf("\n");
    return 0;
}