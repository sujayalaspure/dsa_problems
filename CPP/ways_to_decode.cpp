#include <iostream>
#include <vector>
using namespace std;
int numDecodings(string A) {
  int n = A.size();
  vector<int> dp(n + 1, 0);
  dp[0] = 1;

  // dp[1] = A[0] == '0' ? 0 : 1;
  if (n == 1 && A[0] == '0') return 0;

  for (int i = 1; i <= n; i++) {
    char curr = A[i - 1];
    char prev = A[i - 2];
    if (i == 1 && curr == '0') dp[i] = 0;
    else if (i == 1) dp[i] = 1;
    else {
      dp[i] = curr == '0' ? 0 : dp[i - 1];
      if (prev == '1' || (prev == '2' && curr <= '6')) dp[i] += dp[i - 2];
    }
  }
  // cout << dp[n - 1] << endl;
  return dp[n];
}

int main() {
  // string A = "875361268549483279131";
  string A = "4612";
  cout << numDecodings(A) << endl;
  return 0;
}