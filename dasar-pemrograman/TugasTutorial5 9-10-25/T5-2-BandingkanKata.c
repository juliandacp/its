#include<stdio.h>
#include<string.h>

int main(){
    char kata1[101], kata2[101];
    scanf("%s", kata1);
    scanf("%s", kata2);
    if (strcmp(kata1, kata2) == 0) printf("Sama\n");
    else printf("Berbeda\n");
    return 0;
}