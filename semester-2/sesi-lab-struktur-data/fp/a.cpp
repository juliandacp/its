#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N;
    cin >> N;
    unordered_map<string, int> m;
    while(N--){
        string W;
        cin >> W;
        string prefix = "";
        for(int i = 0; i < W.size(); i++){
            prefix += W[i];
            m[prefix]++;
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        string S;
        cin >> S;
        cout << m[S] << endl;
    }
    return 0;
}