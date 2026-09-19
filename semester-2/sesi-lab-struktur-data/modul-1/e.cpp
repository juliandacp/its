#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int T;
    vector<int> data;
    cin >> T;
    while(T--){
        int input;
        cin >> input;
        if(input == 1){
            int x;
            cin >> x;
            data.push_back(x);
        }
        else if(input == 2){
            int x;
            cin >> x;
            for(int i = 0; i < data.size(); i++) data[i]+=x;
        }
        else if(input == 3){
            if(!data.empty()) data.pop_back();
            else{
                cout << "kosong woe\n";
            }
        }
        else if(input == 4){
            if(!data.empty()){
                for(int i = 0; i < data.size(); i++) cout << data[i] << " ";
                cout << endl;
            }else cout << "gaada isinya :(\n";
        }
        else if(input == 5){
            int y, x;
            cin >> y >> x;
            data.push_back(0);
            vector<int> temp = data;
            for(int i = y; i < data.size()-1; i++) data[i+1] = temp[i];
            data[y] = x;
        }
    }
    return 0;
}