#include <iostream>
#include <vector>
using namespace std;
vector<vector<string> > ans;

void nqueens(vector<vector<char> >& mat, int n, int r, vector<bool>& cols, vector<bool>& left, vector<bool>& right) {
  if (r == n) {
    // print
    vector<string> temp;
    for (vector<char> i : mat) {
      string s(i.begin(), i.end());
      temp.push_back(s);
    }
    ans.push_back(temp);

    return;
  }

  for (int c = 0; c < n; c++) {
    if (cols[c] == false && left[r - c + n - 1] == false && right[r + c] == false) {
      mat[r][c] = 'Q';
      cols[c] = true;
      left[r - c + n - 1] = true;
      right[r + c] = true;
      nqueens(mat, n, r + 1, cols, left, right);
      mat[r][c] = '.';
      cols[c] = false;
      left[r - c + n - 1] = false;
      right[r + c] = false;
    }
  }
}

int main() {
  int n = 4;
  // vector<bool> cols(n);
  // vector<bool> left(n);
  // vector<bool> right(n);
  // vector<vector<string> > ans = {};

  vector<bool> cols(n);
  vector<bool> left(n);
  vector<bool> right(n);
  vector<vector<char> > mat(n, vector<char>(n, '.'));

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     mat[i][j] = '.';
  //   }
  //   cout << endl;
  // }
  nqueens(mat, n, 0, cols, left, right);
  for (auto a : ans) {
    for (string i : a) {
      cout << i << endl;
    }
    cout << "--------" << endl;
  }

  return 0;
}

