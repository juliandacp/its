#include <stdio.h>

int main(){
    float a, b;
    char op;
    scanf("%f %f %c", &a, &b, &op);
    switch(op){
    case '+':
    printf("%.2f\n", a+b);
    break;

    case '-':
    printf("%.2f\n", a-b);
    break;
    
    case '*':
    printf("%.2f\n", a*b);
    break;

    case '/':
    printf("%.2f\n", a/b);
    break;
    }
    return 0;
}