#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> inorder;
    vector<int> st;
    int cur = 1;
    while(cur <= n || !st.empty()){
        while(cur <= n){
            st.push_back(cur);
            cur = cur * 2;
        }
        cur = st.back();
        st.pop_back();
        inorder.push_back(cur);
        cur = cur * 2 + 1;
    }
    vector<int> value_index(n + 1);
    vector<int> index_rank(n);
    for(int i = 0; i < n; i++){
        int idx = inorder[i];
        value_index[idx] = a[i];
        index_rank[i] = idx;
    }
    for(int i = 0; i < n; i++){
        int idx = index_rank[i];
        if(idx == 1) cout << -1;
        else cout << value_index[idx / 2];
        if(i + 1 < n) cout << ' ';
    }
    cout << endl;
    return 0;
}