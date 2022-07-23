#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
string ans = "NO";

void computeMatrix(vector<vector<int>>& g, vector<int>& A, vector<int>& B, int R, int xIdx, int yIdx) {
  // for (int i = 0; i < A.size(); i++) {
  //   int r = R + 1;
  //   int x = A[i], y = B[i];
  //   while (r) {
  //     g[x][y] = 0;
  //     if (x > 0)g[x - 1][y] = 0;
  //     if (y > 0)g[x][y - 1] = 0;
  //     if (x < g.size() - 1)g[x + 1][y] = 0;
  //     if (y < g[0].size() - 1)g[x][y + 1] = 0;
  //     r--;
  //   }
  // }

  for (int i = 0; i <= xIdx; i++) {
    for (int j = 0; j <= yIdx; j++) {
      int res = 1;
      for (int k = 0; k < A.size(); k++) {
        int distance = (int)(pow((i - A[k]), 2) + pow((j - B[k]), 2));
        if (distance <= (R * R)) {
          res = 0;
          break;
        }
      }
      g[i][j] = res;
    }
  }




}


bool isValid(int row, int col, vector<vector<int>>& g) {
  if (row < 0 || col < 0 || row >= g.size() || col >= g[0].size() || g[row][col] == 0) return false;
  return true;
}

void dfs(int row, int col, vector<vector<int>>& g) {
  if (!isValid(row, col, g)) return;
  if (row == g.size() - 1 && col == g[0].size() - 1) {
    ans = "YES";
    return;
  }
  g[row][col] = 0;
  // for (int i = 0;i < 8;i++) {
  //   int newX = row + dx[i];
  //   int newY = col + dy[i];
  //   dfs(newX, newY, g);
  // }

  dfs(row + 1, col, g);
  dfs(row, col + 1, g);
  dfs(row + 1, col + 1, g);
  dfs(row - 1, col - 1, g);
  dfs(row - 1, col + 1, g);
  dfs(row + 1, col - 1, g);
  dfs(row - 1, col, g);
  dfs(row, col - 1, g);
}


string solve() {
  ans = "NO";
  int x = 7, y = 91;
  int N = 8, R = 7;
  vector<int> A = { 1, 7, 1, 7, 1, 5, 1, 6 };
  vector<int> B = { 25, 4, 74, 14, 90, 58, 37, 4 };

  vector<vector<int>> g(x + 1, vector<int>(y + 1, 1));



  computeMatrix(g, A, B, R, x, y);
  if (g[0][0] == 0 || g[x][y] == 0) return "NO";
  dfs(0, 0, g);
  return ans;


  // for (int i = 0; i < x + 1; i++) {
  //   for (int j = 0; j < y + 1; j++) {
  //     cout << g[i][j] << " ";
  //   }
  //   cout << endl;
  // }

}


int main() {

  cout << solve() << endl;


  return 0;
}