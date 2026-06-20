#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        printf("%d\n", i % M);
    }
return 0;
}