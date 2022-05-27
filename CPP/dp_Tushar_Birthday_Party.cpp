#include <iostream>
#include <vector>
using namespace std;


int knapSack(vector<int>& B, vector<int>& C, int val, vector<int>& dp) {
  if (val == 0) return 0;
  if (dp[val] != -1) return dp[val];
  int ans = INT_MAX;
  for (int i = 0;i < B.size();i++) {
    if (val >= B[i]) {
      int temp = C[i] + knapSack(B, C, val - B[i], dp);
      ans = min(ans, temp);
    }
  }
  dp[val] = ans;
  return ans;
}

int main() {
  vector<int> A = { 2, 3, 1, 5, 4 };
  vector<int> B = { 3, 2, 4, 1 };
  vector<int> C = { 1, 2, 5, 10 };

  int n = A.size();
  int maxVal = INT_MIN;
  for (int i : A) {
    maxVal = max(maxVal, i);
  }
  cout << maxVal << endl;

  vector<int> dp(maxVal + 1, -1);
  knapSack(B, C, maxVal, dp);

  int ans = 0;
  for (int a : A) {
    ans += dp[a];
  }

  cout << ans << endl;

  return 0;
}