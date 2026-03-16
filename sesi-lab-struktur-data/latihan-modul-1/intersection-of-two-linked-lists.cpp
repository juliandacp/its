#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while(ptrA != ptrB){
            if(ptrA == NULL) ptrA = headB;
            else ptrA = ptrA->next;
            if(ptrB == NULL) ptrB = headA;
            else ptrB = ptrB->next;
        }
        return ptrA;
    }
};

/*
int main(){
    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);
    c1->next = c2;
    c2->next = c3;
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = c1;
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = c1;
    ListNode* ans = getIntersectionNode(headA, headB);
    if(ans == NULL) cout << "No intersection" << endl;
    else cout << "Intersected at node with value: " << ans->val << endl;
    return 0;
}

int main(){
    int nA, nB;
    cin >> nA;
    vector<int> A(nA);
    for(int i = 0; i < nA; i++) cin >> A[i];
    cin >> nB;
    vector<int> B(nB);
    for(int i = 0; i < nB; i++) cin >> B[i];
    int pos;
    cin >> pos;
    ListNode* headA = new ListNode(A[0]);
    ListNode* curr = headA;
    vector<ListNode*> nodesA;
    nodesA.push_back(headA);
    for(int i = 1; i < nA; i++){
        curr->next = new ListNode(A[i]);
        curr = curr->next;
        nodesA.push_back(curr);
    }
    ListNode* headB = new ListNode(B[0]);
    curr = headB;
    for(int i = 1; i < nB; i++){
        curr->next = new ListNode(B[i]);
        curr = curr->next;
    }
    if(pos >= 0 && pos < nA) curr->next = nodesA[pos];
    ListNode* ans = getIntersectionNode(headA, headB);
    if(ans == NULL) cout << "No intersection\n";
    else cout << "Intersected at node with value: " << ans->val << endl;
    return 0;
}
*/