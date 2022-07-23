#include <iostream>
#include <vector>
#include<queue>
using namespace std;


int bfs(int A, vector<vector<int>> B, int s, int d) {
  vector<int> g[A + 1];
  vector<bool> vis(A + 1, false);

  for (int i = 0;i < B.size();i++) {
    int u = B[i][0];
    int v = B[i][1];
    g[u].push_back(v);
    g[v].push_back(u);
  }

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

  return vis[d];

}


void dfs(vector<vector<int>>& g, vector<int>& vis, int source) {
  if (vis[source]) return;
  vis[source] = true;
  for (int i = 0;i < g[source].size();i++) {
    int v = g[source][i];
    dfs(g, vis, v);
  }
}

int main() {
  int A = 6;
  vector<vector<int>> B = { { 6, 3 }, { 6, 1 }, { 5, 1 }, { 5, 2 }, { 3, 4 }, { 4, 2 } };



  return 0;
}