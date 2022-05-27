#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A = 10;
  int B = 48;
  vector<int> C = { 4, 0, 30, 0, 41, 28, 50, 2, 47, 39 };


  for (int i = 0;i < A;i++) {
    if (C[i] == 0) {
      if (i == 1) {
        C[i] = B;
      }
      else {
        C[i] = C[i - 2];
      }

    }
  }

  cout << C[A - 1] << endl;

  return 0;
}