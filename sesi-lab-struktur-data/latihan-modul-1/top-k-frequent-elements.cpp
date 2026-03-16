#include <bits/stdc++.h>
using namespace std;

struct elements{
    int value;
    int freq;
    bool operator<(const elements& other) const{
        return freq < other.freq;
    }
};

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        priority_queue<elements> pq;
        int n = nums.size();
        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) count++;
            else{
                elements temp;
                temp.value = nums[i-1];
                temp.freq = count;
                pq.push(temp);
                count = 1;
            }
        }
        elements temp;
        temp.value = nums[n-1];
        temp.freq = count;
        pq.push(temp);
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().value);
            pq.pop();
        }
        return ans;
    }
};

/*
int main(){
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;
    vector<int> ans = topKFrequent(nums, k);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
}
*/