#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s[201];
    scanf("%[^\n]s", s);
    char kalimat[201];
    int idx=0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]!=' ') kalimat[idx++]=tolower(s[i]);
    }
    kalimat[idx]='\0';
    int cek=1;
    for(int i=0; i<strlen(kalimat)/2; i++){
        if(kalimat[i]!=kalimat[strlen(kalimat)-i-1]){
            cek=0;
            break;
        }
    }
    if(cek) printf("Palindrome\n");
    else printf("Bukan Palindrome\n");
    return 0;
}