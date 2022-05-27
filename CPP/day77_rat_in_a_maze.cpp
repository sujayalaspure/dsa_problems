#include <iostream>
#include <vector>
using namespace std;


bool move(vector<vector<int> >& A, int i, int j, int n, vector<vector<int> >& ans) {
  if (i >= n || j >= n) return false;
  // cout << i << " " << j << " " << A[i][j] << " " << ans[i][j] << endl;
  if (i == n - 1 && j == n - 1) {
    ans[i][j] = A[i][j];
    // cout << "   " << endl;
    // for (int x = 0; x < n; x++) {
    //   for (int y = 0; y < n; y++) {
    //     cout << ans[x][y] << " ";
    //   }
    //   cout << endl;
    // }
    return true;
  }
  if (A[i][j] == 0) return false;
  if (A[i][j] == 1) {
    ans[i][j] = 1;
    if (move(A, i + 1, j, n, ans)) return true;
    if (move(A, i, j + 1, n, ans)) return true;
    ans[i][j] = 0;
  }
  return false;
}

vector<vector<int> > solve(vector<vector<int> >& A) {
  int n = A.size();
  vector<vector<int>> ans(n, vector<int>(n, 0));
  move(A, 0, 0, n, ans);
  cout << "---" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return ans;

}

int main() {
  vector<vector<int> > A = { {1, 1, 1}, {1, 0, 1},{1,1, 1} };
  solve(A);

  return 0;
}