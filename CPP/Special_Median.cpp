#include <iostream>
#include <vector>
using namespace std;


int solve(vector<int>& A) {
  int n = A.size();
  int pre[n];
  int suf[n];
  pre[0] = 0;
  suf[n - 1] = 0;
  cout << pre[0] << " ";
  for (int i = 1;i < n;i++) {
    pre[i] = pre[i - 1] + A[i - 1];
    cout << pre[i] << " ";
  }
  cout << endl;
  cout << suf[n - 1] << " ";
  for (int i = n - 2;i >= 0;i--) {
    suf[i] = suf[i + 1] + A[i + 1];
    cout << suf[i] << " ";
  }
  cout << endl;

  for (int i = 1;i < n;i++) {
    if (A[i] == pre[i] / 2 || A[i] == suf[i] / 2) return 1;
  }
  return 0;

}

int main() {

  vector<int> A = { 4, 6, 8, 4 };

  // pre -> 0 4 10 18
  // suf -> 18 12 4 0


  cout << solve(A) << endl;
  return 0;
}