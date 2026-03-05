#include<stdio.h>
#include<string.h>

int main(){
    char snake_case[100];
    char camelCase[100];
    int uppercase=0;
    fgets(snake_case, sizeof(snake_case), stdin);
    int j=0;
    for(int i=0; snake_case[i]!='\0'; i++){
        if(snake_case[i]=='_') uppercase=1;
        else{
            if(uppercase){
                if(snake_case[i]>='a' && snake_case[i]<='z') camelCase[j++]=snake_case[i]-32;
                else camelCase[j++]=snake_case[i];
                uppercase=0;
            }else{
                if(snake_case[i]>='A' && snake_case[i]<='Z') camelCase[j++]=snake_case[i]+32;
                else camelCase[j++]=snake_case[i];
            }
        }
    }
    camelCase[j]='\0';
    printf("%s\n", camelCase);
    return 0;
}