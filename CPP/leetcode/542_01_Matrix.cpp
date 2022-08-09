// https://leetcode.com/problems/01-matrix/

#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

  int row = mat.size();
  int col = mat[0].size();
  vector<vector<int>> dist(row, vector<int>(col, INT_MAX - 100000));

  for (int i = 0;i < row;i++) {
    for (int j = 0;j < col;j++) {
      if (mat[i][j] == 0) dist[i][j] = 0;
      else {
        if (i > 0) dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
        if (j > 0) dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
      }
    }
  }
  for (int i = row - 1;i >= 0;i--) {
    for (int j = col - 1;j >= 0;j--) {
      if (i < row - 1) dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
      if (j < col - 1) dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
    }
  }


  for (int i = 0;i < row;i++) {
    for (int j = 0;j < col;j++) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }

  return dist;
}

int main() {

  // vector<vector<int>> mat = { {1, 1, 1}, {1, 1, 0}, {1,0,0} };
  vector<vector<int>> bigmat = {
    {1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
    {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
    {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {1, 1, 1, 1, 0, 1, 0, 0, 1, 1} };
  updateMatrix(bigmat);

  return 0;
}