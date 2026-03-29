#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    cin >> s;
    queue<int> darsu, sudar;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'D') darsu.push(i);
        else sudar.push(i);
    }
    while(!darsu.empty() && !sudar.empty()){
        int da = darsu.front();
        darsu.pop();
        int su = sudar.front();
        sudar.pop();
        if(da < su) darsu.push(da + s.size());
        else sudar.push(su + s.size());
    }
    if(!darsu.empty()) cout << "Darsu" << endl;
    else cout << "Sudar" << endl;
    return 0;
}