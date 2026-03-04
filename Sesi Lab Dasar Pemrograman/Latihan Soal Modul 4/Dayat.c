#include<stdio.h>
#include<string.h>

struct Scroll{
    char kode[1000];
    char tanda;
};

int main(){
    int n;
    int sama = 0;
    int angka[300] = {'\0'};
    scanf("%d", &n);
    struct Scroll Jumlah[n];
    for(int i=0; i<n; i++){
        scanf("%s %c", Jumlah[i].kode, &Jumlah[i].tanda);
    }
    for(int i=0; i<n; i++){
        int panjang = strlen(Jumlah[i].kode);
        for(int j=0; j<panjang; j++){
            if(Jumlah[i].kode[j]>='0' && Jumlah[i].kode[j]<='9'){
                angka[i]=angka[i]*10+(Jumlah[i].kode[j]-'0');
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if((angka[i]==angka[j]) && (Jumlah[i].tanda!=Jumlah[j].tanda) && angka[i]!=-1){
                angka[j]=-1;
                angka[i]=-1;
                sama++;
                break;
            }
        }
    }
    if(sama==0) printf("Tidak ada scroll yang berpasangan, kamu juga ga berpasangan\n");
    else if(sama != 0) printf("%d\n", sama);
    return 0;
}