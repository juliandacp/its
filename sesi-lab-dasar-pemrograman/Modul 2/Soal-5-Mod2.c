#include <stdio.h>
#include <string.h>

int main() {
    char S[101];
    int jmlh_A = 0, jmlh_I = 0, jmlh_U = 0, jmlh_E = 0, jmlh_O = 0;
    fgets(S, sizeof(S), stdin);
    for(int i=0; i<strlen(S); i++) {
        char s=S[i];
        if (s>='A' && s<='Z') {
            s+=32;
        }
        switch(s){
            case 'a': jmlh_A++; break;
            case 'i': jmlh_I++; break;
            case 'u': jmlh_U++; break;
            case 'e': jmlh_E++; break;
            case 'o': jmlh_O++; break;
        }
    }
    printf("A/a : %d\n", jmlh_A);
    printf("I/i : %d\n", jmlh_I);
    printf("U/u : %d\n", jmlh_U);
    printf("E/e : %d\n", jmlh_E);
    printf("O/o : %d\n", jmlh_O);
    return 0;
}