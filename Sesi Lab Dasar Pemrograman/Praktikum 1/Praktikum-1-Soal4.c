#include<stdio.h>

int main(){
    unsigned short d1, h1, m1, d2, h2, m2;
    char jenis, opsi;
    scanf("%hu %hu:%hu\n", &d1, &h1, &m1);
    scanf("%hu %hu:%hu\n", &d2, &h2, &m2);
    scanf("%c\n", &jenis);
    scanf("%c", &opsi);
    int hari, jam, menit, masuk, keluar, biaya=0;
    masuk=d1*24*60+h1*60+m1;
    keluar=d2*24*60+h2*60+m2;
    if(keluar<masuk){
        printf("Tidak mungkin");
    }
    else{
        int selisih=keluar-masuk;
        hari=selisih/(24*60);
        jam=(selisih%(24*60)/60);
        menit=(selisih%(24*60)%60);
        if(jenis=='M'){
            int total_jam=jam;
            if(hari>0){
                biaya=hari*150000+10000;
                if(menit>0) total_jam+=1;
                biaya+=total_jam*2000;
            }else{
                if(menit>0) total_jam+=1;
                if(total_jam>3) biaya+=10000+(total_jam-3)*2000;
                else biaya+=10000;
            }
        }else if(jenis=='S'){
            biaya+=3000;
            biaya+=hari*50000;
        }
        int potongan=0;
        int max_potongan=0;
        if(opsi=='b'){
            potongan=biaya*20/100;
            max_potongan=10000;
            if(potongan>max_potongan) potongan=max_potongan;
            biaya-=potongan;
        }
        else if(opsi=='c'){
            potongan=biaya*10/100;
            max_potongan=20000;
            if(potongan>max_potongan) potongan=max_potongan;
            biaya-=potongan;
        }
        printf("Anda telah berada di sini selama %d hari, %d jam, dan %d menit. Anda harus membayar sebesar %d rupiah", hari, jam, menit, biaya);
    }
    return 0;
}
