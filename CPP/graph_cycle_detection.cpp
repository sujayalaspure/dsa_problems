#include <iostream>
#include <vector>
#include<queue>

using namespace std;


void bfs(vector<vector<int>>& g, vector<bool>& vis, int s) {
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (vis[v] == false) {
        q.push(v);
        vis[v] = true;
      }
    }
  }

  // return vis[d];

}

int findCC(vector<vector<int>>& g, vector<bool>& vis, int A) {
  // vector<bool> vis(A + 1, false);
  int count = 0;
  for (int i = 1;i <= A;i++) {
    if (vis[i] == false) {
      bfs(g, vis, i);
      count++;
    }
  }
  return count;
}

int main() {

  int A = 5;
  vector<vector<int>> B = { {1, 2},{1, 3},{2, 3},{1, 4},{4, 5} };

  vector<vector<int>> g(A + 1);
  vector<bool> vis(A + 1, false);

  for (int i = 0;i < B.size();i++) {
    int u = B[i][0];
    int v = B[i][1];
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int cc = findCC(g, vis, A);
  if (B.size() - 1 == A - cc) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }

  return 0;
}