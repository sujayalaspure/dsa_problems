#include <iostream>
#include <vector>
using namespace std;


void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid, int row, int col) {
  // int row = grid.size();
  // int col = grid[0].size();
  if (i <= -1 || j <= -1 || i >= row || j >= col) return;
  if (grid[i][j] == '0' || vis[i][j]) return;

  // vis[i][j] = true;
  grid[i][j] = '0';
  dfs(i - 1, j, vis, grid, row, col);
  dfs(i, j - 1, vis, grid, row, col);
  dfs(i + 1, j, vis, grid, row, col);
  dfs(i, j + 1, vis, grid, row, col);
}

int numIslands(vector<vector<char>>& grid) {
  int row = grid.size();
  int col = grid[0].size();
  int cnt = 0;

  vector<vector<int>> vis(row + 1, vector<int>(col + 1, false));

  for (int i = 0;i < row;i++) {
    for (int j = 0;j < col;j++) {
      if (grid[i][j] == '1') {
        cout << i << " " << i << endl;
        dfs(i, j, vis, grid, row, col);
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  vector<vector<char>> grid = {
      {'1','1','0','0','0'} ,
      {'1','1','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','1','1'}
  };

  cout << numIslands(grid) << endl;

  return 0;
}