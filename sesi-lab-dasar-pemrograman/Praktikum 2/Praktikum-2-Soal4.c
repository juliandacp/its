#include<stdio.h>
#include<string.h>

int main(){
    int N;
    scanf("%d", &N);
    char S[201][51];
    int keluarga[201] = {0};
    int sahabat[201] = {0};
    int cowok[201] = {0};
    int cewek[201] = {0};
    for(int i=0; i<N; i++){
        int M;
        scanf("%d %s", &M, S[i]);
        for(int j=0; j<M; j++){
            char nomor[21];
            scanf("%s", nomor);
            char idx[9];
            idx[0]=nomor[0];
            idx[1]=nomor[1];
            idx[2]=nomor[2];
            idx[3]=nomor[4];
            idx[4]=nomor[5];
            idx[5]=nomor[7];
            idx[6]=nomor[8];
            idx[7]=nomor[9];
            idx[8]='\0';
            int cek_keluarga=1;
            int cek_sahabat=1;
            int cek_cowok=1;
            char idx_sebelum=idx[0];
            for(int k=1; k<8; k++){
                if(idx[k]!=idx[0]) cek_keluarga=0;
                if(idx[k]>idx_sebelum) cek_sahabat=0;
                if(idx[k]<idx_sebelum) cek_cowok=0;
                idx_sebelum=idx[k];
            }
            if(cek_keluarga) keluarga[i]++;
            else if(cek_sahabat) sahabat[i]++;
            else if(cek_cowok) cowok[i]++;
            else cewek[i]++;
        } 
    }
    int max_keluarga=0, max_sahabat=0, max_cowok=0, max_cewek=0;
    for(int i=0; i<N; i++){
        if(keluarga[i]>max_keluarga) max_keluarga=keluarga[i];
        if(sahabat[i]>max_sahabat) max_sahabat=sahabat[i];
        if(cowok[i]>max_cowok) max_cowok=cowok[i];
        if(cewek[i]>max_cewek) max_cewek=cewek[i];
    }
    printf("Cari kontak keluarga, hubungi ");
    int cek=1;
    for(int i=0; i<N; i++){
        if(keluarga[i]==max_keluarga){
            if(!cek) printf(", ");
            printf("%s", S[i]);
            cek=0;
        }
    }
    printf("\n");
    printf("Cari kontak sahabat, hubungi ");
    cek=1;
    for(int i=0; i<N; i++){
        if(sahabat[i]==max_sahabat){
            if(!cek) printf(", ");
            printf("%s", S[i]);
            cek=0;
        }
    }
    printf("\n");
    printf("Cari kontak cowok, hubungi ");
    cek=1;
    for(int i=0; i<N; i++){
        if(cowok[i]==max_cowok){
            if(!cek) printf(", ");
            printf("%s", S[i]);
            cek=0;
        }
    }
    printf("\n");
    printf("Cari kontak cewek, hubungi ");
    cek=1;
    for(int i=0; i<N; i++){
        if(cewek[i]==max_cewek){
            if(!cek) printf(", ");
            printf("%s", S[i]);
            cek=0;
        }
    }
    printf("\n");
    return 0;
}