#include <iostream>
#include <vector>
using namespace std;


int maximalRectangle(vector<vector<int> >& A) {

  int r = A.size();
  int c = A[0].size();

  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      if (j == 0) continue;
      if (A[i][j] == 1) {
        A[i][j] = 1 + A[i][j - 1];
      }
    }
  }

  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  int area = 0;
  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      if (A[i][j] != 0) {
        int w = A[i][j];
        int h = 0;
        for (int k = i;k >= 0;k--) {
          w = min(w, A[k][j]);
          ++h;
          area = max(area, w * h);
          cout << w << " " << h << " " << area << endl;
        }
      }
    }
  }
  cout << "-> " << area << endl;
  return area;
}



int main() {

  vector<vector<int>> A{ {1, 0}, {0, 1} };

  maximalRectangle(A);
  return 0;
}