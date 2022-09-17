#include <iostream>
#include <vector>
#include<deque>
using namespace std;
typedef pair<int, int> pp;

int dijkstra(vector<pair<int, int>>* g, int A, int s, int dest) {
  vector<int> dist(A + 1, INT_MAX - 1);
  dist[s] = 0;
  deque<pp> q;
  q.push_front({ 0, s });

  while (!q.empty()) {
    auto top = q.front();
    q.pop_front();
    int d = top.first;
    int u = top.second;

    if (d == dist[u]) {
      for (int i = 0; i < g[u].size(); i++) {
        auto dd = g[u][i];
        int v = dd.first;
        int w = dd.second;
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          if (w == 0) {
            q.push_front({ dist[v], v });
          }
          else
            q.push_back({ dist[v], v });
        }
      }
    }
  }
  return dist[dest] == INT_MAX - 1 ? -1 : dist[dest];
}


void solve(int A, vector<vector<int>>& B) {

  vector<pair<int, int>> g[A + 1];

  for (int i = 0;i < B.size();i++) {
    int u = B[i][0];
    int v = B[i][1];
    g[u].push_back(make_pair(v, 0));
    g[v].push_back(make_pair(u, 1));
  }
  cout << dijkstra(g, A, 1, A) << endl;
}
int main() {

  int A = 6;
  vector<vector<int>> B = {
  {1, 2},
  {2, 3},
  {3, 4},
  {4, 1},
  {2, 3},
  {4, 2},
  {3, 4},
  {5, 5},
  {5, 5},
  };

  // vector<vector<int>> B = {
  //   {1, 2} ,
  //   {2, 3},
  //   {4, 3},
  //   {4, 5}
  // };



  solve(A, B);

  return 0;
}