#include <iostream>
#include <vector>
using namespace std;


bool isvalidbox(vector<vector<char> >& A, int r, int c, int k) {
  int startrow = r - r % 3;
  int startcol = c - c % 3;
  for (int i = startrow; i < startrow + 3;i++) {
    for (int j = startcol;j < startcol + 3;j++)

    {
      if (A[i][j] - '0' == k) {
        return false;
      }
    }
  }
  return true;

}

bool isvalidcol(vector<vector<char> >& A, int row, int col, int k) {
  for (int i = 0; i < 9;i++) {
    if (A[row][i] - '0' == k) {
      return false;
    }
  }
  return true;
}

bool isvalidrow(vector<vector<char> >& A, int row, int col, int k) {
  for (int i = 0; i < 9;i++) {
    if (A[i][col] - '0' == k) {
      return false;
    }
  }
  return true;
}

bool fillsudoku(vector<vector<char> >& A, int i) {
  //base case
  if (i == 81) {
    return true;
  }
  int r = i / 9;
  int c = i % 9;

  if (A[r][c] != '.') {
    return fillsudoku(A, i + 1);
  }

  for (int k = 1; k <= 9;k++) {
    if (isvalidcol(A, r, c, k) && isvalidrow(A, r, c, k) && isvalidbox(A, r, c, k)) {
      auto val = to_string(k).data();

      A[r][c] = val[0];

      if (fillsudoku(A, i + 1)) {
        return true;
      }
      A[r][c] = '.';
    }

  }
  return false;
}




bool check(vector<vector<char> >& A, int r, int c, int k) {
  for (int i = 0; i < 9; i++) if (A[i][c] - '0' == k) return false;
  for (int i = 0; i < 9; i++) if (A[r][i] - '0' == k) return false;
  int startrow = r - r % 3;
  int startcol = c - c % 3;
  for (int i = startrow; i < startrow + 3; i++) {
    for (int j = startcol; j < startcol + 3; j++) {
      if (A[i][j] - '0' == k) return false;
    }
  }
  return true;
}

bool sudoku(vector<vector<char> >& A, int i) {
  if (i == 81) {
    //print A
    cout << "DON";
    return true;
  }
  int r = i / 9, c = i % 9;
  if (A[r][c] != '.') return sudoku(A, i + 1);
  for (int k = 1;k <= 9;k++) {
    // char ele = k;
    if (check(A, r, c, k)) {
      auto val = to_string(k).data();

      A[r][c] = val[0];
      if (sudoku(A, i + 1)) return true;
      A[r][c] = '.';
    }
  }
  return false;

}

int main() {

  vector<vector<char>> A = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'} };

  sudoku(A, 0);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }



  return 0;
}