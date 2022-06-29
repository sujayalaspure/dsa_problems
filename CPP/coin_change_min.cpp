#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();
  vector<vector<int>> dp(n + 1, vector<int >(amount + 1, INT_MAX - 1));
  // memset(dp, INT_MAX-1, sizeof(dp));
  for (int i = 1;i <= n;i++) {
    dp[i][0] = 0;
  }
  // special base case;
  for (int i = 1;i <= amount;i++) {
    int t = i % coins[0];
    cout << t << " ";
    if (i % coins[0] == 0) {
      dp[1][i] = (int)(i / coins[0]);
      cout << "i=" << i << " " << dp[1][i] << " - ";
    }
  }

  for (int i = 2;i <= n;i++) {
    int tmep = coins[i - 1];
    // cout << "temp=" << " " << tmep << endl;
    for (int j = 1;j <= amount;j++) {
      if (j >= coins[i - 1]) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  if (dp[n][amount] >= INT_MAX - 1) return -1;
  return (int)dp[n][amount];
}

int main() {

  vector<int> coins = { 1, 2, 5 };
  int amount = 11;
  cout << coinChange(coins, amount) << endl;

  return 0;
}