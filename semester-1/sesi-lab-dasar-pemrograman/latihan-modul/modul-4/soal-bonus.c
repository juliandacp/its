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
    
    int new; scanf("%d", &new);
    arr = (int**) realloc(arr, new*new * sizeof(int) + 5);
    for(int i = 0; i < new; i++) {
        if(i < a) {
            arr[i] = (int*) realloc(arr[i], new*new*sizeof(int*) + 5);
            
            for(int j = a; j < new; j++) {
                arr[i][j] = 0;
            }
            
        } else {
            arr[i] = (int*) malloc(new*new*sizeof(int*) + 5);
            
            for(int j = 0; j < new; j++) {
                arr[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < new; i++) {
        for(int j = 0; j < new; j++) {
            printf("%d ", arr[i][j]);
        }
        free(arr[i]);
        printf("\n");
    }
    free(arr);

    return 0;
}
