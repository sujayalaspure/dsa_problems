#include <iostream>
#include <vector>
using namespace std;


static bool comp(vector<int>& a, vector<int>& b) {
  return a[1] < b[1];
}
int main() {
  int start = 0, end = 1, costIdx = 2;
  vector<int> A = { 1, 2, 3, 4, 6 };
  vector<int> B = { 3, 5, 10, 6, 9 };
  vector<int> C = { 20, 20, 100, 70, 60 };
  int n = A.size();
  vector<vector<int>> v;
  for (int i = 0;i < A.size();i++) {
    v.push_back({ A[i], B[i], C[i] });
  }

  sort(v.begin(), v.end(), comp);

  int dp[n];
  memset(dp, 0, sizeof(dp));

  dp[0] = v[0][2];
  for (int i = 1;i < n;i++) {
    int prev = i - 1;

    while (prev >= 0 && v[prev][end] > v[i][start]) prev--;
    int cost = 0;
    if (prev >= 0 && v[prev][end] <= v[i][start]) { cost = dp[prev]; }
    dp[i] = max(dp[i - 1], cost + v[i][costIdx]);

    cout << i << " " << prev << " " << dp[i] << endl;
  }

  cout << dp[n - 1] << endl;

  return 0;
}