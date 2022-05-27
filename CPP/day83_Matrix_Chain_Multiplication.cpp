#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<vector<int>>& dp, vector<int>& A, int i, int j) {
  if (i == j) return 0;
  if (dp[i][j] == -1) {
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
      int l = minCost(dp, A, i, k);
      int r = minCost(dp, A, k + 1, j);
      int c = A[i - 1] * A[k] * A[j];
      ans = min(l + r + c, ans);
    }
    dp[i][j] = ans;

  }

  return dp[i][j];
}

int main() {
  vector<int> A = { 40, 20, 30, 10, 30 };
  int n = A.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  int a = minCost(dp, A, 1, n - 1);
  cout << dp[1][n] << endl;
  cout << a << endl;


  return 0;
}