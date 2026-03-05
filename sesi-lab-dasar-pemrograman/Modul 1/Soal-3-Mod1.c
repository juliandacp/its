#include <stdio.h>

int main() {
    int I1, I2, I3, I4, A, B, C, D, E, F, G, biner;
    scanf("%d %d %d %d", &I1, &I2, &I3, &I4);
    biner=(I1*8)+(I2*4)+(I3*2)+(I4*1);
    switch(biner){
        case 0:
            A = 1; B = 1; C = 1; D = 1; E = 1; F = 1; G = 0;
            break;
        case 1:
            A = 0; B = 1; C = 1; D = 0; E = 0; F = 0; G = 0;
            break;
        case 2:
            A = 1; B = 1; C = 0; D = 1; E = 1; F = 0; G = 1;
            break;
        case 3:
            A = 1; B = 1; C = 1; D = 1; E = 0; F = 0; G = 1;
            break;
        case 4:
            A = 0; B = 1; C = 1; D = 0; E = 0; F = 1; G = 1;
            break;
        case 5:
            A = 1; B = 0; C = 1; D = 1; E = 0; F = 1; G = 1;
            break;
        case 6:
            A = 1; B = 0; C = 1; D = 1; E = 1; F = 1; G = 1;
            break;
        case 7:
            A = 1; B = 1; C = 1; D = 0; E = 0; F = 0; G = 0;
            break;
        case 8:
            A = 1; B = 1; C = 1; D = 1; E = 1; F = 1; G = 1;
            break;
        case 9:
            A = 1; B = 1; C = 1; D = 1; E = 0; F = 1; G = 1;
            break;
        default:
            A = 0; B = 0; C = 0; D = 0; E = 0; F = 0; G = 0;
    }
    printf("%d %d %d %d %d %d %d", A, B, C, D, E, F, G);
    return 0;
}