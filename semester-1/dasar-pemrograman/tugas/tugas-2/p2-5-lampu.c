#include<stdio.h>

int main(){
    char karakter;
    scanf("%c", &karakter);
    if(karakter=='R' || karakter=='r') printf("Berhenti\n");
    else if(karakter=='Y' || karakter=='y') printf("Hati-hati\n");
    else if(karakter=='G' || karakter=='g') printf("Jalan\n");
    return 0;
}