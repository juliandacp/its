#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

typedef struct{
    char nama[101];
    ll harga;
    ll stok;
}Barang;

void print_katalog(Barang katalog[], int n){
    for(int i=0; i<n; i++){
        printf("%s %lld %lld\n", katalog[i].nama, katalog[i].harga, katalog[i].stok);
    }
}

void swap_barang(Barang *a, Barang *b){
    Barang tmp=*a;
    *a=*b;
    *b=tmp;
}

void sort_harga(Barang katalog[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(katalog[i].harga>katalog[j].harga){
                swap_barang(&katalog[i], &katalog[j]);
            }
        }
    }
}

void max_stock(Barang katalog[], int n){
    int idx=0;
    for(int i=1; i<n; i++){
        if(katalog[i].stok>katalog[idx].stok){
            idx=i;
        }
    }
    printf("%s %lld %lld\n", katalog[idx].nama, katalog[idx].harga, katalog[idx].stok);
}

void update_barang(Barang katalog[], int x, ll harga_baru, ll stok_baru){
    katalog[x].harga=harga_baru;
    katalog[x].stok=stok_baru;
}

int main(){
    int n;
    scanf("%d", &n);
    Barang katalog[n+5];
    for(int i=0; i<n; i++){
        scanf("%s %lld %lld", katalog[i].nama, &katalog[i].harga, &katalog[i].stok);
    }
    int m;
    scanf("%d", &m);
    char cmd[20];
    while(m--){
        scanf("%s", cmd);
        if(!strcmp(cmd, "PRINT")) print_katalog(katalog, n);
        else if(!strcmp(cmd, "SWAP")){
            int a, b;
            scanf("%d %d", &a, &b);
            swap_barang(&katalog[a], &katalog[b]);
        }
        else if(!strcmp(cmd, "SORT")) sort_harga(katalog, n);
        else if(!strcmp(cmd, "MAXSTOCK")) max_stock(katalog, n);
        else if(!strcmp(cmd, "UPDATE")){
            int x;
            ll harga_baru, stok_baru;
            scanf("%d %lld %lld", &x, &harga_baru, &stok_baru);
            update_barang(katalog, x, harga_baru, stok_baru);
        }
    }
    return 0;
}