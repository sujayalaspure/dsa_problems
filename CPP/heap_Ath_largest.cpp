#include <iostream>
#include <vector>
#include<queue>
using namespace std;


void minHeap() {
  vector<int> v = { 57, 3, -14, -87, 42, 38, 31, -7, -28, -61 };
  priority_queue<int, vector<int>, greater<int>> q;
  for (int a : v) {
    q.push(a);
  }

  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }

  cout << endl;

}

int main() {

  minHeap();
  vector<int> B = { 3, 15, 20, 90, 1 };
  int A = 2;

  vector<int> ans;
  int n = B.size();
  for (int i = 0; i < n;i++) {
    if (i < A - 1) {
      ans.push_back(-1);
    }
    else {
      sort(B.begin(), B.begin() + i + 1, greater<int>());
      ans.push_back(B[A - 1]);
    }

  }

  // for (int a : ans) {
  //   cout << a << " ";
  // }
  // cout << endl;


  return 0;
}