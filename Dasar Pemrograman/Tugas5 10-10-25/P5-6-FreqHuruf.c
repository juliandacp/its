#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s[101];
    scanf("%[^\n]s", s);
    int count[27]={0};
    for(int i=0; i<strlen(s); i++){
        char c=tolower(s[i]);
        if(c>='a' && c<='z') count[c-'a']++;
    }
    for(int i=0; i<26; i++){
        char huruf='a'+i;
        if(count[i]>0) printf("%c: %d\n", huruf, count[i]);
    }
    return 0;
}