#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

int max_bangau(int K, ll t_min){
    int low=0, high=1000;
    while(low<=high){
        int mid=(low+high)/2;
        ll time=K*mid*(mid+1)/2;
        if(time<=t_min) low = mid + 1;
        else high=mid-1;
    }
    return high;
}

int can_complete(int N, int M, int skill[], ll t_min) {
    ll total_bangau=0;
    for (int i=0; i<M; i++){
        total_bangau+=max_bangau(skill[i], t_min);
        if(total_bangau>=N) return 1;
    }
    return total_bangau>=N;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        int M;
        scanf("%d", &M);
        int skill[M];
        for(int i=0; i<M; i++){
            scanf("%d", &skill[i]);
        }
        ll left=0, right=1;
        while(!can_complete(N, M, skill, right)){
            right*=2;
        }
        while(left<right){
            ll mid=left+(right-left)/2;
            if(can_complete(N, M, skill, mid)) right=mid;
            else left=mid+1;
        }
        printf("%lld\n", left);
    }
    return 0;
}