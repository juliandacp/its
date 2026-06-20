#include<stdio.h>
#include<string.h>

int main(){
    char s1[100], s2[100], hasil[200];
    scanf("%s", s1);
    scanf("%s", s2);
    strcpy(hasil, s1);
    strcat(hasil, s2);
    printf("%s\n", hasil);
    return 0;
}