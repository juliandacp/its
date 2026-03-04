#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s[101];
    scanf("%[^\n]s", s);
    s[0]=toupper(s[0]);
    for(int i=1; i<strlen(s); i++){
        if(s[i-1]==' ' && s[i]!=' ') s[i]=toupper(s[i]);
        else s[i]=tolower(s[i]);
    }
    printf("%s", s);
    return 0;
}