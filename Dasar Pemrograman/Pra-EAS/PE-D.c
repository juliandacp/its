#include<stdio.h>
#include<string.h>

void reverse(char s[], int left, int right){
    if(left>=right) return;
    char temp=s[right];
    s[right]=s[left];
    s[left]=temp;
    reverse(s, left+1, right-1);
}

int main(){
    char s[205];
    scanf("%s", s);
    int akhir=strlen(s)-1;
    reverse(s, 0, akhir);
    printf("%s\n", s);
    return 0;
}
