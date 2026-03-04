#include <stdio.h>

struct Player{
    int HP;
    int ATK;
};

int main(){
    struct Player dataplayer1, dataplayer2;
    scanf("%d %d", &dataplayer1.HP, &dataplayer1.ATK);
    scanf("%d %d", &dataplayer2.HP, &dataplayer2.ATK);
    while(1){
        dataplayer2.HP -= dataplayer1.ATK;
        if(dataplayer2.HP <= 0){
            printf("player 1 menang dengan sisa nyawa = %d. GGWP!\n", dataplayer1.HP);
            break;
        }
        dataplayer1.HP -= dataplayer2.ATK;
        if(dataplayer1.HP <= 0){
            printf("player 2 menang dengan sisa nyawa = %d. Jago banget!\n", dataplayer2.HP);
            break;
        }
    }
    return 0;
}