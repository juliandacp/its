#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s[201];
    scanf("%[^\n]s", s);
    int idx=0;
    char kalimat[201];
    for(int i=0; i<strlen(s); i++){
        char c=tolower(s[i]);
        if(c=='a' || c=='i' || c=='u' ||c=='e' || c=='o') continue;
        kalimat[idx++]=s[i];
    }
    kalimat[idx]='\0';
    printf("%s\n", kalimat);
    return 0;
}