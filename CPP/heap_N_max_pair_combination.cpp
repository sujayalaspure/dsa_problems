#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solve(vector<int>& A, vector<int>& B) {
  priority_queue<int, vector<int>, greater<int> > minHeap;
  int n = A.size();

  for (int i = 0;i < A.size();i++) {
    for (int j = 0;j < B.size();j++) {
      int ele = A[i] + B[j];
      cout << ele << " " << minHeap.size() << endl;

      if (minHeap.size() >= n) {
        if (!minHeap.empty() && minHeap.top() > ele) continue;
        minHeap.pop();
        minHeap.push(ele);
      }
      else {
        minHeap.push(ele);
      }
    }
  }
  vector<int> ans(n);
  cout << endl << "----" << minHeap.size() << endl;
  while (!minHeap.empty() && n > -1) {
    cout << n - 1 << " " << minHeap.top() << endl;
    ans[n - 1] = minHeap.top();
    minHeap.pop();
    n--;
  }
  // minHeap.pop();
  // ans[0] = minHeap.top();
  for (int i = 0;i < ans.size();i++) {
    cout << ans[i] << " ";
  }
  // ans[0]=minHeap.top();
  return ans;

}

int main() {

  vector<int>  A = { 3, 2, 4, 2 };
  vector<int> B = { 4, 3, 1, 2 };
  solve(A, B);

  return 0;
}