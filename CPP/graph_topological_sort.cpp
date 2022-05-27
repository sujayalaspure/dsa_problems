#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int main() {
  int A = 6;
  vector<vector<int>> B = { { 6, 3 }, { 6, 1 }, { 5, 1 }, { 5, 2 }, { 3, 4 }, { 4, 2 } };

  // adjucency matrix

  vector<int> g[A + 1];
  vector<int> indeg(A + 1, 0);

  // u -> v

  for (int i = 0;i < B.size();i++) {
    int u = B[i][0];
    int v = B[i][1];
    g[u].push_back(v);
    indeg[v]++;
  }

  // initialize priority queue
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1;i <= A;i++) {
    if (indeg[i] == 0) pq.push(i);
  }

  // topological sort
  vector<int> ans;
  while (!pq.empty()) {
    int u = pq.top();
    pq.pop();
    // cout << u << " ";
    ans.push_back(u);
    for (int v : g[u]) {
      indeg[v]--;
      if (indeg[v] == 0) pq.push(v);
    }
  }

  // // check if there is a cycle
  // for (int i = 1;i <= A;i++) {
  //   if (indeg[i] != 0) {
  //     cout << "There is a cycle" << endl;
  //     return 0;
  //   }
  // }

  // print ans
  for (int i = ans.size() - 1;i >= 0;i--) {
    cout << ans[i] << " ";
  }






  return 0;
}