#include<stdio.h>
#include<string.h>

int main(){
    char arr[1001];
    scanf("%s", arr);
    int jumlah=0;
    int valid=1;
    for(int i=0; i<strlen(arr); i++){
        if(arr[i]=='(') jumlah++;
        else if(arr[i]==')'){
            if(jumlah<=0){
                valid=0;
                break;
            }
            jumlah--;
        }
    }
    if(jumlah==0 && valid) printf("Y\n");
    else printf("G\n");
    return 0;
}
