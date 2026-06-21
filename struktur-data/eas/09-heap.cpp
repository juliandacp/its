#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> maxHeap;

    maxHeap.push(1000);
    maxHeap.push(800);
    maxHeap.push(600);
    maxHeap.push(500);

    cout << "Produk terlaris: "
         << maxHeap.top() << endl;

    return 0;
}