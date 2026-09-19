#include <bits/stdc++.h>
using namespace std;

struct elements{
    int value;
    int dist;
    bool operator<(const elements& other) const{
        if(dist == other.dist) return value < other.value;
        return dist < other.dist;
    }
};

class Solution{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<elements> pq;
        for(int i = 0; i < arr.size(); i++){
            elements temp;
            temp.value = arr[i];
            temp.dist = abs(arr[i] - x);
            pq.push(temp);
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().value);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    int x = 3;
    vector<int> ans = findClosestElements(arr, k, x);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i != ans.size()-1) cout << ",";
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k, x;
    cin >> k >> x;
    vector<int> ans = findClosestElements(arr, k, x);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
*/