#include<stdio.h>
#include<string.h>

typedef struct{
    char nama[105];
    int harga;
    int stok;
}Barang;

int main(){
    int n;
    scanf("%d", &n);
    Barang barang[n+5];
    for(int i=0; i<n; i++){
        scanf(" %s %d %d", barang[i].nama, &barang[i].harga, &barang[i].stok);
    }
    int min=0;
    int min_new;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(barang[i].harga<barang[j].harga && barang[i].harga!=barang[j].harga){
                min_new=i;
                if(barang[min].harga<=barang[min_new].harga) min=min;
                else min=min_new;
            }else{
                min_new=j;
                if(barang[min].harga<=barang[min_new].harga) min=min;
                else min=min_new;
            }
        }
    }
    printf("%s %d\n", barang[min].nama, barang[min].harga);
    return 0;
}
