#include <iostream>
#include <vector>
using namespace std;

int findLargestSquare(vector<vector<int>> const& mat) {
  // base case
  if (mat.size() == 0) {
    return 0;
  }

  // `M × N` matrix
  int M = mat.size();
  int N = mat[0].size();

  // `lookup[i][j]` stores the size of maximum square
  // submatrix ending at mat[i][j]
  int lookup[M][N];

  // `max` stores the size of the largest square submatrix of 1's
  int max = 0;

  // fill in a bottom-up manner
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      lookup[i][j] = mat[i][j];

      // if we are not at the first row or first column and the
      // current cell has value 1
      if (i && j && mat[i][j]) {
        // largest square submatrix ending at `mat[i][j]` will be
        // 1 plus minimum of largest square submatrix ending at
        // mat[i][j-1], mat[i-1][j] and mat[i-1][j-1]

        lookup[i][j] = (lookup[i][j - 1] * lookup[i - 1][j]) + 1;
      }

      // update maximum size found so far
      if (max < lookup[i][j]) {
        max = lookup[i][j];
      }
    }
  }

  // print lookup matrix
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << lookup[i][j] << " ";
    }
    cout << endl;
  }


  // return size of the largest square matrix
  return max;
}

int main() {
  // input matrix
  vector<vector<int>> mat =
  {
      { 0, 0, 1, 0, 1, 1 },
      { 0, 1, 1, 1, 0, 0 },
      { 0, 0, 1, 1, 1, 1 },
      { 1, 1, 0, 1, 1, 1 },
      { 1, 1, 1, 1, 1, 1 },
      { 1, 1, 0, 1, 1, 1 },
      { 1, 0, 1, 1, 1, 1 },
      { 1, 1, 1, 0, 1, 1 }
  };

  cout << "The size of the largest square submatrix of 1's is " <<
    findLargestSquare(mat) << endl;

  return 0;
}