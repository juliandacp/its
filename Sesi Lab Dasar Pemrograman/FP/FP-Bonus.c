#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d", &n);
    char s[101];
    strcpy(s, "rlrllrllrlrrlrllrrrllrrrrrlrrlrrrlllrllrrrrrlrlllrrlrlllrlllrrlrlllrlllrrlllrllrllrrrrrrrlrlllrrlrrl");
    printf("%c", s[n]);
    return 0;
}