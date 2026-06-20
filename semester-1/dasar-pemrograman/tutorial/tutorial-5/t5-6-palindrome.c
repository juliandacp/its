#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s[101];
    scanf("%s", s);
    int len = strlen(s);
    int palindrome = 1;
    for(int i = 0; i < len / 2; i++){
        if (tolower(s[i]) != tolower(s[len - i - 1])) {
            palindrome = 0;
            break;
        }
    }
    if(palindrome) printf("Palindrome\n");
    else printf("Bukan Palindrome\n");
    return 0;
}