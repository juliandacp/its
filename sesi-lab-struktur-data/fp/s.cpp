#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
    int value;
    int left;
    int right;
};

pair<int, int> dfs(int curr_node, vector<Node> &tree_node){
    if(curr_node == -1) return {0, 0};
    pair<int, int> left_result = dfs(tree_node[curr_node].left, tree_node);
    pair<int, int> right_result = dfs(tree_node[curr_node].right, tree_node);
    int take_curr = tree_node[curr_node].value + left_result.second + right_result.second;
    int skip_curr = max(left_result.first, left_result.second) + max(right_result.first, right_result.second);
    return {take_curr, skip_curr};
}

int main(){
    int N;
    cin >> N;
    vector<int> level(N + 1);
    for(int i = 1; i <= N; i++) cin >> level[i];
    vector<Node> tree_node(N + 1);
    for(int i = 1; i <= N; i++){
        if(level[i] == -1) continue;
        tree_node[i].value = level[i];
        if(2 * i <= N && level[2 * i] != -1) tree_node[i].left = 2 * i;
        else tree_node[i].left = -1;
        if(2 * i + 1 <= N && level[2 * i + 1] != -1) tree_node[i].right = 2 * i + 1;
        else tree_node[i].right = -1;
    }
    pair<int, int> answer = dfs(1, tree_node);
    cout << max(answer.first, answer.second) << endl;
    return 0;
}