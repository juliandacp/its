#include<stdio.h>

int main(){
    int T, N;
    int total_buku=0;
    int buku_prima=0;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &N);
        total_buku+=N;
        for(int j=0; j<N; j++){
            int A;
            scanf("%d", &A);
            int prima=1;
            if(A<2){
                prima=0;
            }else{
                for(int k=2; k*k<=A; k++){
                    if(A%k==0){
                        prima=0;
                        break;
                    }
                }
            }
            if(prima) buku_prima++;
        }
    }
    if(buku_prima==total_buku) printf("Cici senang, bot Mr. Biti berhasil ngirim semua buku\n");
    else if(buku_prima==0) printf("Cici sedih, bot Mr. Biti gak ngirim apa apa\n");
    else printf("Cici kecewa, bot Mr. Biti cuman kirim %d dari %d buku\n", buku_prima, total_buku);
    return 0;
}