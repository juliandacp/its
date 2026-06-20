#include<stdio.h>
#include<string.h>

int cara(int hp) {
    if(hp==0) return 1;
    if(hp<0) return 0;
    return cara(hp-20) + cara(hp-50) + cara(hp-100);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        char nama_musuh[50];
        int hp;
        scanf("%*c");
        scanf("%[^\n]s", nama_musuh);
        scanf("%d", &hp);
        char s[10];
        scanf("%s", s);
        int sum=cara(hp);
        if(sum>0){
            printf("%s DAPAT DIKALAHKAN DENGAN %d CARA YANG BERBEDA!\n", nama_musuh, sum);
        }else{
            printf("KAVA JANGAN TERLALU KERAS MELAWAN %s\n", nama_musuh);
        }
    }
    return 0;
}