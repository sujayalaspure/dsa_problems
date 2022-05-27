// DP
#include <iostream>
#include <vector>
using namespace std;

// each element can be taken at most once
int findWayONlyOne(vector<int>& A, int B) {
  int n = A.size();
  vector<vector<int>> dp(n + 1, vector<int>(B + 1, 0));
  for (int j = 0;j <= B;j++) {
    dp[0][j] = 0;
  }
  for (int j = 0;j <= n;j++) {
    dp[j][0] = 1;
  }


  for (int i = 1;i <= n;i++) {
    // dp[i % 2][0] = 1;
    for (int j = 1;j <= B;j++) {
      dp[i][j] = dp[(i - 1)][j];
      if (j >= A[i - 1])
        dp[i][j] += dp[(i - 1)][j - A[i - 1]];
    }
  }
  return dp[n][B];
}

// assuming you have infinite amount of each coin in the set.
int findWayWithInfinite(vector<int>& A, int B) {
  int mod = (int)(10e6 + 7);
  int n = A.size();
  vector<vector<long>> dp(n + 1, vector<long>(B + 1));
  for (int j = 0;j <= n;j++) {
    dp[j][0] = 1;
  }
  for (int j = 0;j <= B;j++) {
    dp[0][j] = 0;
  }


  for (int i = 1;i <= n;i++) {
    // dp[i % 2][0] = 1;
    for (int j = 1;j <= B;j++) {
      dp[i][j] = dp[i - 1][j] % mod;
      if (j - A[i - 1] >= 0)
        dp[i][j] += (dp[i][j - A[i - 1]] + 1) % mod;
      // dp[i][j] = dp[i][j] % mod;
    }
  }
  return dp[n][B] % mod;
}


int main() {
  vector<int>  A = { 18, 24, 23, 10, 16, 19, 2, 9, 5, 12, 17, 3, 28, 29, 4, 13, 15, 8 };
  int B = 458;
  // vector<int>  A = { 7,4,9,6,11,5,13,8 };
  // int B = 22;


  cout << findWayWithInfinite(A, B) << endl;
  return 0;
}