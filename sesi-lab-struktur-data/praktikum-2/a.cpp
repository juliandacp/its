#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL); 
    int N;
    cin >> N;
    vector<int> T(N + 1);
    unordered_map<int, int> idx;
    for(int i = 1; i <= N; i++){
        cin >> T[i];
    }
    int best_x = 0, best_y = N + 1;
    for(int i = 1; i <= N; i++){
        int target = 100 - T[i];
        if(idx.count(target)){
            int x = idx[target];
            int y = i;
            if(y < best_y || (y == best_y && x > best_x)){
                best_x = x;
                best_y = y;
            }
        }
        idx[T[i]] = i;
    }
    cout << best_x << endl << best_y << endl;
    return 0;
}