#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long

int bil_prima[15];
int memo[605][605];
int arr_temp[605];

void prima(){
    for(int i=0; i<=10; i++){
        bil_prima[i]=1;
    }
    bil_prima[0]=0;
    bil_prima[1]=0;
    for(int i=2; i*i<=10; i++){
        if(bil_prima[i]){
            for(int j=i*i; j<=10; j+=i){
                bil_prima[j]=0;
            }
        }
    }
}

int gcd(int A, int B){
    if(B==0) return A;
    return gcd(B, A%B);
}

void isi_memo(int N){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            memo[i][j]=-1;
        }
    }
}

int max_score(int arr[], int left, int right){
    if(right-left==1){
        memo[left][right] = 0;
        return 0;
    }
    if(memo[left][right]!=-1) return memo[left][right];
    int max_val=0;
    for(int i=left+1; i<=right-1; i++){
        int left_val = arr[left];
        int right_val = arr[right];
        int current_score=0;
        if(bil_prima[arr[i]]) current_score = arr[i]*2*gcd(left_val, right_val);
        else current_score=left_val*arr[i]*right_val;
        int total_score=current_score+max_score(arr, left, i)+max_score(arr, i, right);
        if(total_score>max_val) max_val=total_score;
    }
    memo[left][right]=max_val;
    return max_val;
}

int find_max_score(int arr[], int N){
    isi_memo(N+2);
    arr_temp[0] = 1;
    for(int i=1; i<=N; i++){
        arr_temp[i] = arr[i-1];
    }
    arr_temp[N+1]=1;
    return max_score(arr_temp, 0, N+1);
}

int main(){
    prima();
    int N, M;
    scanf("%d", &N);
    int A[N+5];
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    int B[M+5];
    for(int i=0; i<M; i++){
        scanf("%d", &B[i]);
    }
    int score_player=find_max_score(A, N);
    int score_rival=find_max_score(B, M);
    if(score_player>score_rival) printf("Pop: %d > %d\n", score_player, score_rival);
    else if(score_player<score_rival) printf("Flop: %d < %d\n", score_player, score_rival);
    else printf("Draw: %d = %d\n", score_player, score_rival);
    return 0;
}
