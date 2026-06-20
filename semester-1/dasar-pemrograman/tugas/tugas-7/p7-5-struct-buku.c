#include<stdio.h>

struct Buku{
    char judul[100];
    char penulis[100];
    int tahunTerbit;
};

int main(){
    struct Buku buku;
    scanf("%[^\n]%*c", buku.judul);
    scanf("%[^\n]%*c", buku.penulis);
    scanf("%d", &buku.tahunTerbit);
    printf("Judul: %s, Penulis: %s, Tahun Terbit: %d\n", buku.judul, buku.penulis, buku.tahunTerbit);
 return 0;
}