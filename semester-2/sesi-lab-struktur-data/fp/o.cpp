#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    ll Q;
    cin >> Q;
    unordered_map<ll, ll> scores;
    ordered_set rank;
    while(Q--){
        string cmd;
        cin >> cmd;
        if(cmd == "ADD"){
            ll id, score;
            cin >> id >> score;
            if(scores.count(id)) cout << "FAIL" << endl;
            else{
                scores[id] = score;
                rank.insert({-score, id});
            }
        }else if(cmd == "UPDATE"){
            ll id, score;
            cin >> id >> score;
            if(!scores.count(id)) cout << "FAIL" << endl;
            else{
                rank.erase({-scores[id], id});
                scores[id] = score;
                rank.insert({-score, id});
            }
        }else if(cmd == "REMOVE"){
            ll id;
            cin >> id;
            if(!scores.count(id)) cout << "FAIL" << endl;
            else{
                rank.erase({-scores[id], id});
                scores.erase(id);
            }
        }else if(cmd == "RANK"){
            ll id;
            cin >> id;
            if(!scores.count(id)) cout << "FAIL" << endl;
            else cout << rank.order_of_key({-scores[id], id}) + 1 << endl;
        }else if(cmd == "KTH"){
            ll k;
            cin >> k;
            if(k < 1 || k > rank.size()) cout << "INVALID" << endl;
            else{
                auto it = rank.find_by_order(k - 1);
                cout << it->second << " " << -(it->first) << endl;
            }
        }else if(cmd == "MEDIAN"){
            if(rank.empty()) cout << "EMPTY" << endl;
            else{
                ll k = (rank.size() + 1) / 2;
                auto it = rank.find_by_order(k - 1);
                cout << it->second << " " << -(it->first) << endl;
            }
        }
    }
    return 0;
}
