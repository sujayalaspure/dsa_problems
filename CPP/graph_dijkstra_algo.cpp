#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int dijkstra(vector<vector<pair<int, int>>>& g, int A, int source) {
  auto compare = [](ii lhs, ii rhs) {
    return lhs.first < rhs.first;
  };
  int cost = INT_MIN;
  vector<int> dist(A + 1, INT_MAX);
  dist[source] = 0;
  priority_queue<ii, vector<ii>, decltype(compare)> minHeap(compare);

  minHeap.push({ 0, source });
  while (!minHeap.empty()) {
    int weight = minHeap.top().first;
    int u = minHeap.top().second;
    minHeap.pop();
    // cout << u << " ";
    if (weight == dist[u]) {
      for (int i = 0;i < g[u].size();i++) {
        // cout << u << " " << g[u][i].first << " " << g[u][i].second << endl;
        int v = g[u][i].first;
        int w = g[u][i].second;
        // cout << dist[u] + w << " " << dist[v] << endl;
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          cost = max(cost, dist[v]);
          minHeap.push({ dist[v], v });
        }
      }
    }
  }
  cout << "cost -> " << cost << endl;
  int total = 0;
  cout << endl;
  for (int i = 1;i <= A;i++) {
    total += dist[i];
    cout << dist[i] << " ";
  }
  cout << endl;
  cout << total << endl;


  return cost;

}


void solve(int A, vector<vector<int>> B) {
  // create a adjucency List with weight
  vector<vector<pair<int, int>>> g(A + 1);

  for (int i = 0;i < B.size();i++) {
    int u = B[i][0];
    int v = B[i][1];
    int w = B[i][2];
    g[u].push_back({ v, w });
    g[v].push_back({ u, w });
  }

  int ss = dijkstra(g, A, 1);
  cout << "dd-> " << ss << endl;
}

int main() {

  int A = 3;
  vector<vector<int>> B = { {1, 2, 20},{2, 3, 17} };
  solve(A, B);
  return 0;
}