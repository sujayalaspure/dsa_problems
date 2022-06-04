#include <iostream>
#include <vector>
using namespace std;


int comp(int n, vector<int>& c) {
  if (c[n] == n) return c[n];
  c[n] = comp(c[n], c);
  return c[n];
}
vector<int> solve(int A, vector<vector<int> >& B) {
  vector<int>c(A + 1);
  for (int i = 1;i <= A;i++) {
    c[i] = i;
  }
  if (B.size() == 1) return { 1 };
  vector<int> res(B.size(), 0);
  for (int i = 0;i < B.size();i++) {
    int u = B[i][0];
    int v = B[i][1];
    int w = B[i][2];
    int idx = B[i][3];
    int pu = comp(u, c);
    int pv = comp(v, c);
    cout << pu << " " << pv << endl;
    if (pu != pv) {
      res[idx] = 1;
      c[max(pu, pv)] = min(pu, pv);
    }
  }
  return res;
}

int main() {

  int A = 7;
  vector<vector<int>>B = { {1, 2, 468},{2, 3, 335},{3, 1, 501},{2, 4, 170},{2, 5, 725},{2, 7, 479},{4, 6, 359},{5, 6, 963} };

  for (int i = 0; i < B.size(); i++) {
    B[i].push_back(i);
  }

  // for (int i = 0; i < B.size(); i++) {
  //   for (int j = 0; j < 4; j++) {
  //     cout << B[i][j] << " ";
  //   }
  //   cout << endl;
  // }


  vector<int> ans = solve(A, B);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}