#include <stdio.h>
#include <math.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int terbesar=(a>b) ? a : b;
    int modulus=a%b;
    double pangkat=pow(a, b);
    printf("Bilangan terbesar: %d\n", terbesar);
    printf("Sisa pembagian: %d\n", modulus);
    printf("Pangkat: %.2lf\n", pangkat);
    return 0;
}