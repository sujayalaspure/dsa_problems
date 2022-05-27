#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A = 2;
  vector<int> dp(A + 1, 0);
  dp[0] = 1;
  if (A == 1) return 1;
  for (int i = 1;i < A + 1;i++) {
    int s = 0;
    for (int j = 1;j <= 6;j++) {
      if (i >= j) s += dp[i - j];
    }
    dp[i] = s;
  }
  cout << dp[A] << endl;
  return 0;
}