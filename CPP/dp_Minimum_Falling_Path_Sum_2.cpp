#include <iostream>
#include <vector>
using namespace std;

void recursiveSolve(vector<vector<int>>& A, int r, int c, int curr, int& minSum) {
  if (r == A.size()) {
    minSum = min(minSum, curr);
    return;
  }
  curr += A[r][c];
  for (int i = 0;i < A[0].size();i++) {
    if (i == c) continue;
    recursiveSolve(A, r + 1, i, curr, minSum);
  }
}

// Memorization
int memorizationSolve(vector<vector<int>>& A, int r, int c, vector<vector<int>>& dp) {

  if (r == A.size() - 1) {
    dp[r][c] = A[r][c];
    return dp[r][c];
  }
  if (dp[r][c] != INT_MAX) return dp[r][c];

  for (int i = 0;i < A[r].size();i++) {
    if (i == 0) {
      dp[r][c] = INT_MAX;
    }
    if (i != c) {
      dp[r][c] = min(dp[r][c], memorizationSolve(A, r + 1, i, dp) + A[r][c]);
    }
  }
  return dp[r][c];
}

int main() {


  vector<vector<int>> A = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
  // vector<vector<int>> A = { {17, 14,19} ,{12, 18, 9},{20, 10, 1} };
  int minSum = INT_MAX;

  // Recursive approach Bruete Force
  // int m = A[0].size();
  // for (int i = 0;i < m;i++) {
  //   recursiveSolve(A, 0, i, 0, minSum);
  // }
  // cout << minSum << endl;


// Recursion + Memorization
  int n = A.size();
  int m = A[0].size();
  vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
  for (int i = 0;i < m;i++) {
    memorizationSolve(A, 0, i, dp);
  }
  for (int i = 0;i < n;i++) {
    minSum = min(minSum, dp[0][i]);
  }
  cout << minSum << endl;



  return 0;
}