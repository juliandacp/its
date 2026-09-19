#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N;
    cin >> N;
    deque<char> d1, d2, d3;
    while(N--){
        char macaroni;
        cin >> macaroni;
        d1.push_front(macaroni);
    }
    int T;
    cin >> T;
    while(T--){
        string perintah;
        cin >> perintah;
        if(perintah == "PULL"){
            int x;
            cin >> x;
            if(x > d1.size()){
                cout << "Macaron Furina tidak sebanyak itu pls!" << endl;
                continue;
            }
            while(x > 1){
                d3.push_front(d1.front());
                d1.pop_front();
                x--;
            }
            d2.push_front(d1.front());
            d1.pop_front();
            while(!d3.empty()){
                d1.push_front(d3.back());
                d3.pop_back();
            }
        }
        else if(perintah == "PUT"){
            while(!d2.empty()){
                d1.push_front(d2.front());
                d2.pop_front();
            }
        }else cout << "Apa itu? Furina tidak paham!" << endl;
    }
    while(!d1.empty()){
        cout << d1.back() << " ";
        d1.pop_back();
    }
    cout << endl;
    while(!d2. empty()){
        cout << d2.back() << " ";
        d2.pop_back();
    }
    return 0;
}