#include <stdio.h>
#include <stdlib.h>

int main(){
    int a; scanf("%d", &a);
    int** arr = NULL;
    arr = (int**) realloc(arr, a*a * sizeof(int) + 5);
    for(int i = 0; i < a; i++) {
        arr[i] = (int*) malloc(a * sizeof(int) + 5);
        for(int j = 0; j < a; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int new;
    scanf("%d", &new);
    arr = (int**) realloc(arr, new*new * sizeof(int) + 5);
    for(int i = 0; i < new; i++) {
        arr[i] = (int*) realloc(arr[i], new * sizeof(int) + 5);
        for(int j = 0; j < new; j++) {
            scanf("%d", &arr[i][j]);
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < new; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
