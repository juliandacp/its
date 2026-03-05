#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s[101];
    scanf("%s", s);
    int sum=0;
    for(int i=0; i<strlen(s); i++){
        s[i]=tolower(s[i]);
    }

    for(int i=0; i<strlen(s); i++){
        if(s[i]=='a') sum++;
        else if(s[i]=='i') sum++;
        else if(s[i]=='u') sum++;
        else if(s[i]=='e') sum++;
        else if(s[i]=='o') sum++;
    }
    printf("%d\n", sum);
    return 0;
}