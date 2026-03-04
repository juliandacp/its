#include<stdio.h>
#include<string.h>

int main(){
    char kalimat[201];
    fgets(kalimat, sizeof(kalimat), stdin);
    if(kalimat[strlen(kalimat)-1] == '\n') kalimat[strlen(kalimat)-1] = '\0';
    char *token = strtok(kalimat, " ");
    int count = 0;
    while (token != NULL){
        count++;
        token = strtok(NULL, " ");
    }
    printf("%d\n", count);
    return 0;
}