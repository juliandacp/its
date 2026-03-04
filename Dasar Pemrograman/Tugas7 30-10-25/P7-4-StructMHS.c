#include<stdio.h>

typedef struct{
    char nama[100];
    int umur;
    double IPK;
}Mahasiswa;

int main(){
    Mahasiswa mhs;
    scanf("%s", mhs.nama);
    scanf("%d", &mhs.umur);
    scanf("%lf", &mhs.IPK);
    printf("Nama: %s, Umur: %d tahun, IPK: %.2lf\n", mhs.nama, mhs.umur, mhs.IPK);
    return 0;
}