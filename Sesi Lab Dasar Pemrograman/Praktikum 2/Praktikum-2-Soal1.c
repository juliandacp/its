#include<stdio.h>
#include<string.h>

int main(){
    char enkripsi[1000001];
    char dekripsi[1000001];
    scanf("%[^\n]s", enkripsi);
    char flag[]="[r0selleGustav]";
    int flag_len=strlen(flag);
    int enkripsi_len=strlen(enkripsi);
    int found=0;
    for(int geser=0; geser<=95; geser++){
        for(int i=0; i<enkripsi_len; i++){
                int temp=enkripsi[i]+geser;
                while(temp<32) temp+=95;
                while(temp>126) temp-=95;
                dekripsi[i]=temp;
        }
        dekripsi[enkripsi_len]='\0';
        if(enkripsi_len>=flag_len){
            int cek=1;
            for(int j=0; j<flag_len; j++){
                if(dekripsi[enkripsi_len-flag_len+j]!=flag[j]){
                    cek=0;
                    break;
                }
            }
            if(cek){
                printf("%s\n", dekripsi);
                found=1;
                break;
            }
        }
    }
    if(!found) printf("Unidentified Sequence.\n");
    return 0;
}