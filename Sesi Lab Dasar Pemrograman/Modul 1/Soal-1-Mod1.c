#include <stdio.h>

int main() {
    int n, ratusan, puluhan, satuan, pangkat, sum=0;
    scanf("%d", &n);
    if(n>=0 && n<10){
        printf("Merupakan Bilangan Armstrong");
        return 0;
    }else if(n>10 && n<1000){
        if(n<100){
            puluhan=n/10;
            satuan=n%10;
            sum=puluhan*puluhan+satuan*satuan;
        }
        else if(n>=100 && n<1000){
            ratusan=n/100;
            puluhan=(n/10)%10;
            satuan=n%10;
            sum=ratusan*ratusan*ratusan+puluhan*puluhan*puluhan+satuan*satuan*satuan;
        }
        if(sum==n) printf("Merupakan Bilangan Armstrong");
        else printf("Bukan Merupakan Bilangan Armstrong");
    }
    return 0;
}