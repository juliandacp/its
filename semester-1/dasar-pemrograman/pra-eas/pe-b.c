#include<stdio.h>
#include<string.h>

int main(){
    char s[205];
    scanf("%[^\n]s", s);
    for(int i=0; i<strlen(s); i++){
        char c=s[i];
        if(c==' ') printf(" ");
        else if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o') continue;
        else if(c=='A' || c=='I' || c=='U' || c=='E' || c=='O') continue;
        else printf("%c", c);
    }
    printf("\n");
    return 0;
}
