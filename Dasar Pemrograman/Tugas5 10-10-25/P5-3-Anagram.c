#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char s1[101];
    char s2[101];
    scanf("%s", s1);
    scanf("%s", s2);
    int sum=0;
    if(strlen(s1)!=strlen(s2)){
        printf("TIDAK\n");
        return 0;
    }
    int count1[27]={0};
    int count2[27]={0};
    for(int i=0; i<strlen(s1); i++){
        char c=tolower(s1[i]);
        count1[c-'a']++;
    }
    for(int i=0; i<strlen(s2); i++){
        char c=tolower(s2[i]);
        count2[c-'a']++;
    }
    int cek=1;
    for(int i=0; i<26; i++){
        if(count1[i]!=count2[i]){
            cek=0;
            break;
        }
    }
    if(cek) printf("YA\n");
    else printf("TIDAK\n");
    return 0;
}