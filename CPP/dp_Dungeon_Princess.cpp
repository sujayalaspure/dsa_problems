#include <iostream>
#include <vector>
using namespace std;
int calculateMinimumHP(vector<vector<int> >& A) {
  int row = A.size();
  int col = A[0].size();
  int dp[row][col];

  for (int i = row - 1;i >= 0;i--) {
    for (int j = col - 1;j >= 0;j--) {
      if (i == row - 1 && j == col - 1) {
        dp[i][j] = max(1 - A[i][j], 1);
      }
      else if (i == row - 1 && j != col - 1) {
        dp[i][j] = max(dp[i][j + 1] - A[i][j], 1);
      }
      else if (i != row - 1 && j == col - 1) {
        dp[i][j] = max(dp[i + 1][j] - A[i][j], 1);
      }
      else {
        dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - A[i][j], 1);
      }
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }


  return dp[0][0];

}



int main() {

  vector<vector<int>> A = {
      {-2, -3, 3},
      {-5, -10, 1},
      {10, 30, -5} };

  cout << calculateMinimumHP(A) << endl;

  return 0;
}