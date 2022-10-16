// https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
  int row = grid.size();
  int col = grid[0].size();
  queue<pair<int, int>> q;
  vector<vector<int>> ans(row, vector<int>(col, -1));
  int val = 0;
  q.push(source);
  ans[source.first][source.second] = val;

  while (!q.empty()) {
    val++;
    int sz = q.size();
    for (int i = 0;i < sz;i++) {
      pair<int, int> curr = q.front();
      q.pop();


      for (int j = 0; j < 4; j++) {
        int ni = curr.first + dx[j];
        int nj = curr.second + dy[j];
        if (ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] && ans[ni][nj] == -1) {
          ans[ni][nj] = val;
          q.push({ ni, nj });
        }
      }

    }
  }
  return ans[destination.first][destination.second];
}

int main() {

  vector<vector<int>> grid = { {1, 1, 1, 1},
              {1, 1, 0, 1},
              {1, 1, 1, 1},
              {1, 1, 0, 0},
              {1, 0, 0, 1} };
  pair<int, int> source = { 0, 1 };
  pair<int, int> destination = { 2, 2 };

  int he = shortestPath(grid, source, destination);
  cout << he << endl;

  return 0;
}