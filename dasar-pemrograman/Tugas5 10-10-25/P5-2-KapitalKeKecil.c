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
    printf("%s\n", s);
    return 0;
}