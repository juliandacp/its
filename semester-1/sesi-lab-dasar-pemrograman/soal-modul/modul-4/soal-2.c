#include<stdio.h>
#include<string.h>

struct Nilai{
    char nama[10];
    int matematika;
    int ipa;
    int bi;
    int big;
};

int main(){
    int n, m;
    scanf("%d", &n);
    struct Nilai data[n];
    for(int i=0; i<n; i++){
        scanf("%s", data[i].nama);
        scanf("%d", &data[i].matematika);
        scanf("%d", &data[i].ipa);
        scanf("%d", &data[i].bi);
        scanf("%d", &data[i].big);
    }
    scanf("%d", &m);
    char cari_nama[10];
    for(int i=0; i<m; i++){
        scanf("%s", cari_nama);
        int find=0;
        for(int j = 0; j < n; j++){
            if(strcmp(cari_nama, data[j].nama) == 0){
                printf("Nilai %s\n", data[j].nama);
                printf("Matematika : %d\n", data[j].matematika);
                printf("IPA : %d\n", data[j].ipa);
                printf("Bahasa Indonesia : %d\n", data[j].bi);
                printf("Bahasa Inggris : %d\n", data[j].big);
                find=1;
                break;
            }
        }
        if(!find){
            printf("Nilai %s tidak ditemukan\n", cari_nama);
        }
    }
    return 0;
}