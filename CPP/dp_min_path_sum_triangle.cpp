
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> A = {
      {2} ,
    {5, 4},
   {6, 5, 7},
  {4, 1, 8, 3}
  };

  for (int i = A.size() - 2; i >= 0; i--) {
    for (int j = 0; j < A[i].size(); j++) {
      A[i][j] = min(A[i + 1][j], A[i + 1][j + 1]) + A[i][j];
    }
  }

  cout << A[0][0] << endl;





  return 0;
}