#include<stdio.h>
#include<string.h>

int main(){
    int N;
    char word[25];
    char grid[25][25];
    scanf("%d", &N);
    scanf("%s", word);
    int word_len=strlen(word);
    for(int i=0; i<N; i++){
        scanf("%s", grid[i]);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<=N-word_len; j++){
            int found=1;
            for(int k=0; k<word_len; k++){
                if(grid[i][j+k]!=word[k]){
                    found=0;
                    break;
                }
            }
            if(found){
                printf("ADA\n");
                return 0;
            }
        }
    }
    for(int i=0; i<=N-word_len; i++){
        for(int j=0; j<N; j++){
            int found=1;
            for(int k=0; k<word_len; k++){
                if(grid[i+k][j]!=word[k]){
                    found=0;
                    break;
                }
            }
            if(found){
                printf("ADA\n");
                return 0;
            }
        }
    }
    for(int i=0; i<=N-word_len; i++){
        for(int j=0; j<=N-word_len; j++){
            int found=1;
            for(int k=0; k<word_len; k++) {
                if(grid[i+k][j+k]!=word[k]){
                    found=0;
                    break;
                }
            }
            if(found){
                printf("ADA\n");
                return 0;
            }
        }
    }
    printf("TIDAK ADA\n");
    return 0;
}